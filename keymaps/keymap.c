#include QMK_KEYBOARD_H

// ──────────────────────────────────────────────
// TAP DANCE - Acentos em Português
// ──────────────────────────────────────────────
enum {
    TD_A,  // a → á → â → à → ã
    TD_E,  // e → é → ê
    TD_C,  // c → ç
    TD_O,  // o → ó → ô → õ
    TD_U   // u → ú
};

// Tap dance definitions
void dance_a_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: register_code(KC_A); break;
        case 2: tap_code16(RALT(KC_A)); break;      // á (AltGr+a no US-Intl)
        case 3: tap_code16(S(RALT(KC_6))); tap_code(KC_A); break;  // â (shift+AltGr+6, depois a)
        case 4: tap_code16(RALT(KC_GRV)); tap_code(KC_A); break;   // à (AltGr+`, depois a)
        default: tap_code16(RALT(KC_GRV)); tap_code(KC_A); break;  // ã
    }
}
void dance_a_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) unregister_code(KC_A);
}

void dance_e_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: register_code(KC_E); break;
        case 2: tap_code16(RALT(KC_E)); break;                    // é
        default: tap_code16(S(RALT(KC_6))); tap_code(KC_E); break; // ê
    }
}
void dance_e_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) unregister_code(KC_E);
}

void dance_c_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) register_code(KC_C);
    else tap_code16(RALT(KC_COMM));  // ç (AltGr+, no US-Intl)
}
void dance_c_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) unregister_code(KC_C);
}

void dance_o_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: register_code(KC_O); break;
        case 2: tap_code16(RALT(KC_O)); break;                    // ó
        case 3: tap_code16(S(RALT(KC_6))); tap_code(KC_O); break; // ô
        default: tap_code16(RALT(KC_GRV)); tap_code(KC_O); break; // õ
    }
}
void dance_o_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) unregister_code(KC_O);
}

void dance_u_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) register_code(KC_U);
    else tap_code16(RALT(KC_U));  // ú
}
void dance_u_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) unregister_code(KC_U);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_A] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_a_finished, dance_a_reset),
    [TD_E] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_e_finished, dance_e_reset),
    [TD_C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_c_finished, dance_c_reset),
    [TD_O] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_o_finished, dance_o_reset),
    [TD_U] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_u_finished, dance_u_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W, TD(TD_E),    KC_R,    KC_T,                         KC_Y, TD(TD_U),    KC_I, TD(TD_O),   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, TD(TD_A),    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X, TD(TD_C),    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, TL_LOWR,  KC_SPC,     KC_ENT, TL_UPPR, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// ⚫⚪ ESCUDO DO CORINTHIANS ⚫⚪
static const char PROGMEM corinthians_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
    0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x20, 0x40, 0x00, 0x00, 0x80, 0x40, 0x20,
    0x20, 0x20, 0xc0, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00, 0xff, 0x20, 0x20,
    0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x08, 0x11, 0x12, 0x12, 0x0e, 0x00, 0x00, 0x07, 0x18, 0x10,
    0x10, 0x10, 0x0c, 0x00, 0x00, 0x07, 0x18, 0x10, 0x10, 0x10, 0x0c, 0x00, 0x00, 0xff, 0x02, 0x02,
    0x00, 0x00, 0xff, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8,
    0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x70, 0x80, 0xff,
    0xff, 0x70, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x1c, 0x6c, 0xff,
    0xff, 0x1c, 0x0c, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x30, 0x08, 0x04, 0x03, 0x00,
    0x03, 0x04, 0x08, 0x30, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x7f, 0x42, 0x66, 0x7e, 0x5f, 0x5f, 0x5f, 0x7e, 0x66, 0x42, 0x40, 0x40, 0x40, 0x40,
    0x40, 0x40, 0x40, 0x40, 0x42, 0x66, 0x7e, 0x5f, 0x5f, 0x5f, 0x7e, 0x66, 0x42, 0x7f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const char* rgb_effect_name(void) {
    switch (rgb_matrix_get_mode()) {
        case RGB_MATRIX_NONE:                      return "Off";
        case RGB_MATRIX_SOLID_COLOR:               return "Solid";
        case RGB_MATRIX_ALPHAS_MODS:               return "Alphas";
        case RGB_MATRIX_GRADIENT_UP_DOWN:          return "Grad UD";
        case RGB_MATRIX_GRADIENT_LEFT_RIGHT:       return "Grad LR";
        case RGB_MATRIX_BREATHING:                 return "Breath";
        case RGB_MATRIX_BAND_SAT:                  return "Band Sat";
        case RGB_MATRIX_BAND_VAL:                  return "Band Val";
        case RGB_MATRIX_BAND_PINWHEEL_SAT:         return "Pinwheel";
        case RGB_MATRIX_BAND_PINWHEEL_VAL:         return "PinwhlVal";
        case RGB_MATRIX_BAND_SPIRAL_SAT:           return "Spiral S";
        case RGB_MATRIX_BAND_SPIRAL_VAL:           return "Spiral V";
        case RGB_MATRIX_CYCLE_ALL:                 return "Cycle";
        case RGB_MATRIX_CYCLE_LEFT_RIGHT:          return "Cycle LR";
        case RGB_MATRIX_CYCLE_UP_DOWN:             return "Cycle UD";
        case RGB_MATRIX_RAINBOW_MOVING_CHEVRON:    return "Chevron";
        case RGB_MATRIX_CYCLE_OUT_IN:              return "Out-In";
        case RGB_MATRIX_CYCLE_OUT_IN_DUAL:         return "OutInDual";
        case RGB_MATRIX_CYCLE_PINWHEEL:            return "C-Pinwhl";
        case RGB_MATRIX_CYCLE_SPIRAL:              return "C-Spiral";
        case RGB_MATRIX_DUAL_BEACON:               return "DualBeac";
        case RGB_MATRIX_RAINBOW_BEACON:            return "Rainbow";
        case RGB_MATRIX_RAINBOW_PINWHEELS:         return "RainbowP";
        case RGB_MATRIX_RAINDROPS:                 return "Raindrop";
        case RGB_MATRIX_JELLYBEAN_RAINDROPS:       return "Jelly";
        case RGB_MATRIX_HUE_BREATHING:             return "Hue Brea";
        case RGB_MATRIX_HUE_PENDULUM:              return "Pendulum";
        case RGB_MATRIX_HUE_WAVE:                  return "Hue Wave";
        case RGB_MATRIX_PIXEL_FRACTAL:             return "Fractal";
        case RGB_MATRIX_PIXEL_FLOW:                return "PixelFlo";
        case RGB_MATRIX_PIXEL_RAIN:                return "PixelRai";
        case RGB_MATRIX_TYPING_HEATMAP:            return "Heatmap";
        case RGB_MATRIX_DIGITAL_RAIN:              return "DigRain";
        case RGB_MATRIX_SOLID_REACTIVE_SIMPLE:     return "Reactive";
        case RGB_MATRIX_SOLID_REACTIVE:            return "React";
        case RGB_MATRIX_SOLID_REACTIVE_WIDE:       return "ReactWid";
        case RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE:  return "ReactMW";
        case RGB_MATRIX_SOLID_REACTIVE_CROSS:      return "ReactCrs";
        case RGB_MATRIX_SOLID_REACTIVE_MULTICROSS: return "ReactMC";
        case RGB_MATRIX_SOLID_REACTIVE_NEXUS:      return "Nexus";
        case RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS: return "MultiNex";
        case RGB_MATRIX_SPLASH:                    return "Splash";
        case RGB_MATRIX_MULTISPLASH:               return "MultiSpl";
        case RGB_MATRIX_SOLID_SPLASH:              return "SolidSpl";
        case RGB_MATRIX_SOLID_MULTISPLASH:         return "SolidMS";
        default:                                   return "???";
    }
}

void oled_render_left(void) {
    oled_write_P(PSTR("Layer\n"), false);
    switch (get_highest_layer(layer_state)) {
        case 0: oled_write_P(PSTR("Base\n"),   false); break;
        case 1: oled_write_P(PSTR("Lower\n"),  false); break;
        case 2: oled_write_P(PSTR("Raise\n"),  false); break;
        case 3: oled_write_P(PSTR("Adjust\n"), false); break;
        default: oled_write_P(PSTR("???\n"),   false); break;
    }
    oled_write_P(PSTR("---\n"), false);
    oled_write_P(PSTR("RGB\n"), false);
    oled_write_P(rgb_effect_name(), false);
}

void oled_render_right(void) {
    uint8_t wpm = get_current_wpm();
    
    // Escudo do Timão sempre visível! ⚫⚪
    oled_write_raw_P(corinthians_logo, sizeof(corinthians_logo));
    
    // WPM contador no topo
    char wpm_str[8];
    snprintf(wpm_str, sizeof(wpm_str), "WPM:%3d", wpm);
    oled_set_cursor(0, 0);
    oled_write(wpm_str, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) oled_render_left();
    else oled_render_right();
    return false;
}
#endif