#include <iostream>

void Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void Merge(const int* a, int a_size, const int* b, int b_size, int* c) {
  int i = 0, j = 0;
  while (i < a_size && j < b_size) {
    if (a[i] <= b[j]) {
      c[i + j] = a[i];
      i++;
    } else {
      c[i + j] = b[j];
      j++;
    }
  }
  while (i < a_size) {
    c[i + j] = a[i];
    i++;
  }
  while (j < b_size) {
    c[i + j] = b[j];
    j++;
  }
}

void MergeSortBody(int* a, int n, int* buf) {
  if (n == 1) {
    return;
  }
  if (n == 2) {
    if (a[0] > a[1]) {
      Swap(a[0], a[1]);
    }
    return;
  }
  int m = n / 2;
  MergeSortBody(a, m, buf);
  MergeSortBody(a + m, n - m, buf);
  Merge(a, m, a + m, n - m, buf);
  for (int i = 0; i < n; i++) {
    a[i] = buf[i];
  }
}

void MergeSort(int* a, int n) {
  int* buf = new int[n];
  MergeSortBody(a, n, buf);
  delete[] buf;
}

int main() {
  int n;
  std::cin >> n;
  int* table = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> table[i];
  }
  MergeSort(table, n);
  for (int i = 0; i < n; i++) {
    std::cout << table[i] << ' ';
  }
  std::cout << std::endl;
  delete[] table;
}
