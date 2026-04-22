#include <iostream>

int main() {
  int n, x, index;
  std::cin >> n;
  int* matrix = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> matrix[i];
  }
  std::cin >> x >> index;
  int* new_numbers = new int[n + 1];
  for (int i = 0; i < index - 1; i++) {
    new_numbers[i] = matrix[i];
  }
  new_numbers[index - 1] = x;
  for (int i = index; i < n + 1; i++) {
    new_numbers[i] = matrix[i - 1];
  }
  for (int i = 0; i < n + 1; i++) {
    std::cout << new_numbers[i] << ' ';
  }
  std::cout << std::endl;
  delete[] matrix;
  delete[] new_numbers;
  return 0;
}
