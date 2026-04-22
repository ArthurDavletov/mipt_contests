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

int GetMaxDelta(int* rating, int n, int k) {
  int max_number = 0, delta;
  for (int i = k - 1; i < n; i += k) {
    delta = rating[i] - rating[i - k + 1];
    if (delta > max_number) {
      max_number = delta;
    }
  }
  return max_number;
}

int main() {
  int n, m, k, min_number = 0, number;
  std::cin >> n >> m >> k;
  auto* rating = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> rating[i];
  }
  QuickSort(rating, n);
  for (int i = 0; i <= n % (m * k); i++) {
    number = GetMaxDelta(rating + i, m * k, k);
    if (i == 0 || min_number > number) {
      min_number = number;
    }
  }
  std::cout << min_number << std::endl;
  delete[] rating;
  return 0;
}
