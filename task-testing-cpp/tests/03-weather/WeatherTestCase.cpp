#include "WeatherTestCase.h"

namespace fs = std::filesystem;
using ::testing::_;
using ::testing::Return;

WeatherTestCase::WeatherTestCase() {
  std::string key = "";
  const std::string& path = "api_key.txt";  // путь к вашему файлу с api-key
  if (fs::exists(path)) {
    std::ifstream f(path);
    f >> key;
    f.close();
  }
  weather_mock.SetApiKey(key);
}

TEST_F(WeatherTestCase, GetBadCity) {
  // EXPECT_EQ(weather_mock.FindDiffBetweenTwoCities("a", "b"), 10);
  // std::cout << weather_mock.GetLocationKey("Anime_forever") << std::endl;
  weather_mock.DelegateToFakeGet();
}

TEST_F(WeatherTestCase, GetCitiesTemperature) {
  // std::cout << "Ufa = " << weather_mock.GetLocationKey("Ufa") << "\n";
}