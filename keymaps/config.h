// config.h — Corne QMK + Vial
// RP2040, US International, Home Row Mods

#pragma once

// ──────────────────────────────────────────────
// VIAL
// ──────────────────────────────────────────────
#define VIAL_KEYBOARD_UID {0x12, 0xA4, 0xB6, 0x7C, 0x9F, 0xE8, 0xD3, 0x01}

// Unlock combo: canto superior esquerdo + canto inferior direito
#define VIAL_UNLOCK_COMBO_ROWS { 0, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 11 }

// ──────────────────────────────────────────────
// SPLIT KEYBOARD
// ──────────────────────────────────────────────
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSPORT_MIRROR

// ──────────────────────────────────────────────
// TAP-HOLD
// Equivalente ao comportamento tap-preferred + global-quick-tap do ZMK
// ──────────────────────────────────────────────

// Tempo máximo para considerar um toque (não hold) — igual ao seu ZMK
#define TAPPING_TERM 200

// Se você pressionar a mesma tecla duas vezes rapidamente,
// a segunda sempre vira tap (evita ativar hold em typing rápido)
// Equivalente ao global-quick-tap do ZMK
#define QUICK_TAP_TERM 180

// Comportamento mais próximo do tap-preferred do ZMK:
// se outra tecla for pressionada E solta durante o hold,
// interpreta como tap
#define PERMISSIVE_HOLD

// Permite configurar HOLD_ON_OTHER_KEY_PRESS por tecla via Vial
// (útil para thumb keys que você sempre quer hold)
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// ──────────────────────────────────────────────
// COMBOS
// ──────────────────────────────────────────────
#define COMBO_TERM 50          // Janela de tempo para ativar combo (ms)

// ──────────────────────────────────────────────
// OLED
// ──────────────────────────────────────────────
#define OLED_TIMEOUT 60000     // Desliga OLED após 60s de inatividade (ms)
#define OLED_BRIGHTNESS 255
#define SPLIT_OLED_ENABLE

// ──────────────────────────────────────────────
// RGB
// Com 16MB de flash, podemos habilitar TODOS os efeitos!
// ──────────────────────────────────────────────
#define RGB_MATRIX_TIMEOUT 60000   // Desliga RGB após 60s de inatividade
#define RGB_MATRIX_DEFAULT_VAL 80  // Brilho inicial (0-255)
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_ALL  // Modo inicial: cycle through colors

// Habilita TODOS os efeitos disponíveis
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_RAIN

// Efeitos reativos (respondem a teclas pressionadas)
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

// ──────────────────────────────────────────────
// MISC
// ──────────────────────────────────────────────

// Desativa as teclas que não são usadas no Corne (sem numpad físico)
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE