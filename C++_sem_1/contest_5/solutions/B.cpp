#include <iostream>

void Printer(int n) {
  int temp;
  std::cin >> temp;
  if (n > 1) {
    Printer(--n);
  }
  std::cout << temp << ' ';
}

int main() {
  int n;
  std::cin >> n;
  Printer(n);
  std::cout << std::endl;
  return 0;
}
