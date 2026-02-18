#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
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

// ⚫⚪ LOGO SC DO CORINTHIANS (MINIMALISTA) ⚫⚪
static const char PROGMEM corinthians_sc[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0x70, 0xd8, 0xf8, 0xf8, 0xdc, 0xdc, 0xdc,
    0x9c, 0x1c, 0x1c, 0x1c, 0x38, 0x38, 0x58, 0x70, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xe0, 0xfc, 0xfe, 0x1b, 0x07, 0x01, 0x0e, 0x0f, 0xe3, 0xf9, 0x3c, 0x0e, 0x07, 0x03,
    0x03, 0x0f, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1b, 0xfe, 0xfc, 0xe0, 0x00,
    0x00, 0x00, 0x0f, 0x7f, 0xff, 0xb0, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0x3f, 0x78, 0xe0, 0xe0, 0xe0,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xe0, 0x00, 0xc0, 0xb0, 0xff, 0x7f, 0x0f, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x0e, 0x1c, 0x34, 0x38, 0x38, 0x70, 0x71, 0x71,
    0x73, 0x77, 0x76, 0x76, 0x3e, 0x3f, 0x37, 0x1d, 0x0e, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x90, 0x10, 0x10, 0x20, 0x00, 0x00, 0xc0, 0x20,
    0x10, 0x10, 0x10, 0x60, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x10, 0x10, 0x60, 0x00, 0x00, 0xf0, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x09, 0x09, 0x07, 0x00, 0x00, 0x03, 0x0c,
    0x08, 0x08, 0x08, 0x06, 0x00, 0x00, 0x03, 0x0c, 0x08, 0x08, 0x08, 0x06, 0x00, 0x00, 0x0f, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
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
    static bool show_inverted = false;
    static uint32_t last_blink = 0;
    
    // Define intervalo de piscar baseado no WPM
    uint32_t blink_interval;
    if      (wpm < 30)  blink_interval = 0;      // Sem animação
    else if (wpm < 60)  blink_interval = 800;    // Lento
    else if (wpm < 90)  blink_interval = 400;    // Médio
    else                blink_interval = 150;    // MODO CAMPEÃO! ⚡
    
    // Atualiza estado do piscar
    if (blink_interval > 0 && timer_elapsed32(last_blink) > blink_interval) {
        show_inverted = !show_inverted;
        last_blink = timer_read32();
    }
    
    // ⚫⚪ LOGO SC DO CORINTHIANS ⚫⚪
    oled_write_raw_P(corinthians_sc, sizeof(corinthians_sc));
    
    // Efeito visual baseado em WPM
    if (wpm >= 90 && show_inverted) {
        // MODO CAMPEÃO: Inverte toda a tela! ⚡🏆
        oled_invert(true);
    } else if (wpm >= 60 && show_inverted) {
        // WPM 60-89: Pisca parcial (inverte temporariamente)
        oled_invert(true);
    } else if (wpm >= 30 && show_inverted) {
        // WPM 30-59: Pisca suave
        oled_invert(true);
    } else {
        oled_invert(false);
    }
    
    // WPM contador no topo
    char wpm_str[16];
    if (wpm >= 90) {
        snprintf(wpm_str, sizeof(wpm_str), "CAMPEAO!%3d", wpm);  // ⚡🏆
    } else {
        snprintf(wpm_str, sizeof(wpm_str), "WPM:%3d", wpm);
    }
    oled_set_cursor(0, 0);
    oled_write(wpm_str, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) oled_render_left();
    else oled_render_right();
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:  // ⚪
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_NEXUS);
            rgb_matrix_sethsv_noeeprom(HSV_CORAL);
            break;
        case 1:  // Lower - Azul respirando 🔵
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(HSV_BLUE);
            break;
        case 2:  // Raise - Roxo reativo 🟣
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
            break;
        case 3:  // Adjust - Arco-íris 🌈
            rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
            break;
    }
    return state;
}
#endif