#include "Cipher.h"

#include <vector>
#include <algorithm>

Cipher::Cipher() {
  key_.reserve(this->NCARDS);
  keystream_.reserve(this->NCARDS);
}

std::vector<int> Cipher::generateKey() {
  // Loop, or preferably use a range-based mutator to put integers 1 to 54 into the vector
  // Use std::shuffle (<algorithm>) to shuffle the vector
  std::shuffle(key_.begin(), key_.end());
  // Make a copy for initKey_ as well, because we want to keep the initial key even after
  // the encryption process
  this->initKey_ = key_;
}

std::vector<int> Cipher::generateKeystream(int _n) {
  /* Steps for generating a keystream:
     1. Find JOKER-A (53). Move it down the deck by one step (swap with the one below)
     2. Find JOKER-B (54). Move it down by two steps (swap with adjacent-below twice)
     Note: if "below" is the end of the deck, treat the deck as circular (wrap back to top)
     3. Perform the Triple Cut: swap all cards above higher JOKER with all cards below lower JOKER
     4. Perform the Count Cut: get bottom card (54th card). That gives an index. Either joker is 53, not 54.
        Now search for the card in that position (1-indexed, adjust to 0-indexing when programming) in deck.
        Now all cards up to and including that card, treat it as a slice.
        All cards that are not in that slice, but not including the bottom card (which provided the index!)
        is another slice.
	Swap the two slices.
     5. Find the output card's number. Look at the top card, get its value and use it as an index.
        Using 1-indexing, find the card which the index points to. That card's value is the output!
	If that card is a JOKER, do nothing and start all over again from step 1.
   */
  std::vector<int> output(_n);
  int count = 0; int pos; std::pair<int, int> jokers;
  while (count < _n) {
    pos = this->findJokerA();
    this->swapCards(pos, pos + 1);
    pos = this->findJokerB();
    this->swapCards(pos, pos + 1);
    this->swapCards(pos + 1, pos + 2);
    jokers = this->findJokers();
    this->tripleCut(jokers.first, joker.second);
    pos = key_[this->NCARDS - 1];
    this->countCut(pos); // Handle the pos == 54 exception inside helper method
    keystream_[count] = this->findOutput(); // Check if std::vector<int> output(_n) was initialized with len 54!
    if (keystream_[count] < 0) {
      continue;
    } else {
      ++count;
    }
  }
}

std::string Cipher::encrypt(std::string _plaintext) {
  std::vector<int> textInInts = Cipher::convertCharsToInts(_plaintext);
  int nChars = _plaintext.length();
  key_ = initKey_;
  generateKeystream(nChars);
  // Now add then mod 26
  std::vector<int> ctextInInts(nChars);
  // Translate back to text form by iterating over vector
}

std::string Cipher::decrypt(std::string _ciphertext) {
  std::vector<int> ctextInInts = Cipher::convertCharsToInts(_ciphertext);
  int nChars = _ciphertext.length();
  key_ = initKey_;
  generateKeystream(nChars);
  // Now subtract then mod 26. Remember negatives should wrap around
  std::vector<int> textInInts(nChars);
  // Translate back to text form by iterating over vector
}

// Private helper methods
