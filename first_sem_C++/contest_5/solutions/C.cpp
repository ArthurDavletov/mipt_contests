#include <iostream>

double FastPow(double a, int n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return a;
  }
  if (n % 2 == 0) {
    return FastPow(a * a, n / 2);
  }
  return a * FastPow(a, --n);
}

int main() {
  double a;
  int n;
  std::cin >> a >> n;
  std::cout << FastPow(a, n) << std::endl;
  return 0;
}
