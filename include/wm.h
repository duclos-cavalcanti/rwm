#ifndef __WM__H
#define __WM__H

#include "main.h"
#include "window.h"

#include <stdbool.h>

typedef enum layout {
    VERT,
    HORZ,
    MAX,
    FULL
} layout_t;

typedef struct window_manager {
    Display* dpy;
    window_t* root;
    wlist_t* clients;
    layout_t layout;
    int width, height;
    bool running;
} window_manager_t;

int process_event(window_manager_t* wm, int type);

#endif /* __WM__H */
