#include <core/fb.h>
#include <core/mmio.h>
#include <font.h>
/*
	References:
	 - https://www.3dbrew.org/wiki/GPU/FR
	 - https://www.3dbrew.org/wiki/MTX_Registers
*/

// The physical display is rotated by 90° meaning (0,0) is the bottom left.
// These helper macros relocate the (x,y) offsets so that the (x,y) coordinates
// are relative to the top left corner of the display
#define LCD_SKIP 3
#define CORRECT_X(x) (x * FB_HEIGHT * 3)
#define CORRECT_Y(y) (FB_HEIGHT - y) * LCD_SKIP
#define CORRECT_XY(x, y) CORRECT_X(x) + CORRECT_Y(y)

static inline void pixel(u8 *fb, u32 hex, u32 x, u32 y)
{
	fb += CORRECT_XY(x, y);
	*fb++ = hex & 0xff;
	*fb++ = (hex >> 8) & 0xff;
	*fb++ = (hex >> 16) & 0xff;
}

void putc(bool isTopScreen, u32 posX, u32 posY, u32 color, char c)
{
	u8 *top_display_fb = (u8 *)0x18300000;

	for (int y = 0; y < 8; y++)
	{
		u8 selection = font[c * 8 + y];
		for (int x = 0; x < 8; x++)
		{
			bool can_draw = selection & (1 << (7 - x));
			if (can_draw)
				pixel(top_display_fb, 0xFFFFFF, posX + x, posY + y);
		}
	}
}

void fb_clear(void)
{
	u8 *top_display_fb = (u8 *)0x18300000;
	for (int y = 0; y <= FB_HEIGHT; y++)
	{
		for (int x = 0; x <= FB_TOP_WIDTH; x++)
		{
			pixel(top_display_fb, 0u, x, y);
		}
	}
}

void deinit_displays(void)
{
	mmio_write32(0x10202A44, 0);
	mmio_write32(0x10202244, 0);
	mmio_write32(0x10202014, 0);
}