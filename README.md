# Corne QMK + Vial Firmware

Configuração pessoal do Corne (RP2040) rodando QMK + Vial.

## Estrutura do repositório

```
.
├── .github/
│   └── workflows/
│       └── build.yml       # Compila o firmware automaticamente
├── keymaps/
│   ├── keymap.c            # Layout, camadas, combos, home row mods
│   ├── config.h            # Configurações de tap-hold, RGB, OLED
│   └── rules.mk            # Features habilitadas (Vial, OLED, RGB...)
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
Mudança estrutural (novas camadas, combos, etc.)
    → edita keymap.c/config.h
    → push para o GitHub
    → Actions compila
    → baixa e flasha o .uf2

Ajuste rápido (trocar uma tecla, mudar timing)
    → abre o Vial
    → ajusta ao vivo
    → (opcional) sincroniza de volta ao keymap.c para persistir
```

## Camadas

| Layer | Ativação | Conteúdo |
|-------|----------|----------|
| 0 BASE | — | QWERTY + Home Row Mods |
| 1 LOWER | Polegar esq. (SPC) | Números, símbolos |
| 2 RAISE | Polegar esq. (ENT) | Numpad + Navegação |
| 3 ADJUST | Polegar dir. (BSP) | F-keys, Media, RGB |

## Combos

| Combo | Resultado |
|-------|-----------|
| Q + W | ESC |
| R + T | [ |
| Y + U | ] |
| F + G | ( |
| H + J | ) |
| V + B | { |
| N + M | } |
| T + Y | \ |
| G + H | \| |
| E + D | Ç |

## Home Row Mods

```
Esquerda:  A=GUI   S=ALT   D=CTRL  F=SHIFT
Direita:   J=SHIFT K=CTRL  L=ALT   ;=GUI
```

## Configurações importantes (config.h)

| Setting | Valor | Descrição |
|---------|-------|-----------|
| TAPPING_TERM | 200ms | Igual ao ZMK anterior |
| QUICK_TAP_TERM | 180ms | Evita hold acidental em typing rápido |
| COMBO_TERM | 50ms | Janela de tempo para combos |