
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#elif defined(LV_BUILD_TEST)
#include "../lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_DUST
#define LV_ATTRIBUTE_IMG_DUST
#endif

static const
LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_DUST
uint8_t img_knob_logo_image_map[] = {

    0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x03,0xff,0xff,0xff,0x5b,0xff,0xff,0xff,0x2a,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x33,0xff,0xff,0xff,0x55,0xff,0xff,0xff,0x01,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0x34,0x34,0x34,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x42,0xff,0xff,0xff,0xe3,0xff,0xff,0xff,0x55,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x11,0xff,0xff,0xff,0xba,0xff,0xff,0xff,0xea,0xff,0xff,0xff,0x3b,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x15,0xff,0xff,0xff,0xc4,0xff,0xff,0xff,0xa9,0xff,0xff,0xff,0x0a,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x7c,0xff,0xff,0xff,0xd9,0xff,0xff,0xff,0xbf,0xff,0xff,0xff,0xbc,0xff,0xff,0xff,0x12,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x84,0xff,0xff,0xff,0xdc,0xff,0xff,0xff,0x2b,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x3c,0xff,0xff,0xff,0xe2,0xff,0xff,0xff,0x60,0xff,0xff,0xff,0x26,0xff,0xff,0xff,0xd8,0xff,0xff,0xff,0x7e,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x43,0xff,0xff,0xff,0xe6,0xff,0xff,0xff,0x64,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x12,0xff,0xff,0xff,0xbe,0xff,0xff,0xff,0xa6,0xff,0xff,0xff,0x08,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x61,0xff,0xff,0xff,0xe2,0xff,0xff,0xff,0x3e,0xff,0xff,0xff,0x00,
    0xff,0xff,0xff,0x1a,0xff,0xff,0xff,0xc3,0xff,0xff,0xff,0xa8,0xff,0xff,0xff,0x08,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x7e,0xff,0xff,0xff,0xd8,0xff,0xff,0xff,0x28,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x07,0xff,0xff,0xff,0xa3,0xff,0xff,0xff,0xbe,0xff,0xff,0xff,0x18,
    0xff,0xff,0xff,0x74,0xff,0xff,0xff,0xd3,0xff,0xff,0xff,0x2a,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x25,0xff,0xff,0xff,0xd3,0xff,0xff,0xff,0x61,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x26,0xff,0xff,0xff,0xcf,0xff,0xff,0xff,0x70,
    0xff,0xff,0xff,0x23,0xff,0xff,0xff,0x3b,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x0b,0xff,0xff,0xff,0x43,0xff,0xff,0xff,0x0b,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x38,0xff,0xff,0xff,0x23,

};

const lv_img_dsc_t img_knob_logo_image = {
  .header.magic = LV_IMAGE_HEADER_MAGIC,
  .header.cf = LV_COLOR_FORMAT_ARGB8888,
  .header.flags = 0,
  .header.w = 14,
  .header.h = 8,
  .header.stride = 56,
  .data_size = 448,
  .data = img_knob_logo_image_map,
};

