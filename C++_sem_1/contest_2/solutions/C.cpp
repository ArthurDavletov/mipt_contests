#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  if (a == 0) {
    if (a == b) {
      std::cout << "INF" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  } else {
    int answer = -b / a;
    if (a * answer + b == 0) {
      if (c * answer + d == 0) {
        std::cout << "NO";
      } else {
        std::cout << answer << std::endl;
      }
    } else {
      std::cout << "NO" << std::endl;
    }
  }
}
