CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
ORYX_ENABLE = yes
SPACE_CADET_ENABLE = no
REPEAT_KEY_ENABLE = yes
LAYER_LOCK_ENABLE = yes
LTO_ENABLE = yes

# Non-Oryx rules
SRC += features/custom_shift_keys.c
SRC += features/select_word.c