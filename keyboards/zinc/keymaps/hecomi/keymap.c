#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FN,
    _MOUSE,
    _SCROLL,
};

enum custom_keycodes {
  BACKLIT = SAFE_RANGE,
  KANA,
  EISU,
  RGBRST,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)
#define KC_MOUS MO(_MOUSE)
#define KC_SCRL MO(_SCROLL)
#define KC_FN   MO(_FN)
#define KC_LOWR LT(_LOWER, KC_ESC)
#define KC_RAIS LT(_RAISE, KC_BSPC)
#define KC_AJST LT(_ADJUST, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
[_QWERTY] = LAYOUT_ortho_4x12(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_FN, \
      KC_AJST, KC_MOUS, KC_LALT, KC_LGUI, KC_LOWR, KC_SPC,                    KC_ENT,  KC_RAIS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

[_LOWER] = LAYOUT_ortho_4x12( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_HOME, KC_END,  _______, \
      _______, _______, _______, _______, _______, _______,                   _______, KC_AJST, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

[_RAISE] = LAYOUT_ortho_4x12( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
      KC_LCTL, _______, _______, _______, _______, _______,                   KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV, \
      KC_LSFT, _______, _______, _______, _______, _______,                   KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD, \
      _______, _______, _______, _______, KC_AJST, _______,                   _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

[_ADJUST] = LAYOUT_ortho_4x12( \
      RESET,   RGBRST,  _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, AG_NORM,                   _______, _______, _______, KC_PSCR, _______, _______, \
      _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______,    EISU,                   KANA,    _______, _______, _______, _______, _______ \
      ),

[_FN] = LAYOUT_ortho_4x12( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_PSCR, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______ \
      ),

[_MOUSE] = LAYOUT_ortho_4x12( \
      _______, _______, KC_MS_U, _______, _______, _______,                   KC_MS_U, KC_MS_U, KC_MS_U, KC_MS_U, _______, _______, \
      _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
      KC_SCRL, _______, _______, _______, _______, _______,                   KC_MS_D, KC_MS_D, KC_MS_D, KC_MS_D, _______, _______, \
      _______, _______, _______, _______, KC_BTN2, KC_BTN1,                   KC_BTN1, KC_BTN2, _______, _______, _______, _______ \
      ),

[_SCROLL] = LAYOUT_ortho_4x12( \
      _______, _______, KC_WH_U, _______, _______, _______,                   KC_WH_U, KC_WH_U, KC_WH_U, KC_WH_U, _______, _______, \
      _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,                   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, \
      _______, _______, _______, _______, _______, _______,                   KC_WH_D, KC_WH_D, KC_WH_D, KC_WH_D, _______, _______, \
      _______, _______, _______, _______, KC_BTN2, KC_BTN1,                   KC_BTN1, KC_BTN2, _______, _______, _______, _______ \
      )
};

// define variables for reactive RGB
bool TOG_STATUS = false;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_mode_noeeprom(RGB_current_config.mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode_noeeprom(RGB_current_config.mode);
          rgblight_step();
          RGB_current_config.mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG1);
        }else{
         SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_config = rgblight_config;
        }
      #endif
      break;
  }
  return true;
}


void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_init();
      RGB_current_config = rgblight_config;
    #endif
}


