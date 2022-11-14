#ifndef __WINDOW__H
#define __WINDOW__H

#include "main.h"
#include <stdboo.h>

typedef struct window {
    Window win;
    int x, y;
    unsigned int width, height;
    bool is_floating, is_tiled;
} window_t;

window_t* new_window(Window* w);

#endif /* __WINDOW__H */
