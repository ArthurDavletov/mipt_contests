#include <iostream>

int main() {
  int64_t x, y;
  std::cin >> x >> y;
  int32_t i = x, j = y;
  while (i * j != 0) {
    if (i > j) {
      i %= j;
    } else {
      j %= i;
    }
  }
  std::cout << i + j << ' ' << x * y / (i + j) << std::endl;
  return 0;
}
