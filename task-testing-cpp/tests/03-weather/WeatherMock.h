#pragma once

#include <gmock/gmock.h>
#include <Weather.h>
#include <filesystem>
#include <fstream>

std::unordered_map<std::string, std::unordered_map<std::string, cpr::Response>> FromFile(std::ifstream& f);
void ToFile(const std::unordered_map<std::string, std::unordered_map<std::string, cpr::Response>>& obj, std::ifstream& f);

class WeatherFake : public Weather {
 public:
  WeatherFake();
  virtual ~WeatherFake();
  void SetFakeApiKey(const std::string& api_key);
 protected:
  cpr::Response Get(const std::string& city, const cpr::Url& url);
 private:
  std::string path_ = "../weather_cache/weather_cache.json";
  std::string api_key_;
  std::unordered_map<std::string, std::unordered_map<std::string, cpr::Response>> requests_cache_;
};

class WeatherMock : public WeatherFake {
 public:
  WeatherMock() = default;
  virtual ~WeatherMock() = default;
  void SetMockApiKey(const std::string& api_key);
  MOCK_METHOD(float, GetTemperature, (const std::string& city), (override));
  MOCK_METHOD(float, GetTomorrowTemperature, (const std::string& city), (override));
  MOCK_METHOD(std::string, GetLocationKey, (const std::string& city), (override));
  MOCK_METHOD(cpr::Response, Get, (const std::string& city, const cpr::Url& url), (override));
  Weather real;
 private:
  bool called_get_ = false;
};

