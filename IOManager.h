#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <string>

class IOManager {
 public:
  std::string plaintext_;
  std::string outputFile_;
  IOManager(std::string _inputFile, std::string _outputFile);
  void writeCipherText(std::string _encrypted);
};

#endif
