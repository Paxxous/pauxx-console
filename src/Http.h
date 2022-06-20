#pragma once
#include <curl/curl.h>
#include <string>

// The Http class. Because that is the goal of c++
class Http {
public:
  Http();
  int post(const char *url, const char* payload);
  int get(const char *url);
  void cleanUp();
private:
  CURL* curl;
  CURLcode res;
  FILE* GETResponse;
};
