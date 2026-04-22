#pragma once

#include <gtest/gtest.h>
#include <string>
#include "WeatherMock.h"

using ::testing::NiceMock;

class WeatherTestCase : public ::testing::Test {
 public:
  WeatherTestCase();
  virtual ~WeatherTestCase() = default;
 protected:
  NiceMock<WeatherMock> weather_mock;
  WeatherFake weather_fake;
};



