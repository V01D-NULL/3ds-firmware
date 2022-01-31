#include "fb.h"
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
	*fb++ = 0xFF;
	*fb++ = 0xFF;
	*fb++ = 0xFF;
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