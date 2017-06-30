#include "grapher.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef GNUPLOT_LOC
#define GNUPLOT_LOC "gnuplot"
#endif

window * create_window() {
  window * ptr = (window *)malloc(sizeof(window));
  FILE * session = popen(GNUPLOT_LOC, "w");
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
    fprintf(stderr, "unable to close gnuplot window\n");
  }
}

// Assume commands dont end with newline
void send_command(window * win, char * format, ...) {
  va_list args;
  va_start(args, format);
  vfprintf((FILE *)win->session, format, args);
  va_end(args);
  fprintf((FILE *)win->session, "\n");
  fflush((FILE *)win->session);
}
