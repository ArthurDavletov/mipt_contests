#include <iostream>

void Resize(int*& array, int& old_size, int new_size) {
  int* new_array = new int[new_size]{};
  for (int i = 0; i < old_size; i++) {
    new_array[i] = array[i];
  }
  old_size = new_size;
  delete[] array;
  array = new_array;
}

void Insert(int*& array, int& size, int elem) {
  if (elem >= size - 1) {
    Resize(array, size, elem + 1);
  }
  array[elem]++;
}

int main() {
  int negative_size = 1, non_negative_size = 1;
  int* negative = new int[1]{};
  int* non_negative = new int[1]{};
  int n, elem;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> elem;
    if (elem < 0) {
      Insert(negative, negative_size, -elem);
    } else {
      Insert(non_negative, non_negative_size, elem);
    }
  }
  for (int i = negative_size - 1; i > 0; i--) {
    for (int j = 0; j < negative[i]; j++) {
      std::cout << -i << std::endl;
    }
  }
  for (int i = 0; i < non_negative_size; i++) {
    for (int j = 0; j < non_negative[i]; j++) {
      std::cout << i << std::endl;
    }
  }
  delete[] negative;
  delete[] non_negative;
  return 0;
}
