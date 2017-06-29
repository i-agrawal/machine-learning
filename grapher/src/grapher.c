#include "grapher.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef PLOTTER
#define PLOTTER "gnuplot-src/install/bin/gnuplot",
#endif

window * create_window() {
  window * ptr = (window *)malloc(sizeof(window));
  FILE * session = popen(PLOTTER, "w");
  if (session == NULL) {
    fprintf(stderr, "unable to open gnuplot binary\n");
  }

  ptr->session = (void *)session;
  return ptr;
}

// Assume ending program does not close file
void destroy_window(window * win) {
  int status;

  fprintf((FILE *)win->session, "exit\n");
  status = pclose((FILE *)win->session);
  if (status == -1) {
    fprintf(stderr, "unable to close gnuplot window");
  }
}

// Assume commands dont end with newline
void send_command(window * win, char * cmd) {
  fprintf((FILE *)win->session, "%s\n", cmd);
  fflush((FILE *)win->session);
}

void draw_line(window * win, double m, double b) {
  fprintf((FILE *)win->session, "replot %g * x + %g\n", m, b);
  fflush((FILE *)win->session);
}
