#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

// TODO write has on : sep val directly?

int main (int argc, char** argv) {
  if (argc < 3) {
    // Should this be cerr?
    cout << "You must supply two file names: ./pgm file1 file2" << endl;
    return 0;
  }


  // TODO construct on heap
  unordered_set<size_t> genes;

  ifstream file (argv[1]);

  if (!file.is_open()) {
    // Should this be cerr?
    cout << "Unable to open file " << argv[0] << endl;
    return 0;
  }

  string line, token, clean;

  while (getline(file, line)) {
    cout << "Line:   " << line << endl;

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

    // DEBUG
    cout << "After:  " << clean << endl;

    // add to set
    genes.insert(clean);

    // advance stream to next line

  }

  // close file1
  file.close();

  // open  file2
  file.open(argv[2]);

  for (int line = 0; line < 10 ; line++) {
    // read line
    // concat
    // check in set
  }
}
