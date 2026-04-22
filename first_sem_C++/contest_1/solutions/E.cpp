#include <iostream>

int main() {
  int x;
  std::cin >> x;
  std::cout << x / 100 + x / 10 % 10 + x % 10 << std::endl;
  return 0;
}