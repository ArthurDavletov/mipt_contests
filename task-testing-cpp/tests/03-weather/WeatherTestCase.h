
#pragma once

#include <gtest/gtest.h>
#include <string>

class WeatherTestCase : public ::testing::Test {
 public:
  static void SetUpTestSuite();
 private:
  std::string api_key_;
};



