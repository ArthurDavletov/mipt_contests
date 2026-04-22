#include <iostream>
#include <string>

int DigitCount(std::string word) {
  int counter = 0;
  for (uint32_t i = 0; i < word.length(); i++) {
    if (word[i] >= '0' && word[i] <= '9') {
      counter++;
    }
  }
  return counter;
}

int main() {
  std::string word;
  std::getline(std::cin, word);
  std::cout << DigitCount(word) << std::endl;
}
