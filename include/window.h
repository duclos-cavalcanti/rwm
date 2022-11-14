#ifndef __WINDOW__H
#define __WINDOW__H

#include "main.h"
#include <stdbool.h>

typedef struct window {
    Window win;
    int x, y;
    unsigned int width, height;
    bool is_floating, is_fullscreen, is_focused, is_urgent, is_sticky;
} window_t;

window_t* new_window(Window* w);

#endif /* __WINDOW__H */
