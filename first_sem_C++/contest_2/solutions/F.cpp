#include <iostream>

int main() {
  int n, s = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    std::cin >> temp;
    s += temp;
  }
  std::cout << s << std::endl;
}
