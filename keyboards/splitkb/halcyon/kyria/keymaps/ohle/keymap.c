// Copyright 2024 ohle
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "hlc_tft_display/hlc_tft_display.h"
#include "graphics/fonts/unifont_80.qff.h"

#ifdef HLC_TFT_DISPLAY
// Fonts mono2
#include "hlc_tft_display/graphics/fonts/Retron2000-27.qff.h"
#include "hlc_tft_display/graphics/fonts/Retron2000-underline-27.qff.h"

static const char *caps =        "Caps";
static const char *num =         "Num";
static const char *scroll =      "Scroll";

static painter_font_handle_t Retron27;
static painter_font_handle_t Retron27_underline;
static painter_font_handle_t unifont_80;

static led_t last_led_usb_state = {0};
static layer_state_t last_layer_state = {0};
#endif

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

enum custom_keycodes {
    AE = QK_KB_0, OE, UE,
    SZET,
    RIGHT, LEFT, UP, DOWN,
    COPYRIGHT,
    EN_DASH, EM_DASH, ELLIPSIS,
    EURO,
    CHECK,
    MU, PI,
    SQUARED, CUBED
};

enum unicode_names {
    AE_LOWER_U, AE_UPPER_U, OE_LOWER_U, OE_UPPER_U, UE_LOWER_U, UE_UPPER_U,
    SZET_U,
    RIGHT_U, LEFT_U, UP_U, DOWN_U,
    COPYRIGHT_U,
    EN_DASH_U, EM_DASH_U, ELLIPSIS_U,
    EURO_U,
    CHECK_U,
    MU_U, PI_U,
    SQUARED_U, CUBED_U
};

const uint32_t PROGMEM unicode_map[] = {
    [AE_LOWER_U]  = 0x00e4,
    [AE_UPPER_U]  = 0x00c4,
    [OE_LOWER_U]  = 0x00f6,
    [OE_UPPER_U]  = 0x00d6,
    [UE_LOWER_U]  = 0x00fc,
    [UE_UPPER_U]  = 0x00dc,
    [SZET_U]      = 0x00df,
    [RIGHT_U]     = 0x2192,
    [LEFT_U]      = 0x2190,
    [UP_U]        = 0x2191,
    [DOWN_U]      = 0x2193,
    [COPYRIGHT_U] = 0x00a9,
    [EN_DASH_U]   = 0x2013,
    [EM_DASH_U]   = 0x2014,
    [ELLIPSIS_U]  = 0x2026,
    [EURO_U]      = 0x20ac,
    [CHECK_U]     = 0x2713,
    [MU_U]        = 0x03bc,
    [PI_U]        = 0x03c0,
    [SQUARED_U]   = 0x00b2,
    [CUBED_U]     = 0x00b3,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        bool shifted = (get_mods() | get_oneshot_mods() | get_weak_mods()) & MOD_MASK_SHIFT;

        switch (keycode) {
            case AE:
                register_unicodemap(shifted ? AE_UPPER_U : AE_LOWER_U);
                return false;
            case OE:
                register_unicodemap(shifted ? OE_UPPER_U : OE_LOWER_U);
                return false;
            case UE:
                register_unicodemap(shifted ? UE_UPPER_U : UE_LOWER_U);
                return false;
            case SZET:
                register_unicodemap(SZET_U);
                return false;
            case RIGHT:
                register_unicodemap(RIGHT_U);
                return false;
            case LEFT:
                register_unicodemap(LEFT_U);
                return false;
            case UP:
                register_unicodemap(UP_U);
                return false;
            case DOWN:
                register_unicodemap(DOWN_U);
                return false;
            case COPYRIGHT:
                register_unicodemap(COPYRIGHT_U);
                return false;
            case EN_DASH:
                register_unicodemap(EN_DASH_U);
                return false;
            case EM_DASH:
                register_unicodemap(EM_DASH_U);
                return false;
            case ELLIPSIS:
                register_unicodemap(ELLIPSIS_U);
                return false;
            case EURO:
                register_unicodemap(EURO_U);
                return false;
            case CHECK:
                register_unicodemap(CHECK_U);
                return false;
            case MU:
                register_unicodemap(MU_U);
                return false;
            case PI:
                register_unicodemap(PI_U);
                return false;
            case SQUARED:
                register_unicodemap(SQUARED_U);
                return false;
            case CUBED:
                register_unicodemap(CUBED_U);
                return false;
        }
    }
    return true;
}

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

#ifdef HLC_TFT_DISPLAY
bool display_module_housekeeping_task_user(bool second_display) {
    static bool first_run_led = false;
    static bool first_run_layer = false;

    if( first_run_layer == false) {
        // Load fonts
        Retron27 = qp_load_font_mem(font_Retron2000_27);
        Retron27_underline = qp_load_font_mem(font_Retron2000_underline_27);
        unifont_80 = qp_load_font_mem(font_unifont_80);
    }

    if(last_led_usb_state.raw != host_keyboard_led_state().raw || first_run_led == false) {
        led_t led_usb_state = host_keyboard_led_state();

        led_usb_state.caps_lock   ? qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 3 - 15, Retron27_underline, caps,   HSV_CAPS_ON,   HSV_BLACK) : qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 3 - 15, Retron27, caps,   HSV_CAPS_OFF,   HSV_BLACK);
        led_usb_state.num_lock    ? qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 2 - 10, Retron27_underline, num,    HSV_NUM_ON,    HSV_BLACK) : qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 2 - 10, Retron27, num,    HSV_NUM_OFF,    HSV_BLACK);
        led_usb_state.scroll_lock ? qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height - 5,      Retron27_underline, scroll, HSV_SCROLL_ON, HSV_BLACK) : qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height - 5,      Retron27, scroll, HSV_SCROLL_OFF, HSV_BLACK);

        last_led_usb_state = led_usb_state;
        first_run_led = true;
    }

    if(last_layer_state != layer_state || first_run_layer == false) {
        switch (get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            qp_drawtext_recolor(lcd_surface, 5, 5, unifont_80, "a", HSV_LAYER_0 , HSV_BLACK);
            break;
        case 1:
            qp_drawtext_recolor(lcd_surface, 5, 5, unifont_80, "1", HSV_LAYER_1 , HSV_BLACK);
            break;
        case 2:
            qp_drawtext_recolor(lcd_surface, 5, 5, unifont_80, "&", HSV_LAYER_2 , HSV_BLACK);
            break;
        case 3:
            qp_drawtext_recolor(lcd_surface, 5, 5, unifont_80, "F", HSV_LAYER_3 , HSV_BLACK);
            break;
        case 4:
            qp_drawtext_recolor(lcd_surface, 5, 5, unifont_80, "↕", HSV_LAYER_4 , HSV_BLACK);
            break;
        case 5:
            qp_drawtext_recolor(lcd_surface, 5, 5, unifont_80, "@", HSV_LAYER_5 , HSV_BLACK);
            break;
        case 6:
            qp_drawtext_recolor(lcd_surface, 5, 5, unifont_80, "#", HSV_LAYER_6 , HSV_BLACK);
            break;
        case 7:
            qp_drawtext_recolor(lcd_surface, 5, 5, unifont_80, "#", HSV_LAYER_6 , HSV_BLACK);
            break;
        default:
            qp_drawtext_recolor(lcd_surface, 5, 5, unifont_80, "a", HSV_LAYER_0 , HSV_BLACK);
        }
        last_layer_state = layer_state;
        first_run_layer = true;
    }
    // Move surface to lcd
    qp_surface_draw(lcd_surface, lcd, 0, 0, 0);
    qp_flush(lcd);

    // Return false on the main display so the module's default numeric layer
    // renderer does not run and overwrite these custom glyphs.
    return second_display;
}
#endif
