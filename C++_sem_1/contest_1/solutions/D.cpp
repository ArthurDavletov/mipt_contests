#include <iostream>

int main() {
  int v, t;
  std::cin >> v >> t;
  std::cout << ((v * t) % 109 + 109) % 109 << std::endl;
  return 0;
}