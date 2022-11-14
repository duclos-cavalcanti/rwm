#include "main.h"
#include "wm.h"

#include <stdio.h>
#include <stdbool.h>

// Taken from DWM. Many thanks. https://git.suckless.org/dwm
static void (*handler[LASTEvent]) (window_manager_t*, XEvent*) = {
	[CreateNotify] = create_notify,
	[ConfigureRequest] = configure_request,
	[ConfigureNotify] = configure_notify,
};

void create_notify(window_manager_t* wm, const XEvent* e) {}

void configure_request(window_manager_t* wm, const XEvent* e) {
    XConfigureRequestEvent *ev = &e->xconfigurerequest;
    XWindowChanges c;

    c.x = ev->x;
    c.y = ev->y;
    c.width = ev->width;
    c.height = ev->height;
    c.border_width = ev->border_width;
    c.sibling = ev->above;
    c.stack_mode = ev->detail;

    XConfigureWindow(wm->dpy, e->window, e->value_mask, &c);
    return;
}

int process_event(window_manager_t* wm, XEvent* e) {
    if (handler(e->type))
        handler(wm, e);
    return 0;
}
