#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "window.h"
#include "wm.h"

window_manager_t* wm = { 0 };

int detect() {
    XSetErrorHandler(&on_wm_found);
    XSelectInput(wm->dpy,
                 wm->root->win,
                 SubstructureRedirectMask |
                 SubstructureNotifyMask);
    XSync(wm->dpy, false);

    if (WM_FOUND) return 1;
    return 0;
}


int start() {
    wm->dpy = XOpenDisplay(NULL);
    if (!wm->dpy) {
        fprintf(stderr, "Failed to open XDisplay.\n");
        return EXIT_FAILURE;
    }

    wm->root->win = DefaultRootWindow(wm->dpy);
    return 0;
}

void run() {
    if (detect(wm)) goto leave;
    XSetErrorHandler(&on_x_error);

    while(1) {
        XEvent e;
        XNextEvent(wm->dpy, &e);
        switch(e.type) {
            case CreateNotify:
                on_create_notify(wm, &e.xcreatewindow);
                break;

            case ConfigureNotify:
                on_configure_notify(wm, &e.xconfigure);

            default:
                break;
        }
    }
leave:
    return;
}

void close() {
    XCloseDisplay(wm->dpy);
}

int main(int argc, char* argv[]) {
    start();
    run();
    close();

    return EXIT_SUCCESS;
}
