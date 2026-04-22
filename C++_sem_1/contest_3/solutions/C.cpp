#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  int** matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[m];
    matrix[i][0] = 1;
  }
  for (int j = 0; j < m; j++) {
    matrix[0][j] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
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
