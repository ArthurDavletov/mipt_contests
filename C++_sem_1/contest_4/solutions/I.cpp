#include <iostream>

void Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int n;
  std::cin >> n;
  int* matrix = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> matrix[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n - i; j++) {
      if (matrix[j] < matrix[j - 1]) {
        Swap(matrix[j], matrix[j - 1]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << matrix[i] << ' ';
  }
  std::cout << std::endl;
  delete[] matrix;
  return 0;
}
