#ifndef N3DS_FRAMEBUFFER_H
#define N3DS_FRAMEBUFFER_H

#include <types.h>

#define FB_TOP_WIDTH     400
#define FB_BOTTOM_WIDTH  320
#define FB_HEIGHT        240 // Both displays have the same height

void putc(bool isTopScreen, u32 posX, u32 posY, u32 color, char c);
void deinit_displays(void);

#endif // N3DS_FRAMEBUFFER_H