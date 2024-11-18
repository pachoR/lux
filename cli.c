#include "lux.h"

void turn_off_echo(void) {
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void turn_on_echo(void) {
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag |= (ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void clear_screen(void) {}
