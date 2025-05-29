CONSOLE_ENABLE = yes # TODO: Set to No
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
ORYX_ENABLE = yes
SPACE_CADET_ENABLE = no
REPEAT_KEY_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
LTO_ENABLE = yes

# Non-Oryx rules
SRC += features/sentence_case.c
SRC += features/custom_shift_keys.c
#SRC += features/select_word.c # TODO: Uncomment