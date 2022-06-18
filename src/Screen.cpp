#include <ncurses.h>
#include "Screen.h"

Screen::Screen() {
  /*
   * All this does is Initialize the screen once the class is called
   * So that means that you need to manually close it with the close function. ez.
  */

  initscr(); // Initlaize the screen
  keypad(stdscr, true); // Take more input than just text from the keyboard
}

// Close the ncurses window
void Screen::close() {
  endwin();
}
