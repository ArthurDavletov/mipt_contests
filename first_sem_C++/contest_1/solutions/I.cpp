#include <iostream>

int main() {
  int h, a, b;
  std::cin >> h >> a >> b;
  std::cout << (h - b * 2 + a - 1) / (a - b);
  return 0;
}