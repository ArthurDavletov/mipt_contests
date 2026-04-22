#include <iostream>

int main() {
  int32_t n, m;
  std::cin >> n >> m;
  int32_t** matrix = new int32_t * [n];
  for (int32_t i = 0; i < n; i++) {
    matrix[i] = new int32_t[m] {0};
  }

  int32_t row = 0, col = 0, diag = 0;
  for (int32_t i = 1; i < n * m; i++) {
    row++;
    col--;
    if (col < 0 || row == n) {
      diag++;
      if (diag < m)   {
        col = diag;
      } else {
        col = m - 1;
      } 
      row = diag - col;
    }
    matrix[row][col] = i;
  }


  for (int32_t i = 0; i < n; i++) {
    for (int32_t j = 0; j < m; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  for (int32_t i = 0; i < n; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;
}
