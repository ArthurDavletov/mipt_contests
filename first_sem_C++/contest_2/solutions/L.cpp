#include <iostream>

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (n - i > j + 1) {
        std::cout << 0 << ' ';
      } else if (n - i < j + 1) {
        std::cout << 2 << ' ';
      } else {
        std::cout << 1 << ' ';
      }
    }
    std::cout << '\n';
  }
  return 0;
}
