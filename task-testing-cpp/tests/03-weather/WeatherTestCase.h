
#pragma once

#include <gtest/gtest.h>
#include <string>
#include "WeatherMock.h"

class WeatherTestCase : public ::testing::Test {
 public:
  // WeatherTestCase();
  static void SetUpTestSuite();
  static void TearDownTestSuite();
  // ~WeatherTestCase();
 protected:
  // WeatherMock* weather_mock;
  static WeatherMock* weather_mock;
};



