// defines execute_commands for reading commands for Pokedex

#include "pokedex.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

void execute_commands(const string &filename) {
  ifstream ifs(filename);
  if (!ifs.good()) {
    cout << "Failed to open " << filename << endl;
    return;
  }
  Pokedex pdx;
  while (ifs.good()) {
    string command;
    ifs >> command;
    // single word commands
    if (command == "size") {
      cout << "Executing: " << command << endl;
      cout << pdx.size() << endl;
    } else if (command == "max_size") {
      cout << "Executing: " << command << endl;
      cout << Pokedex::max_size() << endl;
    } else if (command == "empty") {
      cout << "Executing: " << command << endl;
      cout << (pdx.empty() ? "true" : "false") << endl;
    } else if (command == "front") {
      cout << "Executing: " << command << endl;
      cout << pdx.front() << endl;
    } else if (command == "back") {
      cout << "Executing: " << command << endl;
      cout << pdx.back() << endl;
    } else if (command == "pop_back") {
      // no output
      cout << "Executing: " << command << endl;
      pdx.pop_back();
    } else if (command == "print") {
      // call insertion operator
      cout << "Executing: " << command << endl;
      cout << pdx << endl;
    } else if (command == "at") {
      int num;
      ifs >> num;
      cout << "Executing: " << command << " " << num << endl;
      cout << pdx.at(num) << endl;
    } else if (command == "insert") {
      // no output
      string book;
      // skip the space after num
      ifs.ignore();
      // read the whole line, not just up to the first space
      getline(ifs, book);
      cout << "Executing: " << command << " " << book << endl;
      pdx.insert(book);
    } else if (command == "erase") {
      // no output
      int num;
      ifs >> num;
      cout << "Executing: " << command << " " << num << endl;
      pdx.erase(num);
    } else {
      cout << "Invalid command: " << command << endl;
    }
  }
  ifs.close();
}
