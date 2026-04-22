#include <iostream>

int Sum(int a, int b) {
  if (a == 0) {
    return b;
  }
  return Sum(--a, ++b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << Sum(a, b) << std::endl;
}
