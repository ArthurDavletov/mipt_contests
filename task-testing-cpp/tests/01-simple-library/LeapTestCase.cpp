//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>
#include <vector>

TEST(LeapTestCase, NonLeapYears) {
  std::vector<int> years = {2010, 2011, 2013, 2014, 2015, 2017, 2018, 2019, 2021, 2022, 2023, 2025, 2026, 2027, 2029};
  for (int year : years) {
    ASSERT_TRUE(!IsLeap(year));
  }
}

TEST(LeapTestCase, SpecialNonLeapYears) {
  std::vector<int> years = {100, 200, 300, 500, 600, 700, 900, 1000, 1100, 1300, 1400, 1500, 1700, 1800, 1900, 2100};
  for (int year : years) {
    ASSERT_TRUE(!IsLeap(year));
  }
}

TEST(LeapTestCase, LeapYears) {
  std::vector<int> years = {2004, 2008, 2012, 2016, 2020, 2024, 2028, 2032, 2036, 2040, 2044, 2048, 2052, 2056, 2060};
  for (int year : years) {
    ASSERT_TRUE(IsLeap(year));
  }
}

TEST(LeapTestCase, SpecialLeapYears) {
  std::vector<int> years = {400, 800, 1200, 1600, 2000, 2400, 2800, 3200, 3600, 4000};
  for (int year : years) {
    ASSERT_TRUE(IsLeap(year));
  }
}

TEST(LeapTestCase, LeapFebruary) {
  std::vector<int> years = {400, 800, 1200, 1600, 2000, 2004, 2008, 2012, 2016};
  for (int year : years) {
    ASSERT_EQ(GetMonthDays(year, 2), 29);
  }
}

TEST(LeapTestCase, NonLeapFebruary) {
  std::vector<int> years = {1000, 1100, 1300, 1400, 1500, 1700, 1800, 1900, 2010, 2011, 2013, 2014, 2015, 2017};
  for (int year : years) {
    ASSERT_EQ(GetMonthDays(year, 2), 28);
  }
}

TEST(LeapTestCase, Days31) {
  std::vector<int> years = {1200, 1600, 1700, 1800, 1900, 2000, 2004, 2008, 2010, 2011, 2013};
  std::vector<int> months = {1, 3, 5, 7, 8, 10, 12};

  for (int year : years) {
    for (int month : months) {
      ASSERT_EQ(GetMonthDays(year, month), 31);
    }
  }
}

TEST(LeapTestCase, Days30) {
  std::vector<int> years = {1200, 1600, 1700, 1800, 1900, 2000, 2004, 2008, 2010, 2011, 2013};
  std::vector<int> months = {4, 6, 9, 11};

  for (int year : years) {
    for (int month : months) {
      ASSERT_EQ(GetMonthDays(year, month), 30);
    }
  }
}

TEST(LeapTestCase, USSRCalendar) {
  for (int i = 1; i <= 12; i++) {
    EXPECT_EQ(GetMonthDays(1930, i), 30);
  }
}

TEST(LeapTestCase, InvalidYear) {
  ASSERT_THROW(IsLeap(-10), std::invalid_argument);
}

TEST(LeapTestCase, InvalidMonth) {
  ASSERT_THROW(GetMonthDays(2024, -100), std::out_of_range);
  ASSERT_THROW(GetMonthDays(2024, 100), std::out_of_range);
}