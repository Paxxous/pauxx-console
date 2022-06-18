#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>

#include "Http.h"

// Initialize the easy curl interface
Http::Http() {
  curl = curl_easy_init();
}

// Preform a post request to communicate with out server
void Http::post(const char* url, const char* payload) {
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);

  // Preform the post request
  res = curl_easy_perform(curl);

  // Check for any occuring errors
  if (res != CURLE_OK) {
    std::cout << "There was an error preforming the request:\n" << curl_easy_strerror(res) << std::endl;
  }

  else {
    std::cout << "The request was a success :D" << std::endl;
  }

  // Always cleanup
  curl_easy_cleanup(curl);
}
