// Copyright 2024 ohle
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_5_hlc(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
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
