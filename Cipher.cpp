#include "Cipher.h"

#include <vector>
#include <algorithm>

Cipher::Cipher() {
  key_.reserve(this->NCARDS);
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
     4. Perform the Count Cut: get bottom card (54th card). That gives an index.
        Now search for the card in that position (1-indexed, adjust to 0-indexing when programming) in deck.
        Now all cards up to and including that card, treat it as a slice.
        All cards that are not in that slice, but not including the bottom card (which provided the index!)
        is another slice.
	Swap the two slices.
     5. Find the output card's number. Look at the top card, get its value and use it as an index.
        Using 1-indexing, find the card which the index points to. That card's value is the output!
	If that card is a JOKER, do nothing and start all over again from step 1.
   */
  int count = 0;
  while (count < _n) {
    
  }
}
