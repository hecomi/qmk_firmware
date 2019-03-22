#pragma once

#include "../petit_split.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
//rgb led driver
#include "ws2812.h"
#endif

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);
#define LAYOUT( \
  L00, L01,   R00, R01, \
  L10, L11,   R10, R11 \
)\
{\
  { L00, L10 }, \
  { L01, L11 }, \
  { R01, R11 }, \
  { R00, R10 } \
}

#define LAYOUT_kc( \
  L00, L01,   R00, R01, \
  L10, L11,   R10, R11 \
)\
LAYOUT( \
  KC_##L00, KC_##L01, KC_##R00, KC_##R01, \
  KC_##L10, KC_##L11, KC_##R10, KC_##R11 \
)
