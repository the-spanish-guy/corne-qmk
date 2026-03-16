# Corne QMK + Vial Firmware

Configuração pessoal do Corne (RP2040) rodando QMK + Vial.

## Estrutura do repositório

```
.
├── .github/
│   └── workflows/
│       └── build.yml         # Compila o firmware automaticamente
├── keymaps/
│   ├── keymap.c              # Layout das camadas + RGB por layer + CAPS LOCK effect
│   ├── animation.c           # OLED: skull animado (esquerda/direita) + nomes de efeitos RGB
│   ├── config.h              # Tap-hold, combos, RGB matrix, OLED, split sync
│   ├── rules.mk              # Features habilitadas (Vial, OLED, RGB, WPM...)
│   └── vial.json             # Definição de layout para o Vial GUI
└── README.md
```

## Como compilar (GitHub Actions)

1. Faça um push para a branch `main`
2. Acesse a aba **Actions** no GitHub
3. Aguarde o workflow `Build Corne Firmware` terminar (~3-5 min)
4. Clique no workflow concluído → **Artifacts** → baixe `corne-firmware-[hash]`
5. Extraia o `.zip` — dentro estará o arquivo `.uf2`

Você também pode rodar manualmente: **Actions → Build Corne Firmware → Run workflow**

## Como flashear

1. Conecte o Corne via USB
2. Pressione o botão **RESET** duas vezes rapidamente
3. O teclado aparecerá como um drive USB (`RPI-RP2` ou similar)
4. Arraste o arquivo `.uf2` para dentro do drive
5. O teclado reiniciará automaticamente com o novo firmware

## Fluxo de trabalho

```
Mudança estrutural (novas camadas, novos efeitos, etc.)
    → edita keymap.c / animation.c / config.h
    → push para o GitHub
    → Actions compila
    → baixa e flasha o .uf2

Ajuste rápido (trocar uma tecla, mudar timing, adicionar combo)
    → abre o Vial
    → ajusta ao vivo
    → (opcional) sincroniza de volta ao keymap.c para persistir
```

## Camadas

| Layer | Nome | Ativação | Conteúdo |
|-------|------|----------|----------|
| 0 | BASE | — | QWERTY padrão |
| 1 | LOWER | Polegar esq. (TL_LOWR) | Números 1–0 + setas |
| 2 | RAISE | Polegar dir. (TL_UPPR) | Símbolos especiais |
| 3 | ADJUST | LOWER + RAISE simultaneamente | F1–F12 + controle RGB |

### Layer 0 — BASE

```
TAB   Q  W  E  R  T       Y  U  I  O  P  BSPC
LCTL  A  S  D  F  G       H  J  K  L  ;  '
LSFT  Z  X  C  V  B       N  M  ,  .  /  ESC
          LGUI TL_LOWR SPC     ENT TL_UPPR LALT
```

### Layer 1 — LOWER (números + navegação)

```
TAB  1  2  3  4  5       6     7     8   9     0    BSPC
CTL  -  -  -  -  -       LEFT  DOWN  UP  RIGHT  -    -
SFT  -  -  -  -  -       -     -     -   -      -    -
         GUI  ___  SPC       ENT  ___  LALT
```

### Layer 2 — RAISE (símbolos)

```
TAB  !  @  #  $  %       ^  &  *  (  )  BSPC
CTL  -  -  -  -  -       -  =  [  ]  \  `
SFT  -  -  -  -  -       _  +  {  }  |  ~
         GUI  ___  SPC       ENT  ___  LALT
```

### Layer 3 — ADJUST (F-keys + RGB)

```
BOOT  F1  F2  F3  F4   F5      F6  F7  F8  F9  F10  F11
TOG   HUE+ SAT+ VAL+  -    -       -   -   -   -    -   F12
NEXT  HUE- SAT- VAL-  -    -       -   -   -   -    -   -
              GUI  ___  SPC       ENT  ___  LALT
```

## RGB por camada

| Layer | Efeito | Cor |
|-------|--------|-----|
| 0 BASE | Solid Reactive Nexus | Coral |
| 1 LOWER | Breathing | Azul |
| 2 RAISE | Solid Reactive | Roxo |
| 3 ADJUST | Rainbow Moving Chevron | Arco-íris |

> CAPS LOCK ativo: todos os LEDs piscam em magenta (300ms interval).

## OLED

O firmware usa dois displays OLED em rotação 270°, com renderização separada por lado:

**Lado esquerdo (master):**
- Nome da camada ativa (`Base` / `Lower` / `Raise` / `Adjust`)
- Nome curto do efeito RGB atual (ex: `Nexus`, `Breath`, `Chevron`...)

**Lado direito (slave):**
- Animação de caveira (`skull_open` / `skull_closed`) que **pisca na frequência do WPM**:

| WPM | Intervalo de piscar |
|-----|---------------------|
| < 30 | 1000ms (devagar) |
| 30–59 | 500ms |
| 60–89 | 250ms |
| 90+ | 100ms — DOOM MODE |

- Contador `WPM: XXX` exibido no canto superior esquerdo do display

## Configurações importantes (config.h)

| Setting | Valor | Descrição |
|---------|-------|-----------|
| `TAPPING_TERM` | 200ms | Tempo para diferenciar tap de hold |
| `QUICK_TAP_TERM` | 180ms | Evita hold acidental em typing rápido |
| `PERMISSIVE_HOLD` | ativo | Hold resolve mais rápido ao rolar teclas |
| `COMBO_TERM` | 50ms | Janela de tempo para ativar combos |
| `COMBO_ONLY_FROM_LAYER` | 0 | Combos só funcionam na layer BASE |
| `MASTER_LEFT` | ativo | Lado esquerdo é o master (USB) |
| `RGB_MATRIX_LED_COUNT` | 54 | 27 LEDs por lado |
| `RGB_MATRIX_MAXIMUM_BRIGHTNESS` | 255 | Brilho máximo |
| `RGB_MATRIX_DEFAULT_VAL` | 80 | Brilho padrão ao inicializar |
| `RGB_MATRIX_TIMEOUT` | 60000ms | Desliga RGB após 60s sem teclar |
| `OLED_TIMEOUT` | 60000ms | Desliga OLED após 60s sem teclar |
| `SPLIT_WPM_ENABLE` | ativo | Slave recebe WPM via serial |
| `SPLIT_LAYER_STATE_ENABLE` | ativo | Slave recebe estado de layer |

## Features habilitadas (rules.mk)

| Feature | Status | Descrição |
|---------|--------|-----------|
| `VIAL_ENABLE` | yes | Configuração ao vivo via Vial GUI |
| `RGB_MATRIX_ENABLE` | yes | Controle de LEDs por matrix |
| `OLED_ENABLE` | yes | Driver ssd1306 |
| `COMBO_ENABLE` | yes | Combos hardcoded + combos via Vial |
| `TAP_DANCE_ENABLE` | yes | Tap dance |
| `EXTRAKEY_ENABLE` | yes | Media keys |
| `WPM_ENABLE` | yes | Contador de WPM para o OLED |
| `CAPS_WORD_ENABLE` | yes | Caps Word (maiúsculas até espaço) |
| `LTO_ENABLE` | yes | Link-time optimization |
| `SERIAL_DRIVER` | vendor | PIO para RP2040 (evita USB disconnect) |
