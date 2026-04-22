#include <iostream>

int Fib(int n) {
  if (n <= 2) {
    return 1;
  }
  return 1 + Fib(n - 1) + Fib(n - 2);
}

int main() {
  int n;
  std::cin >> n;
  std::cout << Fib(n) << std::endl;
  return 0;
}
