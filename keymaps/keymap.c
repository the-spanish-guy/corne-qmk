#include QMK_KEYBOARD_H
#include "transactions.h"

// ──────────────────────────────────────────────
// MAC / LINUX MODE
// ──────────────────────────────────────────────
bool mac_mode = false;

enum custom_keycodes {
    MAC_ON = SAFE_RANGE,  // ADJUST + H → ativa modo Mac
    LNX_ON,               // ADJUST + J → volta modo Linux
};

// Declarado em animation.c
extern void set_keylog(uint16_t keycode, keyrecord_t *record);

// ──────────────────────────────────────────────
// KEYMAPS
// ──────────────────────────────────────────────
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
                                          KC_LGUI, TL_LOWR,  KC_SPC,     KC_ENT, TL_UPPR, KC_LALT
  ),
  [1] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_LALT
  ),
  [2] = LAYOUT_split_3x6_3(
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_LALT
  ),
  [3] = LAYOUT_split_3x6_3(
       QK_BOOT,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
       RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,
       RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                    XXXXXXX,  MAC_ON,  LNX_ON, XXXXXXX, XXXXXXX, XXXXXXX,
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_LALT
  )
};

// ──────────────────────────────────────────────
// RGB
// ──────────────────────────────────────────────
static void apply_rgb_for_layer(uint8_t layer) {
    switch (layer) {
        case 0:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_NEXUS);
            // Ciano no modo Mac, Coral no modo Linux
            if (mac_mode) rgb_matrix_sethsv_noeeprom(HSV_CYAN);
            else          rgb_matrix_sethsv_noeeprom(HSV_CORAL);
            break;
        case 1:  // Lower - Azul respirando
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(HSV_BLUE);
            break;
        case 2:  // Raise - Roxo reativo
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
            break;
        case 3:  // Adjust - Arco-iris
            rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    apply_rgb_for_layer(get_highest_layer(state));
    return state;
}

static void mac_sync_handler(uint8_t in_size, const void *in_data, uint8_t out_size, void *out_data) {
    memcpy(&mac_mode, in_data, sizeof(mac_mode));
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(USER_SYNC_MAC, mac_sync_handler);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_NEXUS);
    rgb_matrix_sethsv_noeeprom(HSV_CORAL);
}

void housekeeping_task_user(void) {
    if (!is_keyboard_master()) return;
    static bool last_mac_mode = false;
    if (last_mac_mode != mac_mode) {
        if (transaction_rpc_send(USER_SYNC_MAC, sizeof(mac_mode), &mac_mode)) {
            last_mac_mode = mac_mode;
        }
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!host_keyboard_led_state().caps_lock) return false;

    static uint32_t caps_timer = 0;
    static bool caps_blink = false;

    if (timer_elapsed32(caps_timer) > 300) {
        caps_blink = !caps_blink;
        caps_timer = timer_read32();
    }

    if (caps_blink) {
        for (uint8_t i = led_min; i < led_max; i++) {
            rgb_matrix_set_color(i, RGB_MAGENTA);
        }
    }

    return false;
}

// ──────────────────────────────────────────────
// PROCESS RECORD
// ──────────────────────────────────────────────
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) set_keylog(keycode, record);

    switch (keycode) {
        case MAC_ON:
            if (record->event.pressed) {
                mac_mode = true;
                apply_rgb_for_layer(get_highest_layer(layer_state));
            }
            return false;
        case LNX_ON:
            if (record->event.pressed) {
                mac_mode = false;
                apply_rgb_for_layer(get_highest_layer(layer_state));
            }
            return false;

        // No modo Mac: mindinho (LCTL) → Command, polegar (LGUI) → Control
        case KC_LCTL:
            if (mac_mode) {
                if (record->event.pressed) register_code(KC_LGUI);
                else                       unregister_code(KC_LGUI);
                return false;
            }
            return true;
        case KC_LGUI:
            if (mac_mode) {
                if (record->event.pressed) register_code(KC_LCTL);
                else                       unregister_code(KC_LCTL);
                return false;
            }
            return true;
    }

    return true;
}
