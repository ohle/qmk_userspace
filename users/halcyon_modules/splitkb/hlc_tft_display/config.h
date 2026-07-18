// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

// Any QMK options should go here

#pragma once

#define HLC_TFT_DISPLAY

// LCD Configuration
#define LCD_RST_PIN GP26
#define LCD_CS_PIN GP13
#define LCD_DC_PIN GP16
#define LCD_SPI_DIVISOR 0
#define LCD_SPI_MODE 3
#define LCD_WIDTH 135
#define LCD_HEIGHT 240
#define LCD_ROTATION QP_ROTATION_0
#define LCD_OFFSET_X 52
#define LCD_OFFSET_Y 40

// QP Configuration
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
#define ST7789_NO_AUTOMATIC_VIEWPORT_OFFSETS
#define ST7789_NUM_DEVICES 1

#define SURFACE_NUM_DEVICES 1

// Backlight configuration
#undef BACKLIGHT_PIN
#define BACKLIGHT_PIN GP27

// Timeout configuration
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT HLC_BACKLIGHT_TIMEOUT

// All values (including hue) are scaled to 0-255
#define HSV_SPLITKB 145, 235, 155
#define HSV_CAPS_OFF 17, 104, 77
#define HSV_CAPS_ON 17, 191, 245
#define HSV_SCROLL_OFF 202, 104, 77
#define HSV_SCROLL_ON 202, 191, 245
#define HSV_NUM_OFF 142, 104, 77
#define HSV_NUM_ON 142, 191, 245

#define HSV_LAYER_0 0, 0, 160
#define HSV_LAYER_3 0, 82, 255
#define HSV_LAYER_1 23, 89, 255
#define HSV_LAYER_2 43, 71, 255
#define HSV_LAYER_4 77, 64, 255
#define HSV_LAYER_6 131, 99, 255
#define HSV_LAYER_7 154, 94, 255
#define HSV_LAYER_5 176, 77, 255
// #define HSV_LAYER_8 213, 56, 255
#define HSV_LAYER_UNDEF 0, 255, 255