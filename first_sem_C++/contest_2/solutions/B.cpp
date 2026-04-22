#include <iostream>

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  if ((k % m == 0 || k % n == 0) && (k < n * m)) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
}
