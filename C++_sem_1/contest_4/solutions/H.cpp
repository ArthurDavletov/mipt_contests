#include <iostream>

void IndexInsert(int* matrix, int old_index, int new_index) {
  int elem = matrix[old_index];
  if (old_index > new_index) {
    for (int i = old_index; i > new_index; i--) {
      matrix[i] = matrix[i - 1];
    }
  } else {
    for (int i = old_index; i < new_index; i++) {
      matrix[i] = matrix[i + 1];
    }
  }
  matrix[new_index] = elem;
}

int main() {
  int n;
  std::cin >> n;
  int* matrix = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> matrix[i];
  }
  for (int i = 1; i < n; i++) {
    bool inserted_elem = false;
    for (int j = i - 1; j >= 0; j--) {
      if (matrix[i] > matrix[j]) {
        IndexInsert(matrix, i, j + 1);
        inserted_elem = true;
        break;
      }
    }
    if (!inserted_elem) {
      IndexInsert(matrix, i, 0);
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << matrix[i] << ' ';
  }
  std::cout << std::endl;
  delete[] matrix;
  return 0;
}
