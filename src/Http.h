#pragma once
#include <curl/curl.h>

// The Http class. Because that is the goal of c++
class Http {
public:
  Http();
  int post(const char *url, const char* payload);
  int get(const char *url);
private:
  CURL* curl;
  CURLcode res;
};
