#include "window.h"

window_t* new_window(Window* win) {
    window_t* ret = (window_t*) calloc(1, sizeof(window_t));
    if (!ret) {
        fprintf(stderr, "Creating window struct failed!\n");
        exit(EXIT_FAILURE);
    }

    ret->win = (*win);
    ret->x = 0;
    ret->y = 0;
    ret->width = 0;
    ret->height = 0;
    ret->is_floating = false;
    ret->is_fullscreen = false;
    ret->is_focused = false;
    ret->is_urgent = false;
    ret->is_sticky = false;

    return ret;
}
