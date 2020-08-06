/* Copyright 2019-2020 DMQ Design
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
#include "midi.h"
#include "qmk_midi.h"

enum layers
{
  _BL,
  _FL,
  _TL
};

uint8_t currentLayer;

//The below layers are intentionally empty in order to give a good starting point for how to configure multiple layers.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(/* Base */
                KC_KP_7, KC_KP_8, KC_KP_9, TO(_BL),
                KC_KP_4, KC_KP_5, KC_KP_6, TO(_FL),
                KC_KP_1, KC_KP_2, KC_KP_3, TO(_TL),
                KC_KP_0, KC_PDOT, KC_PENT
                ),

    [_FL] = LAYOUT(/* Base */
                KC_NO, KC_NO, KC_NO, KC_TRNS,
                KC_NO, KC_NO, KC_NO, KC_TRNS,
                KC_NO, KC_NO, KC_NO, KC_TRNS,
                KC_MS_BTN1, KC_NO, KC_MS_BTN2
                ),

    [_TL] = LAYOUT(/* Base */
                KC_NO, KC_NO, KC_NO, KC_TRNS,
                KC_NO, KC_NO, KC_NO, KC_TRNS,
                KC_NO, KC_NO, KC_NO, KC_TRNS,
                KC_NO, KC_NO, KC_NO
                )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch (currentLayer) {     //break each encoder update into a switch statement for the current layer
            case _BL:
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
                break;
            case _FL:
                if (clockwise) {
                    // tap
                    // midi_send_cc(&midi_device, 0, 0x14, 1);
                } else {
                    // midi_send_cc(&midi_device, 0, 0x15, 1);
                }
                break;
            case _TL:
                if (clockwise) {
                    // midi_send_cc(&midi_device, 0, 0x1A, 1);
                } else {
                    // midi_send_cc(&midi_device, 0, 0x1B, 1);
                }
                break;
        }
    } else if (index == 1) { /* Second encoder */
        switch (currentLayer) {
            case _BL:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _FL:
                if (clockwise) {
                    // midi_send_cc(&midi_device, 0, 0x16, 1);
                } else {
                    // midi_send_cc(&midi_device, 0, 0x17, 1);
                }
                break;
            case _TL:
                if (clockwise) {
                    // midi_send_cc(&midi_device, 0, 0x1C, 1);
                } else {
                    // midi_send_cc(&midi_device, 0, 0x1D, 1);
                }
                break;
        }
    } else if (index == 2) { /* Third encoder */
        switch (currentLayer) {
            case _BL:
                if (clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
                }
                break;
            case _FL:
                if (clockwise) {
                    // midi_send_cc(&midi_device, 0, 0x18, 1);
                } else {
                    // midi_send_cc(&midi_device, 0, 0x19, 1);
                }
                break;
            case _TL:
                if (clockwise) {
                    // midi_send_cc(&midi_device, 0, 0x1E, 1);
                } else {
                    // midi_send_cc(&midi_device, 0, 0x1F, 1);
                }
                break;
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state) { //This will run every time the layer is updated
    currentLayer = get_highest_layer(state);

    switch (currentLayer) {
        case _BL:
            setrgb(RGB_WHITE, &led[0]); //Set the top LED to white for the bottom layer
            setrgb(0, 0, 0, &led[1]);
            setrgb(0, 0, 0, &led[2]);
            break;
        case _FL:
            setrgb(0, 0, 0, &led[0]); //Set the middle LED to white for the middle layer
            setrgb(RGB_WHITE, &led[1]);
            setrgb(0, 0, 0, &led[2]);
            break;
        case _TL:
            setrgb(0, 0, 0, &led[0]);
            setrgb(0, 0, 0, &led[1]);
            setrgb(RGB_WHITE, &led[2]); //Set the bottom LED to white for the top layer
            break;
    }
    rgblight_set();
    return state;
}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // OLED Rotation enum values are flags
    // typedef enum {
    //     OLED_ROTATION_0   = 0,
    //     OLED_ROTATION_90  = 1,
    //     OLED_ROTATION_180 = 2,
    //     OLED_ROTATION_270 = 3, // OLED_ROTATION_90 | OLED_ROTATION_180
    // } oled_rotation_t;
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BL:
            oled_write_P(PSTR("1\n"), false);
            break;
        case _FL:
            oled_write_P(PSTR("2\n"), false);
            break;
        case _TL:
            oled_write_P(PSTR("3\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
