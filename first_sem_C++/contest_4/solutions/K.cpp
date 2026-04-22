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
  int n, m, k, counter = 0;
  std::cin >> n >> m;
  int* ship = new int[n * m];
  for (int i = 0; i < n * m; i++) {
    std::cin >> ship[i];
  }
  std::cin >> k;
  int* table = new int[k];
  for (int i = 0; i < k; i++) {
    std::cin >> table[i];
  }
  SelectionSort(table, k);
  SelectionSort(ship, n * m);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n * m; j++) {
      if (ship[j] != -1 && table[i] <= ship[j]) {
        counter++;
        ship[j] = -1;  // занято
        break;
      }
    }
  }
  std::cout << counter << std::endl;
  delete[] table;
  delete[] ship;
  return 0;
}
