#include <iostream>

int main() {
  int a, b, answer = 0;
  std::cin >> a >> b;
  while (b != 0) {
    answer += a / b;
    int temp = a;
    a = b;
    b = temp % b;
  }
  std::cout << answer << std::endl;
}
