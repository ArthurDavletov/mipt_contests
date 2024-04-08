#include "main.h"

int main() {
  // Количество элементов
  size_t n;
  std::cin >> n;

  std::vector<int> arr(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  SelectionSort(arr);

  for (auto elem : arr) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;

  return 0;
}