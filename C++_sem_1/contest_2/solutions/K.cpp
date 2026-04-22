#include <iostream>

int main() {
  int a, b;
  std::ios_base::sync_with_stdio(false);
  std::cin >> a >> b;
  int c = a, d = b;
  while (a != 0 && b != 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  int g = a + b;
  std::cout << c / g << ' ' << d / g << '\n';
  return 0;
}
