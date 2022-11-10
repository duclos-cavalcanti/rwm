#ifndef __WINDOW__H
#define __WINDOW__H

#include "wm.h"

typedef struct window {
    Window win;
    int x, y;
    unsigned int width, height;
    unsigned int layout;
} window_t;

typedef struct wnode {
    window_t* w;
    window_t* next;
} wnode_t;

typedef struct wlist {
    wnode_t* head;
} wlist_t;

int frame_window(window_manager_t* wm, window_t* w);

#endif /* __WINDOW__H */
