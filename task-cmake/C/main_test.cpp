#include "main_test.h"

void CheckVector(std::vector<int>&& y) {
  std::vector<int> x = y;
  SelectionSort(x);
  std::sort(y.begin(), y.end());
  // x - моя сортировка, y - реальная
  ASSERT_EQ(y.size(), x.size()) << "У векторов разные размеры\n";
  for (size_t i = 0; i < y.size(); i++) {
    EXPECT_EQ(y[i], x[i]);
  }
}

void CheckVector(std::vector<int>& y) {
  std::vector<int> x = y;
  SelectionSort(x);
  std::sort(y.begin(), y.end());
  // x - моя сортировка, y - реальная
  ASSERT_EQ(y.size(), x.size()) << "У векторов разные размеры\n";
  for (size_t i = 0; i < y.size(); i++) {
    EXPECT_EQ(y[i], x[i]);
  }
}

namespace {
  TEST(SelectionSortTest, OneElem) {
    CheckVector({1});
    CheckVector({0});
    CheckVector({-1});
  }

  TEST(SelectionSortTest, TwoElems) {
    for (int i = -3; i <= 3; i++) {
      for (int j = -3; j <= 3; j++) {
        CheckVector({i, j});
      }
    }
  }

  TEST(SelectionSortTest, RandomTests) {
    for (int i = 0; i < 30; i++) {
      int size = rand() % 500;
      std::vector<int> s(size);
      for (int i = 0; i < size; i++) {
        s[i] = rand() % 10000 - 5000;
      }
      CheckVector(s);
    }
  }
}

int main() { 
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}