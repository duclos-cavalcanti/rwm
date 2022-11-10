#include "window.h"

#include "config.h"

int frame_window(window_manager_t* wm, window_t* w) {
    XWindowAttributes xattr;
    XGetWindowAttributes(wm->dpy, w->win, &xattr);

    Window fr = XCreateSimpleWindow(wm->dpy, wm->root->win, xattr.x,
                                                            xattr.y,
                                                            xattr.width,
                                                            xattr.height,
                                                            config_def.border_width,
                                                            config_def.border_color,
                                                            config_def.bg_color);

    return 0;
}

