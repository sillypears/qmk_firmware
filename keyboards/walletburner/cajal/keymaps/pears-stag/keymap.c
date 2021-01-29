/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base Layer
   * .-----------------------------------------------------------------------------.   .-------.
   * | GRV | Q   | W   | E   | R   | T   | Y   | U   | I   | O   | P   | [{  | BKSP|   |RGB TOG|
   * |-----------------------------------------------------------------------------|   '-------'
   * | LCTL  | A   | S   | D   | F   | G   | H   | J   | K   | L   | ;   |  ENTER  |
   * |-----------------------------------------------------------------------------'  .------.
   * | LSHIFT | Z   | X    | C   | V   | B   | N   | M   | ,<  | .>  | RSHFT  |       | UP   |
   * |-----------------------------------------------------------------------' .------|------|-----.
   * | TAB  | LWIN | LALT | MO(1)     | SPACE       | MO(2)    | RCTL    |     | LF   | DN   | RT  |
   * '-------------------------------------------------------------------'     '-------------------'
   */
    [0] = LAYOUT_stagger(
        KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_BSPC, RGB_TOG,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_LSFT, KC_UP,
        KC_TAB, KC_LGUI, KC_LALT, MO(1), KC_SPC, MO(2), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
  /* First Layer
   * .-----------------------------------------------------------------------------.   .-------.
   * |     | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 0   | ]}  | \|  |   |RGB MOD|
   * |-----------------------------------------------------------------------------|   '-------'
   * |      | -  | =   | [  | ]  | \  | LEFT  | DOWN | UP  | RGHT | '   |  ENTER   |
   * |-----------------------------------------------------------------------------'   .------.
   * |       |     |      |     |   |     |     |     | PRSC  |  /    |       |        | PGUP |
   * |-----------------------------------------------------------------------'  .------|------|-----.
   * |      |     |      |           |                  |       | MO(3)  |      | HOME | PGDN | END |
   * '-------------------------------------------------------------------'      '-------------------'
   */
    [1] = LAYOUT_stagger(
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRC, KC_BSLS, RGB_MOD,
        KC_TRNS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLSH, KC_TRNS, KC_PGUP,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, MO(3),  KC_HOME, KC_PGDN, KC_END
    ),
  /* Second Layer
   * .-----------------------------------------------------------------------------.   .-------.
   * | ~   | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |   |       |
   * |-----------------------------------------------------------------------------|   '-------'
   * |      |     |     |    |    |     |      |      |     |      |     |         |
   * |-----------------------------------------------------------------------------'   .------.
   * |       |     |      |     |   |     |     |     | SAD   | SAI  |       |         | VAI  |
   * |-----------------------------------------------------------------------'  .------|------|-----.
   * |      |     |      | MO(3)     |                  |       |        |      | HUD  | VAD  | HUI |
   * '-------------------------------------------------------------------'      '-------------------'
   */
    [2] = LAYOUT_stagger(
        KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAD, RGB_SAI, KC_TRNS, RGB_VAI,
        KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUD, RGB_VAD, RGB_HUI
    ),
  /* Third Layer
   * .-----------------------------------------------------------------------------.   .-------.
   * |     |     |     |     |     |     |     |     |     |     |     |     |     |   | RESET |
   * |-----------------------------------------------------------------------------|   '-------'
   * |      |     |     |    |    |     |      |      |     |      |     |         |
   * |-----------------------------------------------------------------------------'   .------.
   * |       |     |      |     |   |     |     |     |       |      |       |         |      |
   * |-----------------------------------------------------------------------'  .------|------|-----.
   * |      |     |      |           |                  |       |        |      |      |      |     |
   * '-------------------------------------------------------------------'      '-------------------'
   */
    [3] = LAYOUT_stagger(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        writePinHigh(B7);
        writePinLow(B6);
        break;
    case 2:
        writePinLow(B7);
        writePinHigh(B6);
        break;
    case 3:
        writePinHigh(B7);
        writePinHigh(B6);
        break;
    default:
        writePinLow(B7);
        writePinLow(B6);
        break;
    }
    return state;
}

bool led_update_user(led_t led_state) {
    writePin(B5, led_state.caps_lock);
    return false;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}

