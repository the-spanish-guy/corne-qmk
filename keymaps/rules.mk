# rules.mk — Corne QMK + Vial
# RP2040, OLED, RGB

# Vial (configuração em tempo real sem reflash)
VIAL_ENABLE = yes
QMK_SETTINGS = yes      # expõe settings do QMK via Vial (tapping term, etc.)
TAP_DANCE_ENABLE = no   # não usando tap dance por enquanto

# Dynamic keymap é necessário pro Vial funcionar
DYNAMIC_KEYMAP_ENABLE = yes

# Combos via Vial (não via código)
# COMBO_ENABLE não é necessário quando usando Vial
COMBO_ENABLE = no

# OLED
OLED_ENABLE = yes
OLED_DRIVER = ssd1306

# RGB
RGB_MATRIX_ENABLE = yes

# Encoder (descomente se o seu Corne tiver rotary encoders)
# ENCODER_ENABLE = yes
# ENCODER_MAP_ENABLE = yes

# Otimizações de tamanho (RP2040 tem memória de sobra, mas boa prática)
LTO_ENABLE = yes