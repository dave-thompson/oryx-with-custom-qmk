CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
REPEAT_KEY_ENABLE = no
COMBO_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
LAYER_LOCK_ENABLE = yes
LTO_ENABLE = yes

# Space saving
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
EXTRAKEY_ENABLE = no
ORYX_ENABLE = yes # Set to no to gain 1,006 bytes of firmware size, at the expense of losing live training in Keymapp
UNICODE_ENABLE = no
SWAP_HANDS_ENABLE= no

# Non-Oryx rules
DEFERRED_EXEC_ENABLE = yes
SRC += features/sentence_case.c
SRC += features/custom_shift_keys.c
SRC += features/select_word.c
SRC += features/switcher.c