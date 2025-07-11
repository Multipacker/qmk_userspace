// Copyright 2025 Simon Renhult (simon.renhult@hotmail.se)
// SPDX-License-Identifier: MIT

#include QMK_KEYBOARD_H

#include "sendstring_us_international.h"

enum {
    L_Base,
    L_Fun,
    L_Num,
    L_Mouse,
    L_Nav,
    L_Media,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* Base
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │Esc├───┐           ┌───┤Del│
      *           └───┤   ├───┐   ┌───┤Bsp├───┘
      *               └───┤Tab│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [L_Base] = LAYOUT_split_3x6_3(
        XXXXXXX,         KC_Q,         KC_W,         KC_E,              KC_R,              KC_T,                                                               KC_Y,              KC_U,         KC_I,         KC_O,             KC_P, XXXXXXX,
        XXXXXXX, LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D),      LCTL_T(KC_F),              KC_G,                                                               KC_H,      RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L),  RSFT_T(KC_SCLN), XXXXXXX,
        XXXXXXX,         KC_Z,         KC_X,         KC_C,              KC_V,              KC_B,                                                               KC_N,              KC_M,      KC_COMM,       KC_DOT,          KC_SLSH, XXXXXXX,
                                                           LT(L_Nav, KC_ESC), LT(L_Num, KC_SPC), LT(L_Mouse, KC_TAB),          LT(L_Media, KC_ENT), RSFT_T(KC_BSPC), LT(L_Fun, KC_DEL)
    ),

     /* Numbers & symbols
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │MKE│   │   │   │   │       │[{ │7& │8* │9( │-_ │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Sft│GUI│Alt│Ctl│   │       │}] │4$ │5% │6^ │=+ │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │\| │1! │2@ │3# │`~ │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤   │
      *           └───┤Hld├───┐   ┌───┤0) ├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [L_Num] = LAYOUT_split_3x6_3(
        XXXXXXX, QK_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          KC_LBRC,   KC_7, KC_8, KC_9, KC_MINS, XXXXXXX,
        XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,                          KC_RBRC,   KC_4, KC_5, KC_6,  KC_EQL, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          KC_BSLS,   KC_1, KC_2, KC_3, KC_QUOT, XXXXXXX,
                                            _______, XXXXXXX, XXXXXXX,         KC_ENT,    KC_0, KC_GRV
    ),

     /* Mouse
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │MKE│   │   │   │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Sft│GUI│Alt│Ctl│   │       │ ← │ ↓ │ ↑ │ → │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │ ⇐ │ ⇓ │ ⇑ │ ⇒ │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤Mid│
      *           └───┤   ├───┐   ┌───┤Lft├───┘
      *               └───┤Hld│   │Rgt├───┘
      *                   └───┘   └───┘
      */
    [L_Mouse] = LAYOUT_split_3x6_3(
        XXXXXXX, QK_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,                           MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX, XXXXXXX,
                                            XXXXXXX, _______, XXXXXXX,         MS_BTN3, MS_BTN1, MS_BTN2
    ),

     /* Navigation
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │MKE│   │   │   │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Sft│GUI│Alt│Ctl│   │       │ ← │ ↓ │ ↑ │ → │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │Hme│Dwn│Up │End│   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │Hld├───┐           ┌───┤   │
      *           └───┤   ├───┐   ┌───┤   ├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [L_Nav] = LAYOUT_split_3x6_3(
        XXXXXXX, QK_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,                           KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, _______,         XXXXXXX, XXXXXXX, XXXXXXX
    ),

     /* Function
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │F1 │F2 │F3 │F4 │ Å │       │   │   │   │   │MKE│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │F5 │F6 │F7 │F8 │ Ä │       │   │Ctl│Alt│GUI│Sft│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │F9 │F10│F11│F12│ Ö │       │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤Hld│
      *           └───┤   ├───┐   ┌───┤   ├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [L_Fun] = LAYOUT_split_3x6_3(
        XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, US_ARNG,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_MAKE, XXXXXXX,
        XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, US_ADIA,                            XXXXXXX, KC_RCTL, KC_RALT, KC_RGUI, KC_RSFT, XXXXXXX,
        XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, US_ODIA,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, _______
    ),

     /* Meida
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │       │   │   │   │   │MKE│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │Prv│Ply│Nxt│   │       │   │Ctl│Alt│GUI│Sft│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │Vl+│Mut│Vl-│   │       │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤   │
      *           └───┤   ├───┐   ┌───┤   ├───┘
      *               └───┤   │   │Hld├───┘
      *                   └───┘   └───┘
      */
    [L_Media] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_MAKE, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                            XXXXXXX, KC_RCTL, KC_RALT, KC_RGUI, KC_RSFT, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX
    ),
};

