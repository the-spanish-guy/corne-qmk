// config.h — Corne QMK + Vial
// RP2040, US International, Home Row Mods

#pragma once

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
#define OLED_TIMEOUT 30000     // Desliga OLED após 30s de inatividade (ms)

// ──────────────────────────────────────────────
// RGB
// ──────────────────────────────────────────────
#define RGB_MATRIX_TIMEOUT 60000   // Desliga RGB após 60s de inatividade
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BREATHING
#define RGB_MATRIX_DEFAULT_VAL 80  // Brilho inicial (0-255)

// Se estiver usando RGB Matrix (não Underglow), descomente:
// #define ENABLE_RGB_MATRIX_BREATHING
// #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON

// ──────────────────────────────────────────────
// MISC
// ──────────────────────────────────────────────

// Desativa as teclas que não são usadas no Corne (sem numpad físico)
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE