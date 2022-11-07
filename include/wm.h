#ifndef __WM__H
#define __WM__H

#include "main.h"
#include "window.h"

typedef struct window_manager {
    Display* dpy;
    window_t* root;
} window_manager_t;

int on_wm_found(Display* d, XErrorEvent* e);
int on_x_error(Display* d, XErrorEvent* e);
void on_create_notify(window_manager_t* wm, const XCreateWindowEvent* e);
void on_configure_request(window_manager_t* wm, const XConfigureRequestEvent* e);

#endif /* __WM__H */
