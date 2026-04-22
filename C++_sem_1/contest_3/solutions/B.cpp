#include <iostream>

int main() {
  int n, m, best_result = 0, counter = 0;
  std::cin >> n >> m;
  int** matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[m];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int temp;
      std::cin >> temp;
      matrix[i][j] = temp;
      if (best_result < temp) {
        best_result = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == best_result) {
        counter++;
        break;
      }
    }
  }
  std::cout << counter << std::endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == best_result) {
        std::cout << i << ' ';
        break;
      }
    }
  }
  std::cout << std::endl;

  for (int i = 0; i < n; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;
}
