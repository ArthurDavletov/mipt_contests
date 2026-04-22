#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  int x = a - b;
  std::cout << (a + b + x * (x % 2 + (x + 1) % 2)) / 2 << std::endl;
  return 0;
}
