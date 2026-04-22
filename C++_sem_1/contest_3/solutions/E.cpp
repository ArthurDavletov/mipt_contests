#include <iostream>

int main() {
  int n, m, w;
  std::cin >> n >> m >> w;
  int** matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[m]{};
  }
  for (int row = 0; row < w; row++) {
    int i, j;
    std::cin >> i >> j;
    matrix[i - 1][j - 1] = -1;  // -1 -> мина
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] != -1) {
        for (int ai = i - 1; ai <= i + 1; ai++) {
          for (int aj = j - 1; aj <= j + 1; aj++) {
            if (ai >= 0 && ai < n && aj >= 0 && aj < m && matrix[ai][aj] == -1) {
              matrix[i][j]++;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == -1) {
        std::cout << '*' << ' ';
      } else {
        std::cout << matrix[i][j] << ' ';
      }
    }
    std::cout << '\
';
  }
  for (int i = 0; i < n; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;
}
