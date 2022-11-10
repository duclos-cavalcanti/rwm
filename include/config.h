#ifndef __CONFIG__H
#define __CONFIG__H

#include "main.h"

typedef struct config {
    unsigned int border_width;
    unsigned long border_color;
    unsigned long bg_color;
} config_t;

config_t config_def = {
    .border_width = 2,
    .border_color = 0xff0000,
    .bg_color = 0x000000
};

#endif /* __CONFIG__H */
