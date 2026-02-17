VIA_ENABLE          = yes
VIAL_ENABLE         = yes
LTO_ENABLE          = yes

# RGB Underglow com TODOS os efeitos
RGBLIGHT_ENABLE     = yes
RGB_MATRIX_ENABLE   = no # Can't have RGBLIGHT and RGB_MATRIX at the same time.

# OLED habilitado
OLED_ENABLE         = yes
OLED_DRIVER         = ssd1306

# Features extras
MOUSEKEY_ENABLE     = no
EXTRAKEY_ENABLE     = yes  # Habilitando para media keys funcionarem
COMBO_ENABLE        = no
QMK_SETTINGS        = yes  # Habilitando para ajustar configs via Vial

# Features adicionais úteis
CAPS_WORD_ENABLE    = yes
LAYER_LOCK_ENABLE   = no
REPEAT_KEY_ENABLE   = no

# Dynamic keymap obrigatório para Vial
DYNAMIC_KEYMAP_ENABLE = yes