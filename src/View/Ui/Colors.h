#ifndef __COLORS_H__
#define __COLORS_H__

#define RGB2COLOR(r, g, b) ((((r>>3)<<11) | ((g>>2)<<5) | (b>>3)))

#define WIN95BASE 		RGB2COLOR(0xC0, 0xC0, 0xC0)
#define WIN95BASEDARK	RGB2COLOR(0x90, 0x90, 0x90)
#define WIN95BLUELIGHT	RGB2COLOR(0xA5, 0xC6, 0xDE)
#define WIN95BLUEDARK	RGB2COLOR(0x13, 0x27, 0x5D)
#define WHITE			RGB2COLOR(0xFF, 0xFF, 0xFF)
#define BLACK			RGB2COLOR(0x00, 0x00, 0x00)


#endif