#include <iostream>

void Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void SelectionSort(int* matrix, int n) {  // reversed
  for (int i = 0; i < n - 1; i++) {
    int max_index = i;
    for (int j = i + 1; j < n; j++) {
      if (matrix[j] > matrix[max_index]) {
        max_index = j;
      }
    }
    Swap(matrix[max_index], matrix[i]);
  }
}

int main() {
  int n;
  uint32_t s = 0;
  std::cin >> n;
  int* prices = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> prices[i];
  }
  SelectionSort(prices, n);
  for (int i = 0; i < n; i++) {
    if ((i + 1) % 3 == 0) {
      prices[i] = 0;
    }
    s += prices[i];
  }
  std::cout << s << std::endl;
  delete[] prices;
  return 0;
}
