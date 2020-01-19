#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _FN 5
#define _TENKEY 6
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FN,
  TENKEY,
  ADJUST,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC_XXXX  KC_NO
#define KC_____  KC_TRNS
#define KC_LOWR  LT(LOWER, KC_BSPC)
#define KC_RAIS  LT(RAISE, KC_ESC)
#define KC_AJST  ADJUST
#define KC_FN    FN
#define KC_TENK  TG(_TENKEY)
#define KC_RST   RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [_QWERTY] = LAYOUT_kc(
          ESC,    1,    2,    3,    4,    5,    6,        5,    6,    7,    8,    9,    0, TILD,
           TAB,    Q,    W,    E,    R,    T,    Y,        T,    Y,    U,    I,    O,    P, BSPC,
           LCTL,    A,    S,    D,    F,    G,    H,        G,    H,    J,    K,    L, SCLN, QUOT,
            LSFT,    Z,    X,    C,    V,    B,    N,        B,    N,    M, COMM,  DOT, SLSH,   FN,
             AJST, TENK, LWIN, LALT, LOWR,  SPC,  SPC,      ENT, RAIS, BSPC, LEFT, DOWN,   UP, RGHT
    ),
    [_LOWER] = LAYOUT_kc(
         ____, ____, ____, ____, ____, ____, ____,     ____, ____, ____, ____, ____, ____, ____,
          ____,   F1,   F2,   F3,   F4,   F5,   F6,       F7,   F8,   F9,  F10,  F11,  F12, ____,
           ____,    1,    2,    3,    4,    5,    6,        5,    6,    7,    8,    9,    0,  DEL,
            ____, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,     XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, ____,
             ____, ____, ____, ____, ____, ____, ____,     ____, ____, ____, ____, ____, ____, ____
    ),
    [_RAISE] = LAYOUT_kc(
         ____, ____, ____, ____, ____, ____, ____,     ____, ____, ____, ____, ____, ____, ____,
          ____, EXLM,   AT, HASH,  DLR, PERC, CIRC,     PERC, CIRC, AMPR, ASTR, LPRN, RPRN, ____,
           ____, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,     XXXX, MINS,  EQL, PIPE, LCBR, RCBR, GRV,
            ____, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,     XXXX, UNDS, PLUS, BSLS, LBRC, RBRC, TILD,
             ____, ____, ____, ____, ____, ____, ____,     ____, ____, ____, ____, ____, ____, ____
    ),
    [_FN] = LAYOUT_kc(
         ____,   F1,   F2,   F3,   F4,   F5,   F6,       F7,   F8,   F9,  F10,  F11,  F12,  DEL,
          ____, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,     XXXX, XXXX, XXXX, XXXX,   UP,   UP,  DEL,
           ____,    1,    2,    3,    4,    5,    6,        5,    6,    7,    8, LEFT, RGHT, ____,
            ____, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,     XXXX, XXXX, XXXX, XXXX, DOWN, DOWN, ____,
             ____, ____, ____, ____, ____, ____, ____,     ____, ____, ____, ____, ____, ____, ____
    ),
    [_ADJUST] = LAYOUT_kc(
          RST, ____, ____, ____, ____, ____, ____,     ____, ____, ____, ____, ____, ____, ____,
          ____, ____, ____, ____, ____, ____, ____,     ____, ____, ____, ____, ____, ____, ____,
           ____, ____, ____, ____, ____, ____, ____,     ____, ____, ____, ____, ____, ____, ____,
            ____, ____, ____, ____, ____, ____, ____,     ____, ____, ____, ____, ____, ____, ____,
             ____, ____, ____, ____, ____, ____, ____,     ____, ____, ____, ____, ____, ____, ____
    ),
    [_TENKEY] = LAYOUT_kc(
         XXXX,    7,    8,    9, MINS,  EQL, XXXX,     XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
           TAB,    4,    5,    6, PLUS, XXXX, XXXX,     XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
           XXXX,    1,    2,    3, ASTR, XXXX, XXXX,     XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
            XXXX, BSPC,    0,  ENT, SLSH, XXXX, XXXX,     XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
             XXXX, TENK, LALT, LALT, XXXX, XXXX, XXXX,     XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX
    )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
  }
  return true;
}

