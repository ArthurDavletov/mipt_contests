#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;
  int* matrix = new int32_t[n];
  int* numbers = new int32_t[k];
  for (int i = 0; i < n; i++) {
    int32_t temp;
    std::cin >> temp;
    matrix[i] = temp;
  }
  for (int i = 0; i < k; i++) {
    int32_t temp;
    std::cin >> temp;
    numbers[i] = temp;
  }
  for (int ki = 0; ki < k; ki++) {
    int32_t number = numbers[ki];
    int i = 0, j = n - 1;
    while (abs(i - j) > 1) {
      int half = (i + j) / 2;
      if (matrix[half] >= number) {
        j = half;
      } else {
        i = half;
      }
    }
    if (matrix[i] == number || matrix[j] == number) {
      std::cout << "YES" << '\
';
    } else {
      std::cout << "NO" << '\
';
    }
  }
  delete[] matrix;
  delete[] numbers;
  return 0;
}
