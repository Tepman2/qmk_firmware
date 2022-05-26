#include QMK_KEYBOARD_H
#include "config.h"
#include "debug.h"

// Helpful defines
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Each layer gets a name for readability.
// The underscores don't mean anything - you can
// have a layer called STUFF or any other name.
// Layer names don't all need to be of the same
// length, and you can also skip them entirely
// and just use numbers.

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap _QWERTY: Base Layer (Default Layer)
 *
 * ,-----------------------------------------.                                 ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                 |   Y  |   U  |   I  |   O  |   P  | BckSp|
 * |------+------+------+------+------+------|                                 |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |                                 |   H  |   J  |   K  |   L  |   ;  | '    |
 * |------+------+------+------+------+------|                                 |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |                                 |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+-------------.    ,--------------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  | Raise| Space| Meh  | Hyper|    | Hyper| Meh   | Space| Lower| Left | Down | Up   | Right|
 * `-------------------------------------------------------'    `--------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,\
 KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,\
 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,\
 KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,  KC_SPC, OS_MEH, OS_HYPR,    OS_HYPR, OS_MEH,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Lower
 * ,-----------------------------------------.                                ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |                                |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |                                |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |                                |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+-------------.    ,-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |    |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-------------------------------------------------------'    `-------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
 KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                        KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,\
 KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,\
 _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                                         KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,\
 _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),
/* Raise
 * ,-----------------------------------------.                                ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                                |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |                                |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |                                |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------.    ,-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |    |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-------------------------------------------------------'    `-------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
 KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,\
 KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,\
 _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                                         KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,\
 _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
    default:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
        }
        return false;
        break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
}
