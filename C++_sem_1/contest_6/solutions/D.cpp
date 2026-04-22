#include <iostream>

void Partition(int* matrix, int n, int pivot, int& i, int& j) {
  int k = 0;
  for (int index = 0; index < n; index++) {
    if (i + j + k >= n) {
      break;
    }
    while (matrix[index] > pivot && (i + j + k < n)) {
      std::swap(matrix[index], matrix[n - 1 - k]);
      k++;
    }
    if (matrix[index] < pivot) {
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

int PopElem(int*& matrix, int& n, int index) {
  int* new_matrix = new int[n - 1];
  for (int i = 0; i < index; i++) {
    new_matrix[i] = matrix[i];
  }
  int element = matrix[index];
  for (int i = index + 1; i < n; i++) {
    new_matrix[i - 1] = matrix[i];
  }
  n--;
  delete[] matrix;
  matrix = new_matrix;
  return element;
}

void InsertElem(int*& matrix, int& n, int index, int element) {
  int* new_matrix = new int[n + 1];
  for (int i = 0; i < index; i++) {
    new_matrix[i] = matrix[i];
  }
  new_matrix[index] = element;
  for (int i = index; i < n; i++) {
    new_matrix[i + 1] = matrix[i];
  }
  n++;
  delete[] matrix;
  matrix = new_matrix;
}

int main() {
  int n, k;
  std::cin >> n;
  int* houses = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> houses[i];
  }
  std::cin >> k;
  int elem = PopElem(houses, n, k - 1);
  QuickSort(houses, n);
  if ((k == 1 && (abs(houses[n - 1] - elem) < abs(houses[0] - elem))) ||
      (k == n && (abs(houses[n - 1] - elem) > abs(houses[0] - elem))) ||
      (abs(houses[n - k] - elem) + abs(houses[n - k + 1] - elem) <
       abs(houses[k - 1] - elem) + abs(houses[k - 2] - elem))) {
    for (int i = n - 1; i > n - k; i--) {
      std::cout << houses[i] << ' ';
    }
    std::cout << elem << ' ';
    for (int i = n - k; i >= 0; i--) {
      std::cout << houses[i] << ' ';
    }
  } else {
    for (int i = 0; i < k - 1; i++) {
      std::cout << houses[i] << ' ';
    }
    std::cout << elem << ' ';
    for (int i = k - 1; i < n; i++) {
      std::cout << houses[i] << ' ';
    }
  }
  std::cout << std::endl;
  delete[] houses;
  return 0;
}
