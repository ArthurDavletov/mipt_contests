#pragma once

#include <gtest/gtest.h>
#include <string>
#include "WeatherMock.h"

using ::testing::NiceMock;

class WeatherTestCase : public ::testing::Test {
 public:
  WeatherTestCase();
 protected:
  NiceMock<WeatherMock> weather_mock;
  Weather real_weather;
};



