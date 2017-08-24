#include <vector>
#include <algorithm>
#include <iostream>

int main() {
  std::vector<int> vec(10);
  int count = 1;
  for (auto i = vec.begin(); i != vec.end(); ++i) {
    *i = count++;
  }
  std::rotate(vec.begin(), vec.begin() + 9, vec.end());
  for (auto i = vec.begin(); i != vec.end(); ++i) {
    std::cout << *i << " ";
  }
}
