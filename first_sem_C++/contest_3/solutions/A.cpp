#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int** matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[n];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == n - j - 1) {
        matrix[i][j] = 1;
      } else if (i < n - j - 1) {
        matrix[i][j] = 0;
      } else {
        matrix[i][j] = 2;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < n; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;
}
