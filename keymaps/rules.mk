VIA_ENABLE          = yes
VIAL_ENABLE         = yes
LTO_ENABLE          = yes

# RGB MATRIX com TODOS os efeitos (controla LEDs das teclas + underglow)
RGB_MATRIX_ENABLE   = yes
RGBLIGHT_ENABLE     = no  # Não pode ter os dois ao mesmo tempo

# OLED habilitado
OLED_ENABLE         = yes
OLED_DRIVER         = ssd1306

# Features extras
MOUSEKEY_ENABLE     = no
EXTRAKEY_ENABLE     = yes  # Media keys
COMBO_ENABLE        = yes  # Combos hardcoded + Vial combos
QMK_SETTINGS        = yes

# Features adicionais
CAPS_WORD_ENABLE    = yes
LAYER_LOCK_ENABLE   = no
REPEAT_KEY_ENABLE   = no

# Dynamic keymap obrigatório para Vial
DYNAMIC_KEYMAP_ENABLE = yes

WPM_ENABLE          = yes      # Habilita contador de palavras por minuto para mostrar no OLED
