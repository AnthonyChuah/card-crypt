#ifndef CIPHER_H
#define CIPHER_H

#include <vector>
#include <utility>
#include <string>

class Cipher {
  static constexpr int NCARDS = 54;
  static constexpr int RADIX = 26;
  std::vector<int> initKey_;
  std::vector<int> key_;
  std::vector<int> keystream_;
  static std::vector<int> convertCharsToInts(std::string _chars);
  static std::string convertIntsToChars(std::vector<int> _ints);
  void swapCards(int _pos1, int _pos2);
  int findJokerA() const;
  int findJokerB() const;
  std::pair<int, int> findJokers() const;
  void tripleCut(int _endSlice1, int _startSlice2);
  void countCut(int _pos);
  int findOutput() const;
 public:
  Cipher();
  // generateKey should give a vector of length NCARDS (54). This is like shuffling the deck.
  std::vector<int> generateKey();
  // generateKeystream should use the generated key to provide a keystream
  std::vector<int> generateKeystream(int _n);
  // encrypt should use the generated keystream to encrypt the plaintext
  std::string encrypt(std::string _plaintext);
  // decrypt should use the generated keystream to decrypt the ciphertext
  std::string decrypt(std::string _ciphertext);
};

#endif
