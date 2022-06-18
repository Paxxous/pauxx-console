#include "Http.h"
#include <curl/curl.h>

// Initialize the easy curl interface
Http::Http() {
  curl = curl_easy_init();
}
