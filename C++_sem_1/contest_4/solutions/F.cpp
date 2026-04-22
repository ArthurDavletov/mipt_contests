#include <iostream>

void Swap(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  int n;
  std::cin >> n;
  int* matrix = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> matrix[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int* min_elem = &matrix[i];
    for (int j = i + 1; j < n; j++) {
      if (matrix[j] < *min_elem) {
        min_elem = &matrix[j];
      }
    }
    Swap(matrix[i], *min_elem);
  }
  for (int i = 0; i < n; i++) {
    std::cout << matrix[i] << ' ';
  }
  std::cout << std::endl;
  delete[] matrix;
  return 0;
}
