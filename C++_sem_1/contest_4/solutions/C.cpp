#include <iostream>

bool IsPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int x;
  std::cin >> x;
  if (IsPrime(x)) {
    std::cout << "prime" << std::endl;
  } else {
    std::cout << "composite" << std::endl;
  }
  return 0;
}
