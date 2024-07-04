/*
Copyright 2020 Seth Lienemann <sethlienemann@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"
//#define PRODUCT         Dactyl Ergo(6x6)

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 8

// wiring of each half

#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, B6 }
#define MATRIX_ROW_PINS { B7, C7, F1, F0 }

//TODO: Is this actually correct?
#define DIODE_DIRECTION COL2ROW

/* USB Device descriptor parameter */
#define VENDOR_ID       0x03eb
#define PRODUCT_ID      0x2ff4
#define DEVICE_VER      0x0001

#define DESCRIPTION     A split keyboard

/* mouse config */
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY    0

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD

/* ws2812 RGB LED */
//#define RGB_DI_PIN D3

//#define RGBLED_NUM 12    // Number of LEDs
