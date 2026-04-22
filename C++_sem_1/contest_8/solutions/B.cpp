#include <iostream>

int main() {
  int n;
  std::cin >> n;
  if (n % 3 == 0) {
    std::cout << 2 << std::endl;
  } else {
    std::cout << 1 << std::endl;
  }
  return 0;
}
