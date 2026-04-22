#include <iostream>

void Partition(int* matrix, int n, int pivot, int& i, int& j) {
  int k = 0;
  for (int index = 0; index < n; index++) {
    if (i + j + k >= n) {
      break;
    }
    while (matrix[index] < pivot && (i + j + k < n)) {
      std::swap(matrix[index], matrix[n - 1 - k]);
      k++;
    }
    if (matrix[index] > pivot) {
      std::swap(matrix[index], matrix[i]);
      i++;
    } else if (matrix[index] == pivot) {
      std::swap(matrix[index], matrix[i + j]);
      j++;
    }
  }
}

void QuickSort(int* matrix, int n) {
  if (n > 1) {
    int i = 0, j = 0;
    int pivot = matrix[0];
    Partition(matrix, n, pivot, i, j);
    QuickSort(matrix, i);
    QuickSort(matrix + i + j, n - i - j);
  }
}

int main() {
  int n, s, count;
  int counter = 0;
  std::cin >> n >> s;
  auto money = new int[n];
  auto bank = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> money[i];
  }
  QuickSort(money, n);
  for (int i = 0; i < n; i++) {
    count = s / money[i];
    if (count > 0) {
      for (int j = 0; j < count; j++) {
        bank[counter++] = money[i];
      }
      s -= count * money[i];
    }
  }
  if (s == 0) {
    std::cout << counter << std::endl;
    for (int i = 0; i < counter; i++) {
      std::cout << bank[i] << ' ';
    }
    std::cout << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }
  delete[] money;
  delete[] bank;
  return 0;
}
