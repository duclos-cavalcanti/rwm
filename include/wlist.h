#ifndef __WLIST__H
#define __WLIST__H

#include "window.h"

typedef struct wnode {
    window_t* w;
    struct wnode* next;
} wnode_t;

typedef struct wlist {
    wnode_t* head;
} wlist_t;

wlist_t* new_list();
void insert_window(wlist_t* wl, Window* w);
wnode_t* find_window(wlist_t* wl, Window* win);

#endif /* __WLIST__H */
