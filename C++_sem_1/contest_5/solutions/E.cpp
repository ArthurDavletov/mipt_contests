#include <iostream>

int64_t F(int64_t i, int64_t adder = 0) {
  if (i == 0) {
    return adder;
  }
  return F(i & (i - 1), (adder + 1) % 3);
}
// Как это работает? Как это работает? Как это работает?
// Мне просто предложили заменить i - 2 ** float(log2(i)) на i & (i - 1)
// У меня сейчас эйфория от этой задачи. Неожиданное решение

int main() {
  int64_t i;
  std::cin >> i;
  std::cout << F(i - 1) << std::endl;
}
