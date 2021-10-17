#include QMK_KEYBOARD_H


#ifdef OLED_ENABLE
#include <stdio.h>

char     wpm_str[10];

#endif


enum layer_number {
  _DVORAK = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _DRAW,
  // _QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | DRL  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   ;  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------| DRAW   |    |   ]   |------+------+------+------+------+------|
 * |LShift|   '  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTRL| LAlt |LGUI  | /Space  /       \Enter \  |RAISE |BackSP| LOWER |
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''---------------------'
 */
 [_DVORAK] = LAYOUT( \
  KC_DLR,      KC_1,     KC_2,       KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_GRV, \
  KC_TAB,   KC_SCLN,   KC_COMM,    KC_DOT,    KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,     KC_SLSH, \
  KC_ESC,   LGUI_T(KC_A), LALT_T(KC_O), LSFT_T(KC_E), LCTL_T(KC_U),    KC_I,   KC_D,    RCTL_T(KC_H),    RSFT_T(KC_T),    RALT_T(KC_N),    RGUI_T(KC_S),     KC_MINS, \
  KC_LSFT,  KC_QUOT,     KC_Q,       KC_J,    KC_K,    KC_X, TG(_DRAW),  KC_RBRC,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,     KC_RSFT, \
                                 MO(_LOWER), KC_LALT, MO(_RAISE), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, MO(_LOWER)  \
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   %  |   7  |   5  |  3   |   1  |   9  |                    |   0  |   2  |   4  |   6  |   8  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   &  |   [  |   {  |   }  |   (  |   =  |-------.    ,-------|   *  |   )  |   +  |   ]  |   !  |  #   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      | TILD |      |      |   |  |   \  |-------|    |-------|   @  |   ^  |   $  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTRL| LAlt |LGUI  | /Space  /       \Enter \  |RAISE |BackSP| LOWER |
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''---------------------'
 *
 *
 *                   
 */
[_RAISE] = LAYOUT( \
  KC_F1,   KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_PERC, LGUI_T(KC_7), LALT_T(KC_5), LSFT_T(KC_3), LCTL_T(KC_1), KC_9,         KC_0,    RCTL_T(KC_2),    RSFT_T(KC_4),    RALT_T(KC_6),    RGUI_T(KC_8),    KC_GRV,\
  KC_AMPR, KC_LBRC,      KC_LCBR, KC_RCBR, KC_LPRN, KC_EQL,                      KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM, KC_HASH, \
  _______, KC_TILD, _______, _______, KC_PIPE, KC_BSLS,  _______,   _______,     KC_AT, KC_CIRC, KC_DLR, _______, _______, _______, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTRL| LAlt |LGUI  | /Space  /       \Enter \  |RAISE |BackSP| LOWER |
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''---------------------'
 */

[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  KC_F1,   LGUI_T(KC_F2),    LALT_T(KC_F3),    LSFT_T(KC_F4),   LCTL_T(KC_F5),   KC_F6,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  ),

  [_DRAW] = LAYOUT(
  KC_DLR,     KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_GRV, \
  XXXXXXX,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, KC_BSPC, _______, _______, _______,  _______, _______, _______
  )


  /* QWERTY - TODO make mode change from adjust
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
   * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */

   /* [_QWERTY] = LAYOUT( \
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
    KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                          KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RGUI \
  ), */
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

const char *read_logo(void);

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("NIX"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        /* case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break; */
        case _DVORAK:
            oled_write_ln_P(PSTR("DVP"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
        // case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _DRAW:
            oled_write_P(PSTR("Draw\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    sprintf(wpm_str, "WPM: %03d", get_current_wpm());
    oled_write_ln(wpm_str, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) return OLED_ROTATION_270;
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    // set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
