#include QMK_KEYBOARD_H

#define _QW 0
#define _RS 1
#define _LW 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = LAYOUT( /* Qwerty */
  KC_Q,          KC_W,    KC_E,    KC_R,         KC_T,                      KC_Y,   KC_U,         KC_I,    KC_O,    KC_P,
  KC_A,          KC_S,    KC_D,    KC_F,         KC_G,                      KC_H,   KC_J,         KC_K,    KC_L,    KC_SCLN,
  LSFT(KC_Z),    KC_X,    KC_C,    KC_V,         KC_B,    MO(_LW), MO(_RS), KC_N,   KC_M,         KC_COMM, KC_DOT,  RSFT(KC_SLSH),
	LCTL(KC_GRAV), KC_MIN,  KC_EQL,  LGUI(KC_TAB), KC_BSPC, KC_DEL,  KC_ENT,  KC_SPC, LALT(KC_TAB), KC_BSLS, KC_QUOT, RCTL(KC_ESC)
  ), 
[_RS] = LAYOUT( /* [> RAISE <] */
  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,                      KC_6,    KC_7,     KC_8,    KC_9,     KC_0,
  KC_BSLS, KC_GRV,  XXXXXXX, XXXXXXX,  XXXXXXX,                   KC_LBRC, XXXXXXX,  XXXXXXX, XXXXXXX, KC_RBRC,
  KC_EQL,  XXXXXXX, KC_VOLD, KC_VOLU,  XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,  XXXXXXX, KC_QUOT, KC_MINS,
  KC_LCTL, XXXXXXX, KC_MPRV, KC_MNXT,  KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT
  ),
[_LW] = LAYOUT( /* [> LOWER <] */
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_PIPE, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCBR,
  KC_PLUS, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UND,
  QK_BOOT, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
  )
};

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
