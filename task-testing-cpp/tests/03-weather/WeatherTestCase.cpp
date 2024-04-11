//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

void WeatherTestCase::SetUpTestSuite() {
  
}

TEST_F(WeatherTestCase, AA) {
  ASSERT_EQ("123", "123");
}