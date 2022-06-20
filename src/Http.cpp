#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <ncurses.h>

#include "Http.h"

// Initialize the easy curl interface
Http::Http() {
  curl = curl_easy_init();
}


// Preform a post request to communicate with out server
int Http::post(const char* url, const char* payload) {
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);

  // Preform the post request
  res = curl_easy_perform(curl);

  // Check for any occuring errors
  if (res != CURLE_OK) {
    printw("There was an error preforming the post request:\n%s\n", curl_easy_strerror(res)); 
  }

  else {
    printw("The post request was a success :D\n");
  }

  // return the status of the request
  return res;
}


// Preform a get request to recieve data from the server
int Http::get(const char* url) {
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
  curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1L);

  // Preform our little request
  res = curl_easy_perform(curl);
 
  const char* tux;
  // Write the data to a string
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &tux);

  // Debug the request
  if (res != CURLE_OK) {
    printw("There was a error preforming the get request:\n%s\n", curl_easy_strerror(res));
  }

  else {
    printw("The get request was a success :D\n(and with a response of %s)", tux);
  }

  // Return the status code
  return res;
}

// Cleanup curl
void Http::cleanUp() {
  curl_easy_cleanup(curl);
}

/* Lmao this turned from an ncurses project to a curl one */
