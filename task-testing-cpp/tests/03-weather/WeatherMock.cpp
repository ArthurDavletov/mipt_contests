//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherMock.h"

namespace fs = std::filesystem;

std::unordered_map<std::string, std::unordered_map<std::string, cpr::Response>> FromFile(std::ifstream& f) {
  json json_obj;
  std::unordered_map<std::string, std::unordered_map<std::string, cpr::Response>> obj;
  try {
    f >> json_obj;
  } catch (json::parse_error) {
    return obj;
  }
  for (auto it = json_obj.begin(); it != json_obj.end(); it++) {
    const std::string& url = it.key();
    const json& in_json = it.value();
    std::unordered_map<std::string, cpr::Response> in_map;
    for (auto jt = in_json.begin(); jt != in_json.end(); jt++) { 
      const std::string& city = jt.key();
      const json& json_response = jt.value();
      cpr::Response response;
      response.status_code = json_response["status_code"];
      response.text = json_response["text"];
      in_map[city] = response;
    }
    obj[url] = in_map;
  }
  return obj;
}

void ToFile(const std::unordered_map<std::string, std::unordered_map<std::string, cpr::Response>>& obj, std::ofstream& f) {
  json json_obj;
  for (auto it = obj.begin(); it != obj.end(); it++) {
    const std::string& url = it->first;
    const std::unordered_map<std::string, cpr::Response>& in_map = it->second;
    json in_json;
    for (auto jt = in_map.begin(); jt != in_map.end(); jt++) {
      const std::string& city = jt->first;
      const cpr::Response response = jt->second;
      json json_response;
      json_response["status_code"] = response.status_code;
      json_response["text"] = response.text;
      in_json[city] = json_response;
    }
    json_obj[url] = in_json;
  }
  f << json_obj;
}

WeatherFake::WeatherFake() {
  if (!fs::exists("weather_cache/cache.json")) {
    fs::create_directory("weather_cache");
    std::ofstream("weather_cache/cache.json").close();
    return;
  }
  std::ifstream f("weather_cache/cache.json");
  requests_cache_ = FromFile(f);
  f.close();
}

WeatherFake::~WeatherFake() {
  std::ofstream f("weather_cache/cache.json");
  ToFile(requests_cache_, f);
  f.close();
}

cpr::Response WeatherFake::Get(const std::string& city, const cpr::Url& url) {
  return FakeGet(city, url);
}

cpr::Response WeatherFake::FakeGet(const std::string& city, const cpr::Url& url) {
  const std::string& url_str = url.str();
  if (requests_cache_.find(url_str) == requests_cache_.end()) {
    requests_cache_[url_str] = std::unordered_map<std::string, cpr::Response>();
  }
  if (requests_cache_[url_str].find(city) == requests_cache_[url_str].end()) {
    requests_cache_[url_str][city] = cpr::Get(
      url, cpr::Parameters{
          {"q", city},
          {"apikey", api_key_},
          {"metric", "true"},
          {"language", "en-us"}
      }
    );
  }
  return requests_cache_[url_str][city];
}

void WeatherFake::SetFakeApiKey(const std::string& api_key) {
  api_key_ = api_key;
  SetApiKey(api_key);
}

WeatherMock::WeatherMock() {
  ON_CALL(*this, SetApiKey).WillByDefault([this](const std::string& api_key) {
    SetFakeApiKey(api_key);
  });
}

void WeatherMock::DelegateToFakeGet() {
  ON_CALL(*this, Get).WillByDefault([this](const std::string& city, const cpr::Url& url) {
    return FakeGet(city, url);
  });
}