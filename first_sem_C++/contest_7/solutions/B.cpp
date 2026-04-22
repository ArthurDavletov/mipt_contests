#include <iostream>

void SiftDown(int* arr, int n, int i) {
  int largest = i;
  int lc = 2 * i + 1, rc = 2 * i + 2;
  if (lc < n && arr[lc] > arr[largest]) {
    largest = lc;
  }
  if (rc < n && arr[rc] > arr[largest]) {
    largest = rc;
  }
  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    SiftDown(arr, n, largest);
  }
}

void HeapInput(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
}

void HeapSort(int* arr, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    SiftDown(arr, n, i);
  }
  for (int i = n - 1; i >= 0; i--) {
    std::swap(arr[0], arr[i]);
    SiftDown(arr, i, 0);
  }
}

void HeapPrint(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

int main() {
  int n;
  std::cin >> n;
  auto* heap = new int[n];
  HeapInput(heap, n);
  HeapSort(heap, n);
  HeapPrint(heap, n);
  delete[] heap;
  return 0;
}
