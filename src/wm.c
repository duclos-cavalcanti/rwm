#include "main.h"
#include "wm.h"

#include <stdio.h>
#include <stdbool.h>

int on_wm_found(Display* d, XErrorEvent* e, bool* WM_FOUND) {
    if (e->error_code == BadAccess) {
        (*WM_FOUND) = true;
    }

    return 0;
}

#define MAX_ERROR_TEXT_LENGTH 1024
int on_x_error(Display* d, XErrorEvent* e) {
    char err[MAX_ERROR_TEXT_LENGTH] = { 0 };

    XGetErrorText(d, e->error_code, err, sizeof(err));
    printf("Received X Error:\n"
           "\tRequest: %d - %s\n"
           "\tError code: %d - %s\n"
           "\tResource ID: %d\n",
           (int) e->request_code,
           (char*) XRequestCodeToString(e->request_code),
           (int) e->error_code,
           err,
           (int) e->resourceid);

    return 0;
}

void on_create_notify(window_manager_t* wm, const XCreateWindowEvent* e) {}

void on_configure_request(window_manager_t* wm, const XConfigureRequestEvent* e) {
    XWindowChanges c;

    c.x = e->x;
    c.y = e->y;
    c.width = e->width;
    c.height = e->height;
    c.border_width = e->border_width;
    c.sibling = e->above;
    c.stack_mode = e->detail;

    XConfigureWindow(wm->dpy, e->window, e->value_mask, &c);
    return;
}
