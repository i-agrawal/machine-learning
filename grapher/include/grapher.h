#ifndef __GRAPHER_H__
#define __GRAPHER_H__

typedef struct {
  void * session;
} window;

window * create_window();
void destroy_window(window *);
void send_command(window *, char *, ...);

#endif
