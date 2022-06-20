#include <cstdio>
#include <curl/curl.h>
#include <curl/easy.h>
#include <ncurses.h>
#include <fstream>

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

  // return the status of the request
  return res;
}


// Preform a get request to recieve data from the server
int Http::get(const char* url) {
  // Set up the file that'll have the GET response written to
  GETResponse = fopen("GETRES.txt", "wb");

  curl_easy_setopt(curl, CURLOPT_URL, url); // First, initialize our url
  curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L); // Then, get ready for an HTTPGET
  curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1L); // Forbid a reuse of the request
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL); // Setup a write function
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, GETResponse); // Then write the response to a file.

  // Close our file
  fclose(GETResponse);

  // Preform our little request
  res = curl_easy_perform(curl);
 
  // Debug the request
  if (res != CURLE_OK) {
    printw("There was a error preforming the get request:\n%s\n", curl_easy_strerror(res));
  }

  // Return the status code
  return res;
}

// Cleanup curl
void Http::cleanUp() {
  curl_easy_cleanup(curl);
}

/* Lmao this turned from an ncurses project to a curl one */
