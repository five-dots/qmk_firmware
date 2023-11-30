/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define TAPPING_TERM 200 // default 200

// TAPPING_TERM 経過前に他のキーを押すと、Hold として扱われるようになる
#define PERMISSIVE_HOLD

// TAPPING_TERM を経過しても、他のキーを押していなければ Tap として扱われるようになる
// TAPPING_TERM が短くて Tap のつもりが Hold 扱いになってしまう場合の対策になる
#define RETRO_TAPPING

// Mod Tap key を Tap 後にすぐに Hold したときに、Hold として扱われるようになる
#define TAPPING_FORCE_HOLD

// Mod Tap key と通常キーを連続して高速に押したとき、両方のキーを Tap として扱うようになる
/* #define IGNORE_MOD_TAP_INTERRUPT */

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

// Underglow
/*
#undef RGBLED_NUM
#define RGBLED_NUM 14    // Number of LEDs
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
*/
