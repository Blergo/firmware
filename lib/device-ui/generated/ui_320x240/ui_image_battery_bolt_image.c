
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
uint8_t img_battery_bolt_image_map[] = {

    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xd9,0xd9,0xd9,0x00,0xff,0xff,0xff,0x00,0xdd,0xdd,0xdd,0x00,0xde,0xde,0xde,0x00,0xdc,0xdc,0xdc,0x00,0xdc,0xdc,0xdc,0x00,0xdc,0xdc,0xdc,0x00,0xdc,0xdc,0xdc,0x00,0xdc,0xdc,0xdc,0x00,0xdc,0xdc,0xdc,0x00,0xdc,0xdc,0xdc,0x00,0xdc,0xdc,0xdc,0x00,0xdc,0xdc,0xdc,0x00,0xdd,0xdd,0xdd,0x00,0xdd,0xdd,0xdd,0x00,0xd9,0xd9,0xd9,0x00,0xda,0xda,0xda,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xdc,0xdc,0xdc,0x00,0xdb,0xdb,0xdb,0x00,0xe0,0xe0,0xe0,0x00,0xdc,0xdc,0xdc,0x04,0xde,0xde,0xde,0x0b,0xdd,0xdd,0xdd,0x0c,0xdd,0xdd,0xdd,0x0c,0xdd,0xdd,0xdd,0x0c,0xdd,0xdd,0xdd,0x0c,0xdd,0xdd,0xdd,0x0c,0xdd,0xdd,0xdd,0x0c,0xdd,0xdd,0xdd,0x0c,0xdd,0xdd,0xdd,0x0c,0xdd,0xdd,0xdd,0x0c,0xde,0xde,0xde,0x0c,0xdd,0xdd,0xdd,0x06,0xe1,0xe1,0xe1,0x00,0xdd,0xdd,0xdd,0x00,0xdd,0xdd,0xdd,0x00,0x00,0x00,0x00,0x00,
    0xda,0xda,0xda,0x00,0xe8,0xe8,0xe8,0x00,0xdf,0xdf,0xdf,0x42,0xe0,0xe0,0xe0,0xac,0xe0,0xe0,0xe0,0xc8,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xb6,0xdf,0xdf,0xdf,0x57,0xdb,0xdb,0xdb,0x02,0xdd,0xdd,0xdd,0x00,0x00,0x00,0x00,0x00,
    0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x24,0xe0,0xe0,0xe0,0xdb,0xe0,0xe0,0xe0,0xf1,0xe0,0xe0,0xe0,0xcc,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc7,0xe0,0xe0,0xe0,0xc6,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xca,0xe0,0xe0,0xe0,0xe9,0xe0,0xe0,0xe0,0xed,0xdf,0xdf,0xdf,0x3e,0xdf,0xdf,0xdf,0x00,0x00,0x00,0x00,0x00,
    0xe0,0xe0,0xe0,0x00,0xdf,0xdf,0xdf,0x52,0xe0,0xe0,0xe0,0xfd,0xdf,0xdf,0xdf,0x76,0xdd,0xdd,0xdd,0x0a,0xde,0xde,0xde,0x0c,0xde,0xde,0xde,0x0c,0xde,0xde,0xde,0x0b,0xdf,0xdf,0xdf,0x31,0xdf,0xdf,0xdf,0x48,0xde,0xde,0xde,0x0f,0xde,0xde,0xde,0x0c,0xde,0xde,0xde,0x0c,0xde,0xde,0xde,0x0c,0xdd,0xdd,0xdd,0x09,0xdf,0xdf,0xdf,0x55,0xe0,0xe0,0xe0,0xfc,0xdf,0xdf,0xdf,0x77,0xe1,0xe1,0xe1,0x00,0xd8,0xd8,0xd8,0x00,
    0xe0,0xe0,0xe0,0x00,0xdf,0xdf,0xdf,0x5a,0xe0,0xe0,0xe0,0xfd,0xdf,0xdf,0xdf,0x5a,0xe0,0xe0,0xe0,0x00,0xde,0xde,0xde,0x00,0xde,0xde,0xde,0x00,0xdd,0xdd,0xdd,0x0a,0xe0,0xe0,0xe0,0xb4,0xe0,0xe0,0xe0,0xd1,0xde,0xde,0xde,0x13,0xde,0xde,0xde,0x00,0xde,0xde,0xde,0x00,0xde,0xde,0xde,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x38,0xe0,0xe0,0xe0,0xf6,0xdf,0xdf,0xdf,0x80,0xe1,0xe1,0xe1,0x00,0xe1,0xe1,0xe1,0x00,
    0xe0,0xe0,0xe0,0x00,0xdf,0xdf,0xdf,0x5a,0xe0,0xe0,0xe0,0xfd,0xdf,0xdf,0xdf,0x5b,0xe0,0xe0,0xe0,0x00,0xe2,0xe2,0xe2,0x00,0xe0,0xe0,0xe0,0x00,0xdf,0xdf,0xdf,0x4f,0xe0,0xe0,0xe0,0xf9,0xdf,0xdf,0xdf,0x9e,0xdd,0xdd,0xdd,0x0f,0xdd,0xdd,0xdd,0x06,0xe2,0xe2,0xe2,0x00,0xe2,0xe2,0xe2,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x39,0xe0,0xe0,0xe0,0xf5,0xe0,0xe0,0xe0,0xc6,0xdf,0xdf,0xdf,0x23,0xdf,0xdf,0xdf,0x00,
    0xe0,0xe0,0xe0,0x00,0xdf,0xdf,0xdf,0x5a,0xe0,0xe0,0xe0,0xfd,0xdf,0xdf,0xdf,0x5b,0xe0,0xe0,0xe0,0x00,0xdd,0xdd,0xdd,0x00,0xdd,0xdd,0xdd,0x08,0xe0,0xe0,0xe0,0xb4,0xe0,0xe0,0xe0,0xff,0xe0,0xe0,0xe0,0xdd,0xe0,0xe0,0xe0,0xc6,0xe0,0xe0,0xe0,0xa3,0xde,0xde,0xde,0x14,0xde,0xde,0xde,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x39,0xe0,0xe0,0xe0,0xf3,0xe0,0xe0,0xe0,0xff,0xdf,0xdf,0xdf,0x59,0xe0,0xe0,0xe0,0x00,
    0xe0,0xe0,0xe0,0x00,0xdf,0xdf,0xdf,0x5a,0xe0,0xe0,0xe0,0xfd,0xdf,0xdf,0xdf,0x5b,0xe0,0xe0,0xe0,0x00,0xde,0xde,0xde,0x00,0xdd,0xdd,0xdd,0x08,0xdf,0xdf,0xdf,0x8d,0xe0,0xe0,0xe0,0xc7,0xe0,0xe0,0xe0,0xd5,0xe0,0xe0,0xe0,0xff,0xe0,0xe0,0xe0,0xd3,0xde,0xde,0xde,0x17,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x39,0xe0,0xe0,0xe0,0xf3,0xe0,0xe0,0xe0,0xff,0xdf,0xdf,0xdf,0x59,0xe0,0xe0,0xe0,0x00,
    0xe0,0xe0,0xe0,0x00,0xdf,0xdf,0xdf,0x5a,0xe0,0xe0,0xe0,0xfd,0xdf,0xdf,0xdf,0x5b,0xe0,0xe0,0xe0,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xdc,0xdc,0xdc,0x05,0xdb,0xdb,0xdb,0x0a,0xdf,0xdf,0xdf,0x7c,0xe0,0xe0,0xe0,0xff,0xdf,0xdf,0xdf,0x72,0xe2,0xe2,0xe2,0x00,0xda,0xda,0xda,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x39,0xe0,0xe0,0xe0,0xf5,0xe0,0xe0,0xe0,0xc6,0xdf,0xdf,0xdf,0x23,0xdf,0xdf,0xdf,0x00,
    0xe0,0xe0,0xe0,0x00,0xdf,0xdf,0xdf,0x5a,0xe0,0xe0,0xe0,0xfd,0xdf,0xdf,0xdf,0x5a,0xe0,0xe0,0xe0,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xde,0xde,0xde,0x00,0xdc,0xdc,0xdc,0x05,0xe0,0xe0,0xe0,0xb3,0xe0,0xe0,0xe0,0xd1,0xdf,0xdf,0xdf,0x1a,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x38,0xe0,0xe0,0xe0,0xf6,0xdf,0xdf,0xdf,0x80,0xe1,0xe1,0xe1,0x00,0xe1,0xe1,0xe1,0x00,
    0xe0,0xe0,0xe0,0x00,0xdf,0xdf,0xdf,0x52,0xe0,0xe0,0xe0,0xfd,0xdf,0xdf,0xdf,0x76,0xdd,0xdd,0xdd,0x0a,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x3e,0xdf,0xdf,0xdf,0x3d,0xdf,0xdf,0xdf,0x0b,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xde,0xde,0xde,0x09,0xdf,0xdf,0xdf,0x55,0xe0,0xe0,0xe0,0xfc,0xdf,0xdf,0xdf,0x77,0xe1,0xe1,0xe1,0x00,0xd8,0xd8,0xd8,0x00,
    0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x24,0xe0,0xe0,0xe0,0xdb,0xe0,0xe0,0xe0,0xf1,0xe0,0xe0,0xe0,0xcb,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc6,0xe0,0xe0,0xe0,0xc6,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xca,0xe0,0xe0,0xe0,0xe8,0xe0,0xe0,0xe0,0xee,0xdf,0xdf,0xdf,0x3e,0xdf,0xdf,0xdf,0x00,0x00,0x00,0x00,0x00,
    0xda,0xda,0xda,0x00,0xe8,0xe8,0xe8,0x00,0xdf,0xdf,0xdf,0x42,0xe0,0xe0,0xe0,0xad,0xe0,0xe0,0xe0,0xc8,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xc9,0xe0,0xe0,0xe0,0xb6,0xdf,0xdf,0xdf,0x57,0xdb,0xdb,0xdb,0x02,0xdd,0xdd,0xdd,0x00,0x00,0x00,0x00,0x00,
    0xdc,0xdc,0xdc,0x00,0xdb,0xdb,0xdb,0x00,0xe0,0xe0,0xe0,0x00,0xdc,0xdc,0xdc,0x04,0xde,0xde,0xde,0x0b,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xdf,0xdf,0xdf,0x0c,0xde,0xde,0xde,0x0c,0xdd,0xdd,0xdd,0x06,0xe1,0xe1,0xe1,0x00,0xdd,0xdd,0xdd,0x00,0xdd,0xdd,0xdd,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xd9,0xd9,0xd9,0x00,0xff,0xff,0xff,0x00,0xdd,0xdd,0xdd,0x00,0xde,0xde,0xde,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xdf,0xdf,0xdf,0x00,0xde,0xde,0xde,0x00,0xdd,0xdd,0xdd,0x00,0xd9,0xd9,0xd9,0x00,0xda,0xda,0xda,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

};

const lv_img_dsc_t img_battery_bolt_image = {
  .header.magic = LV_IMAGE_HEADER_MAGIC,
  .header.cf = LV_COLOR_FORMAT_ARGB8888,
  .header.flags = 0,
  .header.w = 20,
  .header.h = 20,
  .header.stride = 80,
  .data_size = 1600,
  .data = img_battery_bolt_image_map,
};

