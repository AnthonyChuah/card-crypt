#include "IOManager.h"
#include <cassert>
#include <iostream>

int main(int argc, char** argv) {
  // argc must be 3
  // argv must be 2 strings passed to the program
  // Launch this with ./Encrypt inputFile.txt outputFile.txt
  if (argc != 3) throw std::invalid_argument("Bad arguments: try ./Encrypt inFile.txt outFile.txt");
  std::string inputFile = argv[1];
  std::string outputFile = argv[2];
  std::cout << "Your input file is " << inputFile << "\n"
	    << "Your output file is " << outputFile << "\n";
  IOManager io(inputFile, outputFile);
  assert(io.plaintext_ == "plaintext");
  // std::cout << "Passed test of parsing the plaintext file.\n";
  
  return 0;
}
