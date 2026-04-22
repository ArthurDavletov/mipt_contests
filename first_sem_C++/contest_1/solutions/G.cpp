#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::cout << n / 3600 % 24 << ':';
  std::cout << n % 3600 / 60 / 10 << n % 3600 / 60 % 10 << ':';
  std::cout << n % 60 / 10 << n % 60 % 10 << std::endl;
  return 0;
}
