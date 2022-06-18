#include <iostream>
#include <ncurses.h>
#include "Screen.h"
#include "Settings.h"

/* Lmao this is the main function idoit */
int main()
{
  // Initialize the main screen
  initSettings();
  Screen scr;

  // Print something to the console
  printw("amongus?\n");

  // Wait for a keystroke
  getch();
 
  // Close the screen and end the program
  scr.close();
}
