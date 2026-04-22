#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int** matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[n]{};
  }
  int k = 0, t = 0;
  while (2 * k < n) {
    for (int j = k / 2 + t; j < n - k; j++) {
      matrix[k][j] = 1;
    }
    for (int i = k; i < n - k; i++) {
      matrix[i][n - k - 1] = 1;
    }
    for (int j = n - k - 1; j >= k; j--) {
      matrix[n - k - 1][j] = 1;
    }
    for (int i = n - k - 1; i >= k + 2; i--) {
      matrix[i][k] = 1;
    }
    if (k >= 4) {
      t++;
    }
    k += 2;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << matrix[i][j];
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < n; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;
}
