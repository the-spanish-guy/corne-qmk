/*
 * Versão 1: TARTARUGA / COELHO
 * - WPM < 40  → Tartaruga
 * - WPM 40-80 → Coelho parado
 * - WPM > 80  → Coelho correndo
 */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
                                          KC_LGUI, TL_LOWR,  KC_SPC,     KC_ENT, TL_UPPR, KC_RALT
  ),
  [1] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
  ),
  [2] = LAYOUT_split_3x6_3(
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
  ),
  [3] = LAYOUT_split_3x6_3(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

// ── Sprites ────────────────────────────────────
static const char PROGMEM sprite_turtle[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00,
    0x80, 0x1f, 0x00, 0x00, 0xc0, 0x70, 0x00, 0x00, 0x60, 0xf0, 0x00, 0x00, 0x70, 0x97, 0x00, 0x00,
    0x78, 0x95, 0x00, 0x00, 0x4c, 0xf5, 0x00, 0x00, 0x64, 0x77, 0x00, 0x00, 0x54, 0x10, 0x00, 0x00,
    0x54, 0x10, 0x00, 0x00, 0x54, 0x10, 0x00, 0x00, 0x54, 0x10, 0x00, 0x00, 0x64, 0x77, 0x00, 0x00,
    0x4c, 0xf5, 0x00, 0x00, 0x78, 0x95, 0x00, 0x00, 0x70, 0x97, 0x00, 0x00, 0x60, 0xf0, 0x00, 0x00,
    0x40, 0x70, 0x00, 0x00, 0xc0, 0x10, 0x00, 0x00, 0xc0, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const char PROGMEM sprite_rabbit_slow[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x00, 0xc0, 0xdd, 0x00, 0x00, 0xfc, 0xff, 0x00, 0x00, 0x3c, 0xa2, 0x00, 0x00,
    0xa0, 0x22, 0x00, 0x00, 0xa0, 0x22, 0x00, 0x00, 0x20, 0x22, 0x00, 0x00, 0xa0, 0x22, 0x00, 0x00,
    0xbc, 0xa2, 0x00, 0x00, 0x7c, 0xff, 0x00, 0x00, 0xc0, 0xdd, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const char PROGMEM sprite_rabbit_fast[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00,
    0x00, 0xd8, 0x00, 0x00, 0xc0, 0x5d, 0x00, 0x00, 0xfc, 0x27, 0x00, 0x00, 0x3c, 0x22, 0x00, 0x00,
    0xa0, 0x22, 0x00, 0x00, 0xa0, 0x22, 0x00, 0x00, 0x20, 0x22, 0x00, 0x00, 0xa0, 0x22, 0x00, 0x00,
    0xbc, 0x22, 0x00, 0x00, 0x7c, 0x27, 0x00, 0x00, 0xc0, 0x4d, 0x00, 0x00, 0x80, 0xc8, 0x00, 0x00,
    0x00, 0xb8, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

// ── OLED Esquerdo ──────────────────────────────
static const char* rgb_matrix_effect_name(void) {
    switch (rgb_matrix_get_mode()) {
        case RGB_MATRIX_NONE:                       return "Off            ";
        case RGB_MATRIX_SOLID_COLOR:                return "Solid          ";
        case RGB_MATRIX_ALPHAS_MODS:                return "Alphas Mods    ";
        case RGB_MATRIX_GRADIENT_UP_DOWN:           return "Gradient UD    ";
        case RGB_MATRIX_GRADIENT_LEFT_RIGHT:        return "Gradient LR    ";
        case RGB_MATRIX_BREATHING:                  return "Breathing      ";
        case RGB_MATRIX_BAND_SAT:                   return "Band Sat       ";
        case RGB_MATRIX_BAND_VAL:                   return "Band Val       ";
        case RGB_MATRIX_BAND_PINWHEEL_SAT:          return "Pinwheel Sat   ";
        case RGB_MATRIX_BAND_PINWHEEL_VAL:          return "Pinwheel Val   ";
        case RGB_MATRIX_BAND_SPIRAL_SAT:            return "Spiral Sat     ";
        case RGB_MATRIX_BAND_SPIRAL_VAL:            return "Spiral Val     ";
        case RGB_MATRIX_CYCLE_ALL:                  return "Cycle All      ";
        case RGB_MATRIX_CYCLE_LEFT_RIGHT:           return "Cycle LR       ";
        case RGB_MATRIX_CYCLE_UP_DOWN:              return "Cycle UD       ";
        case RGB_MATRIX_RAINBOW_MOVING_CHEVRON:     return "Chevron        ";
        case RGB_MATRIX_CYCLE_OUT_IN:               return "Cycle Out In   ";
        case RGB_MATRIX_CYCLE_OUT_IN_DUAL:          return "Cycle OI Dual  ";
        case RGB_MATRIX_CYCLE_PINWHEEL:             return "Cycle Pinwheel ";
        case RGB_MATRIX_CYCLE_SPIRAL:               return "Cycle Spiral   ";
        case RGB_MATRIX_DUAL_BEACON:                return "Dual Beacon    ";
        case RGB_MATRIX_RAINBOW_BEACON:             return "Rainbow Beacon ";
        case RGB_MATRIX_RAINBOW_PINWHEELS:          return "Pinwheels      ";
        case RGB_MATRIX_RAINDROPS:                  return "Raindrops      ";
        case RGB_MATRIX_JELLYBEAN_RAINDROPS:        return "Jellybean      ";
        case RGB_MATRIX_HUE_BREATHING:              return "Hue Breathing  ";
        case RGB_MATRIX_HUE_PENDULUM:               return "Hue Pendulum   ";
        case RGB_MATRIX_HUE_WAVE:                   return "Hue Wave       ";
        case RGB_MATRIX_PIXEL_FRACTAL:              return "Pixel Fractal  ";
        case RGB_MATRIX_PIXEL_FLOW:                 return "Pixel Flow     ";
        case RGB_MATRIX_PIXEL_RAIN:                 return "Pixel Rain     ";
        case RGB_MATRIX_TYPING_HEATMAP:             return "Heatmap        ";
        case RGB_MATRIX_DIGITAL_RAIN:               return "Digital Rain   ";
        case RGB_MATRIX_SOLID_REACTIVE_SIMPLE:      return "Reactive Simple";
        case RGB_MATRIX_SOLID_REACTIVE:             return "Reactive       ";
        case RGB_MATRIX_SOLID_REACTIVE_WIDE:        return "Reactive Wide  ";
        case RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE:   return "React MultiWide";
        case RGB_MATRIX_SOLID_REACTIVE_CROSS:       return "Reactive Cross ";
        case RGB_MATRIX_SOLID_REACTIVE_MULTICROSS:  return "React MultiCros";
        case RGB_MATRIX_SOLID_REACTIVE_NEXUS:       return "Reactive Nexus ";
        case RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS:  return "React MultiNexs";
        case RGB_MATRIX_SPLASH:                     return "Splash         ";
        case RGB_MATRIX_MULTISPLASH:                return "Multi Splash   ";
        case RGB_MATRIX_SOLID_SPLASH:               return "Solid Splash   ";
        case RGB_MATRIX_SOLID_MULTISPLASH:          return "Solid MultiSpls";
        default:                                    return "Unknown        ";
    }
}

void oled_render_left(void) {
    // Layer
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0: oled_write_ln_P(PSTR("Base   "), false); break;
        case 1: oled_write_ln_P(PSTR("Lower  "), false); break;
        case 2: oled_write_ln_P(PSTR("Raise  "), false); break;
        case 3: oled_write_ln_P(PSTR("Adjust "), false); break;
        default: oled_write_ln_P(PSTR("???    "), false); break;
    }
    // RGB
    oled_write_P(PSTR("RGB: "), false);
    oled_write_ln(rgb_matrix_effect_name(), false);
}

// ── OLED Direito: Sprite + WPM ─────────────────
void oled_render_right(void) {
    uint8_t wpm = get_current_wpm();

    // Sprite baseado no WPM
    if (wpm < 40) {
        oled_write_raw_P(sprite_turtle, sizeof(sprite_turtle));
    } else if (wpm < 80) {
        oled_write_raw_P(sprite_rabbit_slow, sizeof(sprite_rabbit_slow));
    } else {
        oled_write_raw_P(sprite_rabbit_fast, sizeof(sprite_rabbit_fast));
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_left();
    } else {
        oled_render_right();
    }
    return false;
}

char keylog_str[24] = {};
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode < 60) name = code_to_name[keycode];
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
             record->event.key.row, record->event.key.col, keycode, name);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) set_keylog(keycode, record);
    return true;
}
#endif // OLED_ENABLE