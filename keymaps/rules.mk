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
TAP_DANCE_ENABLE    = yes  # Tap dance para acentos
QMK_SETTINGS        = yes

# Features adicionais
CAPS_WORD_ENABLE    = yes
LAYER_LOCK_ENABLE   = no
REPEAT_KEY_ENABLE   = no

# Dynamic keymap obrigatório para Vial
DYNAMIC_KEYMAP_ENABLE = yes

WPM_ENABLE          = yes      # Habilita contador de palavras por minuto para mostrar no OLED

# Serial driver PIO para RP2040 (não bloqueia o loop principal, evita USB disconnect)
SERIAL_DRIVER       = vendor

# Para cada novo arquivo que for adicionado futuramente,
# será preciso uma nova linha SRC += arquivo.c
# ou modificar a linha para passar múltiplas linhas, ex:
# SRC+= animation.c \
#				outro_arquivo.c
SRC += animation.c
