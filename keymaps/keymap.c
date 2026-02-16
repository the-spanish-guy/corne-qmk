// Corne QMK + Vial Keymap
// OS Layout: US International
// Features: Home Row Mods, Combos (brackets/parens/braces/backslash/pipe/esc/cedilha)
//
// CAMADAS:
//   0 - BASE     : QWERTY + Home Row Mods
//   1 - LOWER    : Números, símbolos
//   2 - RAISE    : Numpad (esq), Navegação (dir)
//   3 - ADJUST   : F-keys, Media, RGB, QMK settings

#include QMK_KEYBOARD_H

// ──────────────────────────────────────────────
// LAYER ALIASES
// ──────────────────────────────────────────────
enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// ──────────────────────────────────────────────
// HOME ROW MODS
// Usando GACS (GUI, ALT, CTRL, SHIFT) — mesma ordem do seu ZMK
// Mão esquerda: A=GUI  S=ALT  D=CTRL  F=SHIFT
// Mão direita:  J=SHIFT  K=CTRL  L=ALT  ;=GUI
// ──────────────────────────────────────────────
#define HM_A  LGUI_T(KC_A)
#define HM_S  LALT_T(KC_S)
#define HM_D  LCTL_T(KC_D)
#define HM_F  LSFT_T(KC_F)
#define HM_J  RSFT_T(KC_J)
#define HM_K  RCTL_T(KC_K)
#define HM_L  RALT_T(KC_L)
#define HM_SC RGUI_T(KC_SCLN)

// ──────────────────────────────────────────────
// LAYER TAPS (polegares)
// ──────────────────────────────────────────────
#define LT_SPC LT(_LOWER, KC_SPC)
#define LT_ENT LT(_RAISE, KC_ENT)
#define LT_BSP LT(_ADJUST, KC_BSPC)

// ──────────────────────────────────────────────
// CONFIGURAÇÕES DE TAP-HOLD
// Equivalente ao tap-preferred + global-quick-tap do ZMK
// Cole isso no seu config.h:
//
//   #define TAPPING_TERM 200
//   #define QUICK_TAP_TERM 180
//   #define PERMISSIVE_HOLD               // mais próximo de tap-preferred
//   #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
//
// ──────────────────────────────────────────────

// ──────────────────────────────────────────────
// COMBOS
// Posições das teclas no Corne (0-41):
//
//   0   1   2   3   4   5       6   7   8   9  10  11
//  12  13  14  15  16  17      18  19  20  21  22  23
//  24  25  26  27  28  29      30  31  32  33  34  35
//                 36  37  38      39  40  41
//
// ──────────────────────────────────────────────
enum combo_events {
    COMBO_LEFT_BKT,    // R+T  → [
    COMBO_RIGHT_BKT,   // Y+U  → ]
    COMBO_LEFT_PAR,    // F+G  → (
    COMBO_RIGHT_PAR,   // H+J  → )
    COMBO_LEFT_BRC,    // V+B  → {
    COMBO_RIGHT_BRC,   // N+M  → }
    COMBO_BACKSLASH,   // T+Y  → backslash
    COMBO_PIPE,        // G+H  → pipe
    COMBO_ESC,         // Q+W  → ESC
    COMBO_CEDILHA,     // E+D  → Ç  (AltGr+, no US International)
    COMBO_COUNT
};

// Teclas de cada combo
const uint16_t PROGMEM combo_left_bkt[]   = {KC_R,    KC_T,    COMBO_END};
const uint16_t PROGMEM combo_right_bkt[]  = {KC_Y,    KC_U,    COMBO_END};
const uint16_t PROGMEM combo_left_par[]   = {HM_F,    KC_G,    COMBO_END};
const uint16_t PROGMEM combo_right_par[]  = {KC_H,    HM_J,    COMBO_END};
const uint16_t PROGMEM combo_left_brc[]   = {KC_V,    KC_B,    COMBO_END};
const uint16_t PROGMEM combo_right_brc[]  = {KC_N,    KC_M,    COMBO_END};
const uint16_t PROGMEM combo_backslash[]  = {KC_T,    KC_Y,    COMBO_END};
const uint16_t PROGMEM combo_pipe[]       = {KC_G,    KC_H,    COMBO_END};
const uint16_t PROGMEM combo_esc[]        = {KC_Q,    KC_W,    COMBO_END};
const uint16_t PROGMEM combo_cedilha[]    = {KC_E,    HM_D,    COMBO_END};

combo_t key_combos[] = {
    [COMBO_LEFT_BKT]   = COMBO(combo_left_bkt,   KC_LBRC),
    [COMBO_RIGHT_BKT]  = COMBO(combo_right_bkt,  KC_RBRC),
    [COMBO_LEFT_PAR]   = COMBO(combo_left_par,   KC_LPRN),
    [COMBO_RIGHT_PAR]  = COMBO(combo_right_par,  KC_RPRN),
    [COMBO_LEFT_BRC]   = COMBO(combo_left_brc,   KC_LCBR),
    [COMBO_RIGHT_BRC]  = COMBO(combo_right_brc,  KC_RCBR),
    [COMBO_BACKSLASH]  = COMBO(combo_backslash,  KC_BSLS),
    [COMBO_PIPE]       = COMBO(combo_pipe,        KC_PIPE),
    [COMBO_ESC]        = COMBO(combo_esc,         KC_ESC),
    // Ç no US International = RALT(KC_COMM) — vírgula com AltGr
    [COMBO_CEDILHA]    = COMBO(combo_cedilha,    RALT(KC_COMM)),
};

// ──────────────────────────────────────────────
// KEYMAPS
// ──────────────────────────────────────────────
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // ┌─────────────────────────────────────────────────────────┐
    // │  LAYER 0 — BASE                                         │
    // │  QWERTY + Home Row Mods                                 │
    // │  Combos ativos: ESC, [], (), {}, \, |, Ç               │
    // └─────────────────────────────────────────────────────────┘
    [_BASE] = LAYOUT_split_3x6_3(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCTL, HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                     KC_H,    HM_J,    HM_K,    HM_L,    HM_SC,   KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    //└────────┴────────┴────────┴────────┴────────┴────────┘                └────────┴────────┴────────┴────────┴────────┴────────┘
                                  KC_LGUI, LT_SPC,  LT_ENT,                   LT_BSP,  KC_ENT,  KC_RALT
    //                           └────────┴────────┴────────┘                └────────┴────────┴────────┘
    ),

    // ┌─────────────────────────────────────────────────────────┐
    // │  LAYER 1 — LOWER                                        │
    // │  Números + símbolos comuns                              │
    // └─────────────────────────────────────────────────────────┘
    [_LOWER] = LAYOUT_split_3x6_3(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_TILD,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX,                  XXXXXXX, KC_UNDS, KC_PLUS, KC_LABK, KC_RABK, _______,
    //└────────┴────────┴────────┴────────┴────────┴────────┘                └────────┴────────┴────────┴────────┴────────┴────────┘
                                  _______, _______,  _______,                  _______, _______, _______
    //                           └────────┴────────┴────────┘                └────────┴────────┴────────┘
    ),

    // ┌─────────────────────────────────────────────────────────┐
    // │  LAYER 2 — RAISE                                        │
    // │  Numpad (esquerda) + Navegação (direita)                │
    // └─────────────────────────────────────────────────────────┘
    [_RAISE] = LAYOUT_split_3x6_3(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______, KC_ESC,  KC_7,    KC_8,    KC_9,    KC_ASTR,                  KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, KC_DEL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_0,    KC_4,    KC_5,    KC_6,    KC_MINS,                  KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_CAPS, KC_1,    KC_2,    KC_3,    KC_SLSH,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //└────────┴────────┴────────┴────────┴────────┴────────┘                └────────┴────────┴────────┴────────┴────────┴────────┘
                                  _______, KC_DOT,   _______,                  _______, _______, _______
    //                           └────────┴────────┴────────┘                └────────┴────────┴────────┘
    ),

    // ┌─────────────────────────────────────────────────────────┐
    // │  LAYER 3 — ADJUST                                       │
    // │  F-keys + Media + RGB + QMK                             │
    // └─────────────────────────────────────────────────────────┘
    [_ADJUST] = LAYOUT_split_3x6_3(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                ┌────────┬────────┬────────┬────────┬────────┬────────┐
       QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                ├────────┼────────┼────────┼────────┼────────┼────────┤
       RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                ├────────┼────────┼────────┼────────┼────────┼────────┤
       RGB_TOG, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
    //└────────┴────────┴────────┴────────┴────────┴────────┘                └────────┴────────┴────────┴────────┴────────┴────────┘
                                  _______, _______,  _______,                  _______, _______, _______
    //                           └────────┴────────┴────────┘                └────────┴────────┴────────┘
    ),
};