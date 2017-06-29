#include "grapher.h"
#include <stdio.h>

int main() {
  window * win = create_window();
  send_command(win, "plot x");

  printf("press enter to end: ");
  fflush(stdout);
  getc(stdin);

  destroy_window(win);
}
