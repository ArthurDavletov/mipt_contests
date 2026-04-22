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

  weather_mock.SetFakeApiKey(key);
  weather_fake.SetFakeApiKey(key);
}

TEST_F(WeatherTestCase, GetDiffs) {
  std::string first = "Ufa";
  std::string second = "Moscow";
  for (int i = -20; i < 20; i += 10) {
    for (int j = -20; j < 20; j += 10) {
      EXPECT_CALL(weather_mock, GetTemperature(first)).WillOnce(Return(i));
      EXPECT_CALL(weather_mock, GetTemperature(second)).WillOnce(Return(j));
      auto diff = i - j;
      EXPECT_EQ(weather_mock.FindDiffBetweenTwoCities(first, second), diff);
    }
  }
}

TEST_F(WeatherTestCase, GetLocationKeyCheck) {
  std::string unreal_city = "Anime_Forever";
  EXPECT_THROW(weather_fake.GetLocationKey(unreal_city), std::runtime_error);
}

TEST_F(WeatherTestCase, GetTempCheck) {
  // -110 ... 70
  EXPECT_NEAR(weather_fake.GetTemperature("Ufa"), -20, 90);
}

TEST_F(WeatherTestCase, GetDiffString) {
  std::string f = "Weather in Ufa is ";
  std::string s = " than in Moscow by ";
  std::string first = "Ufa";
  std::string second = "Moscow";

  for (int i = -30; i <= 30; i += 5) {
    for (int j = -30; j <= 30; j += 5) {
      EXPECT_CALL(weather_mock, GetTemperature(first)).WillOnce(Return(i));
      EXPECT_CALL(weather_mock, GetTemperature(second)).WillOnce(Return(j));
      int diff = i - j;
      if (diff < 0) {
        std::string s_d = std::to_string(-diff);
        EXPECT_EQ(weather_mock.GetDifferenceString(first, second), f + "colder" + s + s_d + " degrees");
      } else {
        std::string s_d = std::to_string(diff);
        EXPECT_EQ(weather_mock.GetDifferenceString(first, second), f + "warmer" + s + s_d + " degrees");
      }
    }
  }
}

TEST_F(WeatherTestCase, BadApiError) {
  cpr::Response bad_response;
  bad_response.status_code = 401;
  bad_response.text = "Uncorrect API Key";
  cpr::Url url{"http://ya.ru/"};
  EXPECT_CALL(weather_mock, Get("BadApi", url)).WillOnce(Return(bad_response));
  EXPECT_THROW(weather_mock.GetResponseForCity("BadApi", url), std::invalid_argument);
}

TEST_F(WeatherTestCase, TomorrowTempCheck) {
  // -110 .. 70
  EXPECT_NEAR(weather_fake.GetTomorrowTemperature("Ufa"), -20, 90);
}

TEST_F(WeatherTestCase, GetTomorrowDiffCheck) {
  std::string city = "Ufa";
  std::string f = "The weather in Ufa tomorrow will be ";
  std::string s = " than today.";

  for (int i = -10; i <= 10; i += 5) {
    EXPECT_CALL(weather_mock, GetTomorrowTemperature(city)).Times(5).WillRepeatedly(Return(i));

    EXPECT_CALL(weather_mock, GetTemperature(city)).WillOnce(Return(i + 10));
    EXPECT_EQ(weather_mock.GetTomorrowDiff(city), f + "much colder" + s);

    EXPECT_CALL(weather_mock, GetTemperature(city)).WillOnce(Return(i + 2));
    EXPECT_EQ(weather_mock.GetTomorrowDiff(city), f + "colder" + s);

    EXPECT_CALL(weather_mock, GetTemperature(city)).WillOnce(Return(i - 10));
    EXPECT_EQ(weather_mock.GetTomorrowDiff(city), f + "much warmer" + s);

    EXPECT_CALL(weather_mock, GetTemperature(city)).WillOnce(Return(i - 2));
    EXPECT_EQ(weather_mock.GetTomorrowDiff(city), f + "warmer" + s);

    EXPECT_CALL(weather_mock, GetTemperature(city)).WillOnce(Return(i));
    EXPECT_EQ(weather_mock.GetTomorrowDiff(city), f + "the same" + s);
  }
}