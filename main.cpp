#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

// TODO write has on : sep val directly?

string parse(string token) {
}

int main (int argc, char** argv) {
  if (argc < 3) {
    // Should this be cerr?
    cout << "You must supply two file names: ./pgm file1 file2" << endl;
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
      // Should this be cerr?
      cout << "Unable to open file " << argv[fileNo] << endl;
      continue;
    }

    while (getline(file, line)) {
      cout << "Line:   " << line << endl;

      // TODO better name
      istringstream iss(line);

      if (!(iss >> token)) {
        cout << "Could not process token in line: " << line;
        continue;
      }

      // DEBUG
      cout << "Before: " << token << endl;

      // concat
      // TODO make delim param
      size_t end = token.find('#');
      // TODO make prefix param
      clean = token.substr(14, end - 14);

      // DEBUG
      cout << "During: " << clean << endl;

      size_t pos = -1;
      while ((pos = clean.find(':')) != string::npos) {
        clean.erase(pos, 1);
      }

      // TODO better name
      istringstream iss2(clean);
      //clean >> value;
      value = stoull(clean);
      // TODO error handling

      // DEBUG
      cout << "After:  " << value << endl;

      // add to set
      if (fileNo == 1) {
        genes.insert(value);
      }
      else /* fileNo > 1 */ {
        if (genes.count(value) >= 1) {
	  cout << value << endl;
	}
      }
    }

    // close file
    file.close();
  }

  return 0;
}
