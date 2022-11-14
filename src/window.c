#include "window.h"

window_t* new_window(Window* w) {
    window_t* ret = (window_t*) calloc(1, sizeof(window_t));
    if (!ret) {
        fprintf(stderr, "Creating window struct failed!\n");
        exit(EXIT_FAILURE);
    }

    ret->win = (*w);
    return ret;
}
