#include "lib.h"

void SelectionSort(std::vector<int>& table) {
  size_t n = table.size();
  for (size_t i = 0; i < n; i++) {
    size_t min_index = i;
    for (size_t j = i + 1; j < n; j++) {
      if (table[j] < table[min_index]) {
        min_index = j;
      }
    }
    std::swap(table[i], table[min_index]);
  }
}