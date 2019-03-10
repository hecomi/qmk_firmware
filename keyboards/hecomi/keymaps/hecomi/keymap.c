/* Copyright 2018 takashiski
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "hecomi.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

//R1:7 + 8 = 15
//R2:7 + 8 = 15
//R3:6 + 7 = 13
//R4:6 + 8 = 14
//R5:6 + 6 = 12
//total : 69 keys
//
enum layers{
  DF,
  FN,
  RAISE,
  LOWER,
  MOUSE1,
  MOUSE2,
};

#define KC_FN MO(FN)
#define KC_RAISE LT(RAISE, KC_BSPC)
#define KC_LOWER LT(LOWER, KC_ESC)
#define KC_MOUSE1 MO(MOUSE1)
#define KC_MOUSE2 MO(MOUSE2)
#define KC_SFT(XXX) LSFT(XXX)
#define _____ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DF]=LAYOUT(\
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                   KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NUHS, KC_GRV,\
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,\
      KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G,                       KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,\
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                        KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_FN,\
      KC_LCTRL, KC_MOUSE1, KC_LGUI, KC_RALT, KC_LOWER, KC_SPC,      KC_ENT, KC_RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT\
  ),
  [FN]=LAYOUT(\
      KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,             KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,\
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,                   KC_Y, KC_U, KC_PSCR, KC_SLCK, KC_PAUSE, KC_UP, KC_RBRC, KC_DEL,\
      KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,                        KC_SFT(KC_8), KC_SLSH, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT, KC_ENT,\
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                        KC_B, KC_SFT(KC_EQL), KC_MINS, KC_END, KC_PGDN, KC_DOWN, KC_RSFT, KC_TRNS,\
      KC_LCTRL, KC_LALT, KC_LGUI, KC_RALT, KC_LOWER, KC_SPC,        KC_ENT, KC_RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT\
  ),
  [LOWER]=LAYOUT(\
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                   KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NUHS, KC_GRV,\
      KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,             KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC,\
      KC_LCTRL, KC_1, KC_2, KC_3, KC_4, KC_5,                       KC_6, KC_7, KC_8, KC_9, KC_0, KC_QUOT, KC_ENT,\
      KC_LSFT, _____, _____, _____, _____, _____,                   _____, _____, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_RSFT, KC_FN,\
      KC_LCTRL, KC_LALT, KC_LGUI, KC_RALT, KC_LOWER, KC_SPC,        KC_ESC, KC_RAISE, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK\
  ),
  [RAISE]=LAYOUT(\
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                   KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NUHS, KC_GRV,\
      KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _____, _____, KC_BSPC,\
      KC_LCTRL, _____, _____, _____, _____, _____,                  KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV, KC_ENT,\
      KC_LSFT, _____, _____, _____, _____, _____,                   KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD, KC_RSFT, KC_FN,\
      KC_LCTRL, KC_LALT, KC_LGUI, KC_RALT, KC_LOWER, KC_SPC,        KC_ESC, KC_RAISE, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK\
  ),
  [MOUSE1]=LAYOUT(\
      KC_ESC, KC_ACL0, KC_ACL1, KC_ACL2, _____, _____, _____,       _____, _____, _____, _____, _____, _____, _____, _____,\
      KC_TAB, _____, KC_MS_U, _____, _____, _____, _____,           KC_MS_U, KC_MS_U, KC_MS_U, KC_MS_U, _____, _____, _____, _____,\
      KC_LCTRL, KC_MS_L, KC_MS_D, KC_MS_R, _____, _____,            KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _____, _____, _____,\
      KC_MOUSE2, _____, _____, _____, _____, _____,                 KC_MS_D, KC_MS_D, KC_MS_D, KC_MS_D, _____, _____, _____, _____,\
      KC_LCTRL, KC_MOUSE1, _____, KC_BTN3, KC_BTN2, KC_BTN1,        KC_BTN1, KC_BTN2, KC_BTN3, _____, _____, _____\
  ),
  [MOUSE2]=LAYOUT(\
      KC_ESC, KC_ACL0, KC_ACL1, KC_ACL2, _____, _____, _____,       _____, _____, _____, _____, _____, _____, _____, _____,\
      KC_TAB, _____, KC_WH_U, _____, _____, _____, _____,           _____, _____, _____, _____, _____, _____, _____, _____,\
      KC_LCTRL, KC_WH_L, KC_WH_D, KC_WH_R, _____, _____,            KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _____, _____, _____,\
      KC_MOUSE2, _____, _____, _____, _____, _____,                 _____, _____, _____, _____, _____, _____, _____, _____,\
      KC_LCTRL, _____, _____, KC_BTN3, KC_BTN2, KC_BTN1,            KC_BTN1, KC_BTN2, KC_BTN3, _____, _____, _____\
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
