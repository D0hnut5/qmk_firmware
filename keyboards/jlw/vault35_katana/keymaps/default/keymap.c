// Copyright 2023 jlw
// SPDX-License-Identifier: GPL-2.0-or-later


#include QMK_KEYBOARD_H

/*** Home Row Mods ***/

#define S_ALT LALT_T(KC_S)
#define D_CTL LCTL_T(KC_D)
#define F_SFT LSFT_T(KC_F)
#define J_SFT RSFT_T(KC_J)
#define K_CTL RCTL_T(KC_K)
#define L_ALT RALT_T(KC_L)
#define L_SPC LT(1, KC_BSPC)
#define R_SPC LT(2, KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_6bars(
         KC_Q,      KC_W,   KC_E,       KC_R,       KC_T,                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
         KC_A,      S_ALT,  D_CTL,      F_SFT,      KC_G,                   KC_H,       J_SFT,      K_CTL,      L_ALT,      KC_ENTER,
         KC_Z,      KC_X,   KC_C,       KC_V,       KC_B,       KC_MUTE,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,
                            KC_LCTL,    KC_LGUI,    L_SPC,                  R_SPC,      MO(3),      MO(4)
    ),

    [1] = LAYOUT_split_6bars(
         KC_EXLM,   KC_AT,  KC_HASH,    KC_DLR,     KC_PERC,                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,
         KC_1,      KC_2,   KC_3,       KC_4,       KC_5,                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
         KC_TRNS,   KC_GRV, KC_LBRC,    KC_RBRC,    KC_BSLS,    RGB_TOG,    KC_MINS,    KC_EQL,     KC_SCLN,    KC_QUOT,    KC_QUES,
                            RGB_HUD,    RGB_HUI,    KC_TRNS,                KC_PSCR,    RGB_MOD,    RGB_RMOD
    ),

    [2] = LAYOUT_split_6bars(
         _______,  _______,  _______,   _______,    _______,                _______,    KC_HOME,    KC_UP,      KC_END,     KC_PGUP,
         _______,  KC_LALT,  KC_LCTL,   KC_LSFT,    _______,                _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_PGDN,
         _______,  _______,  _______,   _______,    _______,   RGB_TOG,     _______,    _______,    _______,    _______,    _______,
                             RGB_SPD,   RGB_SPI,    KC_DEL,                 KC_TRNS,    RGB_VAD,    RGB_VAI
    ),

    [3] = LAYOUT_split_6bars(
         _______,  KC_ACL2,  KC_ACL1,   KC_ACL0,    _______,                _______,      KC_NO,    KC_MS_U,      KC_NO,      KC_NO,
         _______,  _______,  KC_BTN2,   KC_BTN1,    _______,                _______,    KC_MS_L,    KC_MS_D,    KC_MS_R,      KC_NO,
         _______,  _______,  _______,   _______,    _______,   RGB_TOG,     _______,    _______,    _______,    _______,    _______,
                             _______,   _______,    _______,                _______,    KC_TRNS,    _______
    ),

    [4] = LAYOUT_split_6bars(
         _______,  _______,  _______,   _______,    _______,                _______,    KC_HOME,    KC_UP,      KC_END,     KC_PGUP,
         _______,  KC_LALT,  KC_LCTL,   KC_LSFT,    _______,                _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_PGDN,
          QK_RBT,  _______,  _______,   _______,    _______,   KC_TRNS,     _______,    _______,    _______,    _______,    _______,
                             _______,   _______,    _______,                _______,    _______,    KC_TRNS
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [2] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [3] =   { ENCODER_CCW_CW(RGB_SPD, RGB_SPI) },
    [4] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif

/*#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case F_SFT:
            // Immediately select the hold action when another key is tapped.
            return true;
        case J_SFT:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
#endif*/

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case F_SFT:
            return 120;
        case J_SFT:
            return 120;
        default:
            return TAPPING_TERM;
    }
}
#endif

#ifdef COMBO_ENABLE
enum combos {
     QW_ESC,
     DF_TAB,
     JK_BACK,
     FJ_CAPS,
     QPZ_BOOT
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM df_combo[] = {D_CTL, F_SFT, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {J_SFT, K_CTL, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {F_SFT, J_SFT , COMBO_END};
const uint16_t PROGMEM qpz_combo[] = {KC_Q, KC_P, KC_Z, KC_SLSH, COMBO_END};

combo_t key_combos[] = {
    [QW_ESC] = COMBO(qw_combo, KC_ESC),
    [DF_TAB] = COMBO(df_combo, KC_TAB),
    [JK_BACK] = COMBO(jk_combo, RCTL(KC_BSPC)),
    [FJ_CAPS] = COMBO(fj_combo, KC_CAPS),
    [QPZ_BOOT] = COMBO(qpz_combo, QK_BOOT),
};
#endif