#pragma once
#include <curl/curl.h>

class Http {
public:
  Http();
private:
  CURL* curl;
};
