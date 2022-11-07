#ifndef __WINDOW__H
#define __WINDOW__H

#include "main.h"

typedef struct window {
    Window win;
    int x, y;
    unsigned int width, height;
    unsigned int layout;
} window_t;


#endif /* __WINDOW__H */
