#include "task_A.h"

void CheckIndex(const std::vector<int>& s, int elem) {
  int my_index = GetIndex(s, elem);
  std::vector<int>::const_iterator it = std::find(s.begin(), s.end(), elem);
  if (it == s.end()) {
    ASSERT_EQ(my_index, -1) << "Элемента в массиве на самом деле нет";
  } else {
    int true_index = std::distance(s.begin(), it);
    ASSERT_EQ(my_index, true_index) << "Элемент найден по неверному индексу";
  }
}

TEST(HeaderCheck, IndexTests) {
  for (int i = 0; i < 50; i++) {
    int size = rand() % 500;
    std::vector<int> s(size);
    for (int i = 0; i < size; i++) {
      s[i] = rand() % 10000 - 5000;
    }
    CheckIndex(s, rand() % 20000 - 10000);
  }
}