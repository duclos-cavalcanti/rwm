#include "main.h"
#include "wm.h"
#include "util.h"

static bool WM_FOUND = false;

int wm_handler(Display* d, XErrorEvent* e) {
    if (e->error_code == BadAccess) {
        WM_FOUND = true;
    }
    return 0;
}

int detect_wm(window_manager_t* wm) {
    XSetErrorHandler(&wm_handler);
    XSelectInput(wm->dpy,
                 wm->root->win,
                 SubstructureRedirectMask |
                 SubstructureNotifyMask);
    XSync(wm->dpy, false);

    if (WM_FOUND) return 1;
    return 0;
}

