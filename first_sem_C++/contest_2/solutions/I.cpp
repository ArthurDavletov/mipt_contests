#include <iostream>

int main() {
  int a = 0, b = 1, c, n;
  std::cin >> n;
  if (n == 0) {
    c = a;
  } else if (n == 1) {
    c = b;
  } else {
    for (int i = 1; i < n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
  }
  std::cout << c << std::endl;
}
