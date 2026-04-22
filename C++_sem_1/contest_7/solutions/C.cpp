#include <iostream>

void SiftDown(int*& array, int size, int& index) {
  while (2 * index + 1 < size) {
    int lc = 2 * index + 1;
    int rc = 2 * index + 2;
    if (rc >= size) {
      if (array[index] >= array[lc]) {
        break;
      }
      std::swap(array[lc], array[index]);
      index = lc;
    }
    int max_index = lc;
    if (rc < size && array[max_index] < array[rc]) {
      max_index = rc;
    }
    if (array[index] >= array[max_index]) {
      break;
    }
    std::swap(array[max_index], array[index]);
    index = max_index;
  }
}

void SiftUp(int*& array, int& index) {
  if (index != 0) {
    int parent = (index - 1) / 2;
    if (array[parent] < array[index]) {
      std::swap(array[parent], array[index]);
      index = (index - 1) / 2;
      SiftUp(array, index);
    }
  }
}

void ExtractMax(int*& array, int& size) {
  if (size == 0) {
    std::cout << -1 << std::endl;
    return;
  }
  int index = 0, elem = array[0];
  std::swap(array[size - 1], array[0]);
  size--;
  SiftDown(array, size, index);
  if (size == 0) {
    index = -1;
  }
  std::cout << index + 1 << ' ' << elem << std::endl;
}

void Insert(int*& array, int& size, int capacity, int elem) {
  if (size >= capacity) {
    std::cout << -1 << std::endl;
    return;
  }
  size++;
  array[size - 1] = elem;
  int index = size - 1;
  SiftUp(array, index);
  std::cout << index + 1 << std::endl;
}

void PrintHeap(int* array, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << array[i] << ' ';
  }
  std::cout << std::endl;
}

int main() {
  int n, m, command, elem, size = 0;
  std::cin >> n >> m;
  auto* heap = new int[n];
  for (int temp = 0; temp < m; temp++) {
    std::cin >> command;
    if (command == 1) {
      ExtractMax(heap, size);
    } else {
      std::cin >> elem;
      Insert(heap, size, n, elem);
    }
  }
  PrintHeap(heap, size);
  delete[] heap;
  return 0;
}
