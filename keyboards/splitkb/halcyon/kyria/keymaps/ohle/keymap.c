// Copyright 2024 ohle
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK_DH,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_5_hlc(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        CTL_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                                    KC_H, KC_J, KC_K, KC_L, KC_SCLN, CTL_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_CAPS, FKEYS, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                ADJUST, KC_LGUI, ALT_ENT, KC_SPC, NAV,            SYM, KC_SPC, KC_RALT, KC_RGUI, KC_APP,
        KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,                                                      KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_DVORAK] = LAYOUT_split_3x6_5_hlc(
        KC_TAB, KC_QUOTE, KC_COMM, KC_DOT, KC_P, KC_Y,                            KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC,
        CTL_ESC, KC_A, KC_O, KC_E, KC_U, KC_I,                                    KC_D, KC_H, KC_T, KC_N, KC_S, CTL_MINS,
        KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_LBRC, KC_CAPS, FKEYS, KC_RBRC, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT,
                                 ADJUST, KC_LGUI, ALT_ENT, KC_SPC, NAV,           SYM, KC_SPC, KC_RALT, KC_RGUI, KC_APP,
        KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,                                                      KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_COLEMAK_DH] = LAYOUT_split_3x6_5_hlc(
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B,                                     KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
        CTL_ESC, KC_A, KC_R, KC_S, KC_T, KC_G,                                    KC_M, KC_N, KC_E, KC_I, KC_O, CTL_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_LBRC, KC_CAPS, FKEYS, KC_RBRC, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                 ADJUST, KC_LGUI, ALT_ENT, KC_SPC, NAV,           SYM, KC_SPC, KC_RALT, KC_RGUI, KC_APP,
        KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,                                                      KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_NAV] = LAYOUT_split_3x6_5_hlc(
        _______, _______, _______, _______, _______, _______,                                       KC_PGUP, KC_HOME, KC_UP, KC_END, KC_VOLU, KC_DEL,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
        _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______, KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                                   _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT_split_3x6_5_hlc(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                                 KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        KC_PIPE, KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM, KC_DOT, KC_SLSH, KC_QUES,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                               _______, _______, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT_split_3x6_5_hlc(
        _______, KC_F9, KC_F10, KC_F11, KC_F12, _______,                                   _______, _______, _______, _______, _______, _______,
        _______, KC_F5, KC_F6, KC_F7, KC_F8, _______,                                      _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
        _______, KC_F1, KC_F2, KC_F3, KC_F4, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                         _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_split_3x6_5_hlc(
        _______, _______, _______, QWERTY, _______, _______,                                _______, _______, _______, _______, _______, _______,
        _______, _______, _______, DVORAK, _______, _______,                                RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT, _______,
        _______, _______, _______, COLEMAK, _______, _______, _______, _______, _______, _______, _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                         _______, _______, _______, _______, _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [4] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [5] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [6] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif
// clang-format on

// Solarized palette: layer 0 = off, layers 1-5 = blue/cyan/orange/green/violet
static const uint8_t PROGMEM layer_colors[][3] = {
    {  0,   0,   0},  // layer 0: off
    { 38, 139, 210},  // layer 1: Solarized blue   (#268BD2)
    { 42, 161, 152},  // layer 2: Solarized cyan   (#2AA198)
    {203,  75,  22},  // layer 3: Solarized orange (#CB4B16)
    {133, 153,   0},  // layer 4: Solarized green  (#859900)
    {108, 113, 196},  // layer 5: Solarized violet (#6C71C4)
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    if (layer >= ARRAY_SIZE(layer_colors)) {
        return false;
    }

    uint8_t r = pgm_read_byte(&layer_colors[layer][0]);
    uint8_t g = pgm_read_byte(&layer_colors[layer][1]);
    uint8_t b = pgm_read_byte(&layer_colors[layer][2]);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, r, g, b);
    }

    return false;
}
