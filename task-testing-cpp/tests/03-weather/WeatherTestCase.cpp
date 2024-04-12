//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"

namespace fs = std::filesystem;
using ::testing::_;

WeatherMock* WeatherTestCase::weather_mock;

// WeatherTestCase::WeatherTestCase() {
void WeatherTestCase::SetUpTestSuite () {
  std::string key = "";
  weather_mock = new WeatherMock();
  const std::string& path = "api_key.txt";  // путь к вашему файлу с api-key
  if (fs::exists(path)) {
    std::ifstream f(path);
    f >> key;
    f.close();
  }
  weather_mock->SetApiKey(key);
}

void WeatherTestCase::TearDownTestSuite() {
  delete weather_mock;
}

TEST_F(WeatherTestCase, GetTemperature) {
  std::cout << "t = " << weather_mock->GetTemperature("Ufa") << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
  EXPECT_CALL(*weather_mock, GetLocationKey(_));
  weather_mock->DelegateToFakeGet();
}