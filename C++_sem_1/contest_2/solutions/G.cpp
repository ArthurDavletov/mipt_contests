#include <iostream>

int main() {
  int first = 0, second = 0, temp;
  std::cin >> temp;
  while (temp != 0) {
    if (temp > first) {
      second = first;
      first = temp;
    } else if (temp > second) {
      second = temp;
    }
    std::cin >> temp;
  }
  std::cout << second << std::endl;
}
