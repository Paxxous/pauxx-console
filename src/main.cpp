#include <iostream>
#include <ncurses.h>
#include "Screen.h"
#include "Http.h"
#include "Settings.h"

/* Lmao this is the main function idoit */
int main() {
  // Initialize the main screen
  Screen scr;
  
  // Initialize the http module
  Http http;
  // initSettings();
  
  http.post("http://127.0.0.1:8080/post", "Content=Hello, world!");

  // Print something to the console
  printw("amongus?\n");

  // Wait for a keystroke
  getch();
 
  // Close the screen and end the program
  scr.close();
}
