#ifndef __WM__H
#define __WM__H

#include "main.h"
#include "window.h"

#include <stdbool.h>

typedef struct window_manager {
    Display* dpy;
    window_t* root;
    wlist_t* clients;
} window_manager_t;

int on_wm_found(Display* d, XErrorEvent* e, bool* WM_FOUND);
int on_x_error(Display* d, XErrorEvent* e);
void on_create_notify(window_manager_t* wm, const XCreateWindowEvent* e);
void on_configure_request(window_manager_t* wm, const XConfigureRequestEvent* e);

#endif /* __WM__H */
