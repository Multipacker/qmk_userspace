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
    L_Sym,
    L_Game,
    L_GameSnd,
};

// NOTE(simon): Make it easier to specify layers.
#define split_layout(                                                                       \
        k00, k01, k02, k03, k04,                 k05, k06, k07, k08, k09,                   \
        k10, k11, k12, k13, k14,                 k15, k16, k17, k18, k19,                   \
        k20, k21, k22, k23, k24,                 k25, k26, k27, k28, k29,                   \
                        t0,  t1,  t2,        t3,  t4,  t5                                   \
    ) LAYOUT_split_3x6_3(                                                                   \
        XXXXXXX, k00, k01, k02, k03, k04,                 k05, k06, k07, k08, k09, XXXXXXX, \
        XXXXXXX, k10, k11, k12, k13, k14,                 k15, k16, k17, k18, k19, XXXXXXX, \
        XXXXXXX, k20, k21, k22, k23, k24,                 k25, k26, k27, k28, k29, XXXXXXX, \
                                 t0,  t1,  t2,        t3,  t4,  t5                          \
    )

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
    [L_Base] = split_layout(
                KC_Q,         KC_W,         KC_E,              KC_R,              KC_T,                                                             KC_Y,              KC_U,         KC_I,         KC_O,             KC_P,
        LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D),      LCTL_T(KC_F),              KC_G,                                                             KC_H,      RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L),  RSFT_T(KC_SCLN),
                KC_Z,         KC_X,         KC_C,              KC_V,              KC_B,                                                             KC_N,              KC_M,      KC_COMM,       KC_DOT,          KC_SLSH,
                                                  LT(L_Nav, KC_ESC), LT(L_Num, KC_SPC), LT(L_Mouse, KC_TAB),          LT(L_Sym, KC_ENT), RSFT_T(KC_BSPC), LT(L_Fun, KC_DEL)
    ),

     /* Numbers & symbols
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │MKE│Gam│   │   │   │       │   │7& │8* │9( │-_ │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Sft│GUI│Alt│Ctl│   │       │   │4$ │5% │6^ │=+ │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │   │1! │2@ │3# │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤   │
      *           └───┤Hld├───┐   ┌───┤0) ├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [L_Num] = split_layout(
        QK_MAKE, TO(L_Game), XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX,    KC_7, KC_8, KC_9, KC_MINS,
        KC_LSFT,    KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,                          XXXXXXX,    KC_4, KC_5, KC_6,  KC_EQL,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX,    KC_1, KC_2, KC_3, XXXXXXX,
                                      XXXXXXX, _______, XXXXXXX,        XXXXXXX,    KC_0, XXXXXXX
    ),

     /* Mouse
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │MKE│Gam│   │   │   │       │   │   │   │   │   │
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
    [L_Mouse] = split_layout(
        QK_MAKE, TO(L_Game), XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT,    KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,                           MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, XXXXXXX,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
                                      XXXXXXX, XXXXXXX, _______,         MS_BTN3, MS_BTN1, MS_BTN2
    ),

     /* Navigation
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │MKE│Gam│   │   │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Sft│GUI│Alt│Ctl│   │       │ ← │ ↓ │ ↑ │ → │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │Hme│Dwn│Up │End│   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │Hld├───┐           ┌───┤Nxt│
      *           └───┤   ├───┐   ┌───┤Ply├───┘
      *               └───┤   │   │Prv├───┘
      *                   └───┘   └───┘
      */
    [L_Nav] = split_layout(
        QK_MAKE, TO(L_Game), XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT,    KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,                           KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
                                      _______, XXXXXXX, XXXXXXX,         KC_MPRV, KC_MPLY, KC_MNXT
    ),

     /* Function
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │F1 │F2 │F3 │F4 │ Å │       │   │   │   │Gam│MKE│
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
    [L_Fun] = split_layout(
          KC_F1,   KC_F2,   KC_F3,   KC_F4, US_ARNG,                            XXXXXXX, XXXXXXX, XXXXXXX, TO(L_Game), QK_MAKE,
          KC_F5,   KC_F6,   KC_F7,   KC_F8, US_ADIA,                            XXXXXXX, KC_RCTL, KC_RALT,    KC_RGUI, KC_RSFT,
          KC_F9,  KC_F10,  KC_F11,  KC_F12, US_ODIA,                            XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX
    ),

     /* Symbols
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ ! │ @ │ # │ $ │ % │       │   │   │   │Gam│MKE│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ ( │ ) │ { │ } │ ^ │       │   │Ctl│Alt│GUI│Sft│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ [ │ ] │   │ * │ & │       │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │`~ ├───┐           ┌───┤   │
      *           └───┤'" ├───┐   ┌───┤   ├───┘
      *               └───┤\| │   │Hld├───┘
      *                   └───┘   └───┘
      */
    [L_Sym] = split_layout(
        KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                            XXXXXXX, XXXXXXX, XXXXXXX, TO(L_Game), QK_MAKE,
        KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_CIRC,                            XXXXXXX, KC_RCTL, KC_RALT,    KC_RGUI, KC_RSFT,
        KC_LBRC, KC_RBRC, XXXXXXX, KC_ASTR, KC_AMPR,                            XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                                    KC_GRV, KC_QUOT, KC_BSLS,          XXXXXXX, XXXXXXX, _______
    ),

     /* Game
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │Esc│ Q │ W │ E │ R │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Sft│ A │ S │ D │ F │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Ctl│ Z │ X │ C │ V │       │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │Tab├───┐           ┌───┤   │
      *           └───┤   ├───┐   ┌───┤   ├───┘
      *               └───┤Ctl│   │Nrm├───┘
      *                   └───┘   └───┘
      */
    [L_Game] = split_layout(
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,                                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,                                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                    KC_TAB,  KC_SPC, LT(L_GameSnd, KC_LCTL),          TG(L_Game), XXXXXXX, XXXXXXX
    ),

     /* Game second
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │   │ 7 │ 8 │ 9 │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │ 4 │ 5 │ 6 │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │ 1 │ 2 │ 3 │   │       │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤   │
      *           └───┤   ├───┐   ┌───┤   ├───┘
      *               └───┤Hld│   │   ├───┘
      *                   └───┘   └───┘
      */
    [L_GameSnd] = split_layout(
        XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, _______,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

