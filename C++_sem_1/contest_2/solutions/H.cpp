#include <iostream>

int main() {
  int32_t s = 0, n;
  std::cin >> n;
  while (n > 0) {
    s += n % 10;
    n /= 10;
  }
  std::cout << s << std::endl;
}
