#include "IOManager.h"
#include "Cipher.h"

#include <cassert>
#include <iostream>
#include <algorithm>

int main(int argc, char** argv) {
  // argc must be 3
  // argv must be 2 strings passed to the program
  // Launch this with ./Encrypt inputFile.txt outputFile.txt
  try {
    if (argc != 3) throw std::invalid_argument("Bad arguments: try ./Encrypt inFile.txt outFile.txt");
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::cout << "Your input file is " << inputFile << "\n"
	      << "Your output file is " << outputFile << "\n";
    std::cout << "Constructing the IOManager.\n";
    IOManager io(inputFile, outputFile);
    std::cout << "The plaintext is: " << io.plaintext_ << "\n";
    assert(io.plaintext_ == "plaintext");
    // std::cout << "Passed test of parsing the plaintext file.\n";
    std::cout << "Constructing the Cipher.\n";
    Cipher cipher;
    std::cout << "Generating the key.\n";
    std::vector<int> key = cipher.generateKey();
    std::cout << "The initialized key is: ";
    std::for_each(key.begin(), key.end(), [](int a){ std::cout << a << " "; });
    std::cout << "\n"
	      << "Performing encryption.\n";
    std::string encrypted = cipher.encrypt(io.plaintext_);
    std::cout << "The ciphertext is: " << encrypted << "\n";
    std::cout << "Performing decryption.\n";
    std::string decrypted = cipher.decrypt(encrypted);
    std::cout << "The decrypted ciphertext is: " << decrypted << "\n";
    assert(io.plaintext_ == decrypted);
    std::cout << "Writing ciphertext to the output file.\n";
    io.writeCipherText(encrypted);
    std::cout << "Good-bye!\n";
  } catch (std::exception &e) {
    std::cout << "Some exception occurred. Please debug.\n";
    std::cout << e.what();
  }
  return 0;
}
