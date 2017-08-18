#include "IOManager.h"

#include <iomanip>
#include <sstream>
#include <ctime>
#include <fstream>
#include <exception>
#include <cctype>

IOManager::IOManager(std::string _inputFile, std::string _outputFile) {
  // this->plaintext_ to be filled in
  std::ifstream fin;
  std::stringstream ss;
  fin.open(_inputFile.c_str());
  if (fin.fail()) throw std::invalid_argument("Bad input file name.");
  char next;
  while (!fin.eof()) {
    fin.get(next);
    if (!isalpha(next)) continue;
    if (isupper(next)) next = tolower(next);
    ss << next;
  }
  fin.close();
  this->plaintext_ = ss.str();
}
