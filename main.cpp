#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

// TODO write hash on : sep val directly?

int main (int argc, char** argv) {
  if (argc < 3) {
    cerr << "You must supply two file names: ./uneek file1 file2" << endl;
    return 0;
  }

  // TODO construct on heap
  unordered_set<size_t> genes;

  ifstream file;

  string line, token, clean;
  size_t value;

  for (int fileNo = 1; fileNo < argc; fileNo++) {
    file.open(argv[fileNo]);

    if (!file.is_open()) {
      cerr << "Unable to open file " << argv[fileNo] << endl;
      continue;
    }

    while (getline(file, line)) {
#ifdef DEBUG
      cerr << "Line:   " << line << endl;
#endif

      // TODO better name
      istringstream iss(line);

      // Skip head lines
      if (line[0] == '@') {
        continue;
      }

      // Grab read location
      if (!(iss >> token)) {
        cerr << "Could not process token in line: " << line;
        continue;
      }

#ifdef DEBUG
      cerr << "Before: " << token << endl;
#endif

      // concat
      // TODO make delim param
      size_t end = token.find('#');
      // TODO make prefix param
      clean = token.substr(14, end - 14);

#ifdef DEBUG
      cerr << "During: " << clean << endl;
#endif

      // Remove :'s
      size_t pos = -1;
      while ((pos = clean.find(':')) != string::npos) {
        clean.erase(pos, 1);
      }

      // Grab binary flag of read to distinguish start/end
      if (!(iss >> token)) {
        cerr << "Could not process token in line: " << line;
        continue;
      }

#ifdef DEBUG
      cerr << "Token:  " << token << endl;
#endif

      // TODO error handling
      value = stoull(clean + token);

#ifdef DEBUG
      cerr << "After:  " << value << endl;
#endif

      // add to set
      if (fileNo == 1) {
        genes.insert(value);
      }
      else /* fileNo > 1 */ {
        if (genes.count(value) < 1) {
	  cout << line << endl;
	}
      }
    }

    // close file
    file.close();
  }

  return 0;
}
