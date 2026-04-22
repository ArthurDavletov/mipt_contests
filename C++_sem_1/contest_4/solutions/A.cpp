#include <iostream>

int Gcd(int x, int y) {
  while (x * y != 0) {
    if (x > y) {
      x %= y;
    } else {
      y %= x;
    }
  }
  return x + y;
}

int main() {
  int n, x, y, answer = 0;
  std::cin >> n >> x >> y;
  answer = Gcd(x, y);
  for (int i = 2; i < n; i++) {
    std::cin >> y;
    answer = Gcd(answer, y);
  }
  std::cout << answer << std::endl;
  return 0;
}
