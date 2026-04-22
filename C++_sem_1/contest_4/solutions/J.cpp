#include <iostream>

void Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int n, counter = 0;
  std::cin >> n;
  int* matrix = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> matrix[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n - i; j++) {
      if (matrix[j] < matrix[j - 1]) {
        Swap(matrix[j], matrix[j - 1]);
        counter++;
      }
    }
  }
  std::cout << counter << std::endl;
  delete[] matrix;
  return 0;
}
