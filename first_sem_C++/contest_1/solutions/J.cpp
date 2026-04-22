#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::cout << 1 + (n % m) * (m % n) << std::endl;
  return 0;
}
