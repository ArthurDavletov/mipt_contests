#include "WeatherTestCase.h"

namespace fs = std::filesystem;
using ::testing::_;

NiceMock<WeatherMock>* WeatherTestCase::weather_mock;

// WeatherTestCase::WeatherTestCase() {
void WeatherTestCase::SetUpTestSuite () {
  std::string key = "";
  weather_mock = new NiceMock<WeatherMock>();
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
  NiceMock<WeatherMock> wm;
  wm.DelegateToFakeGet();
  wm.SetApiKey("___");
  
  const cpr::Url kLocationUrl = cpr::Url{"http://dataservice.accuweather.com/locations/v1/cities/search"};
  std::cout << "Ufa = " << wm.GetLocationKey("Ufa") << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  // std::cout << "t = " << weather_mock->GetTemperature("Ufa") << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
  // EXPECT_CALL(*weather_mock, Get(_, _));
 
  weather_mock->DelegateToFakeGet();
}