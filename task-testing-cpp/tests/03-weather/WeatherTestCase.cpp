//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

namespace fs = std::filesystem;

void WeatherTestCase::SetUpTestSuite() {
  WeatherMock weather_mock;
  std::string api_key = "";
  const std::string& path = "api_key.txt";  // путь к вашему файлу с api-key
  if (fs::exists(path)) {
    std::ifstream f(path);
    f >> api_key;
    f.close();
  }
  weather_mock.SetApiKey(api_key);
}

TEST_F(WeatherTestCase, AA) {
  ASSERT_EQ("123", "123");
}