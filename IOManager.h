#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <string>

class IOManager {
 public:
  std::string plaintext_;
  std::string encrypted_;
  IOManager(std::string _inputFile, std::string _outputFile);
};

#endif
