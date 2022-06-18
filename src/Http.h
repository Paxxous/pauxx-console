#pragma once
#include <curl/curl.h>

// The Http class. Because that is the goal of c++
class Http {
public:
  Http();
  void post(const char *url, const char* payload);
  void cleanUp();
private:
  CURL* curl;
  CURLcode res;
};
