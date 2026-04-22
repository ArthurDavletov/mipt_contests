#include "AddTestCase.h"
#include "Functions.h"

TEST(AddTestCase, AddNumbers) {
  for (int i = -10; i < 10; i++) {
    for (int j = -10; j < 10; j++) {
      ASSERT_EQ(Add(i, j), i + j);
    }
  }
}