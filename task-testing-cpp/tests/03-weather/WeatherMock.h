//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>
#include <filesystem>
#include <fstream>

std::unordered_map<std::string, std::unordered_map<std::string, cpr::Response>> FromFile(std::ifstream& f);
void ToFile(const std::unordered_map<std::string, std::unordered_map<std::string, cpr::Response>>& obj, std::ifstream& f);

class WeatherMock : public Weather {
 public:
  // WeatherMock();
  MOCK_METHOD(json, GetResponseForCity, (const std::string &city, const cpr::Url& url));
  MOCK_METHOD(float, GetTemperature, (const std::string& city), (override));
  MOCK_METHOD(float, GetTomorrowTemperature, (const std::string& city), (override));
  MOCK_METHOD(std::string, GetLocationKey, (const std::string& city), (override));
  MOCK_METHOD(float, FindDiffBetweenTwoCities, (const std::string& city1, const std::string& city2));
  MOCK_METHOD(void, SetApiKey, (const std::string& api_key));
  MOCK_METHOD(std::string, GetDifferenceString, (const std::string& city1, const std::string& city2));
  MOCK_METHOD(std::string, GetTomorrowDiff, (const std::string& city));
  MOCK_METHOD(cpr::Response, Get, (const std::string& city, const cpr::Url& url), (override));
  void DelegateToFake() {
    ON_CALL(*this, Get).WillByDefault([this](const std::string& city, const cpr::Url& url) {
      return weather_fake_.Get(city, url);
    });
  }
  // cpr::Response Get(const std::string& city, const cpr::Url& url) override;
  // ~WeatherMock();
 private:
  WeatherFake weather_fake_;
  // const cpr::Url kBaseUrl = cpr::Url{"http://dataservice.accuweather.com/currentconditions/v1/"};
  // const cpr::Url kForecastUrl = cpr::Url{"http://dataservice.accuweather.com/forecasts/v1/daily/5day/"};
  // const cpr::Url kLocationUrl = cpr::Url{"http://dataservice.accuweather.com/locations/v1/cities/search"};
  // std::string api_key_;

  // std::unordered_map<cpr::Url, std::unordered_map<std::string, cpr::Response>> requests_cache_;
  // std::unordered_map<std::string, std::string> locations_cache_;
};

class WeatherFake : public Weather {
 public:
  WeatherFake(const std::string& api_key = "");
  ~WeatherFake();
  void SetApiKey(const std::string& api_key);
  cpr::Response Get(const std::string& city, const cpr::Url& url);
 private:
  const cpr::Url kBaseUrl = cpr::Url{"http://dataservice.accuweather.com/currentconditions/v1/"};
  const cpr::Url kForecastUrl = cpr::Url{"http://dataservice.accuweather.com/forecasts/v1/daily/5day/"};
  const cpr::Url kLocationUrl = cpr::Url{"http://dataservice.accuweather.com/locations/v1/cities/search"};
  std::string api_key_;

  std::unordered_map<std::string, std::string> locations_cache_;
  std::unordered_map<std::string, std::unordered_map<std::string, cpr::Response>> requests_cache_;
};

