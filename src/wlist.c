#include "wlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_empty(wlist_t* wl) {
    return (wl->head == NULL);
}

wnode_t* new_node(Window* w) {
    wnode_t* ret = (wnode_t*) calloc(1, sizeof(wnode_t));
    if (!ret) {
        fprintf(stderr, "Creating window node failed!\n");
        exit(EXIT_FAILURE);
    }

    ret->w = new_window(w);
    ret->next = NULL;
    return ret;
}

void insert_window(wlist_t* wl, Window* w) {
    wnode_t* n = new_node(w);
    if (is_empty(wl)) {
        wl->head = n;
    } else {
        wnode_t* it;
        for (it = wl->head; it->next; it=it->next){}
        it->next = n;
    }

    return;
}

wlist_t* new_list() {
    wlist_t* ret = (wlist_t*) calloc(1, sizeof(wlist_t));
    if (!ret) {
        fprintf(stderr, "Creating window list failed!\n");
        exit(EXIT_FAILURE);
    }

    return ret;
}

wnode_t* find_window(wlist_t* wl, Window* win) {
    if (is_empty(wl)) {
        return NULL;
    } else {
        wnode_t* it;
        for (it=wl->head; it; it=it->next)
            if (it->w->win == *win)
                return it;
        return NULL;
    }
}
