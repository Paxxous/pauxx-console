#include <iostream>
#include <ncurses.h>
#include "Screen.h"

/* Lmao this is the main function idoit */
int main() {
  // Initialize the main screen
  Screen scr;

  // Print something to the console
  printw("amongus?\n");

  // Wait for a keystroke
  getch();

  // Close the screen and end the program
  scr.close();
}
