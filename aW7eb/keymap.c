#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"

#include "features/sentence_case.h"
#include "features/custom_shift_keys.h"
#include "features/select_word.h"
#include "features/switcher.h"

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  SELWFWD,
  SELWBAK,
  SELLINE,
  SWITCH,
};

/** Custom Shift **/
const custom_shift_key_t custom_shift_keys[] = {
  {KC_COMM, KC_QUES}, // Shift , is ?
  {KC_DOT , KC_EXLM}, // Shift . is !
  {KC_QUOTE, KC_DOUBLE_QUOTE}, // Shift ' is "
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

/** Switcher **/
uint16_t SWITCHER_TRIGGER_KEYCODE = SWITCH;
uint16_t SWITCHER_VIRTUAL_HOLD_KEY = KC_LGUI;
uint16_t SWITCHER_VIRTUAL_TAP_KEY = KC_TAB;
const switcher_key_t switcher_secondary_keys[] = {
  // When switcher is active:
  {KC_LEFT, KC_LEFT}, // 'left' functions as usual
  {KC_RIGHT, KC_RIGHT}, // 'right' functions as usual
  {KC_UP, KC_UP}, // 'up' functions as usual
  {KC_DOWN, KC_DOWN}, // 'down' functions as usual
  {LGUI(KC_A), KC_Q}, // left pinky sends 'Q' to quit app
  {LGUI(KC_V), KC_H}, // left index sends 'H' to hide app
  {LGUI(KC_C), KC_DOT}, // left middle sends '.' to silently exit switcher
  // All other keycodes both exit the switcher and send the keycode for processing
};
uint8_t NUM_SWITCHER_SECONDARY_KEYS =
    sizeof(switcher_secondary_keys) / sizeof(switcher_key_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_LEFT_ALT,    KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LALT(LGUI(LCTL(LSFT(KC_K)))),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, KC_B,           KC_L,           KC_D,           KC_W,           KC_Z,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_QUOTE,       KC_F,           KC_O,           KC_U,           KC_J,           KC_TRANSPARENT,
    KC_TRANSPARENT, MT(MOD_LALT, KC_N),MT(MOD_LCTL, KC_R),MT(MOD_LGUI, KC_T),MT(MOD_LSFT, KC_S),KC_G,                                                                           KC_Y,           MT(MOD_RSFT, KC_H),MT(MOD_RGUI, KC_A),MT(MOD_RCTL, KC_E),MT(MOD_RALT, KC_I),KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,           KC_X,           KC_M,           KC_C,           KC_V,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_K,           KC_P,           KC_COMMA,       KC_DOT,         OSL(2),         TG(4),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    MO(3),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LT(1, KC_SPACE)
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LABK,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_LBRC,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RBRC,        KC_PERC,        KC_SLASH,       KC_ASTR,        KC_CIRC,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_LPRN,                                                                        KC_RPRN,        KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_RABK,        KC_DLR,         UK_PND,         KC_5,           KC_LCBR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RCBR,        KC_6,           KC_TRANSPARENT, KC_TRANSPARENT, OSL(2),         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_GRAVE,       KC_BSLS,        KC_PIPE,        KC_SLASH,       KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AMPR,        KC_UNDS,        KC_AT,          LALT(LSFT(KC_MINUS)),KC_TRANSPARENT,                                                            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TILD,        UK_HASH,        KC_SCLN,        KC_COLN,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_N),     LGUI(KC_W),       LGUI(LCTL(KC_F)),              LGUI(KC_M),     LGUI(KC_I),     KC_TRANSPARENT,                KC_TRANSPARENT, SELLINE,        SELWBAK,        KC_UP,          SELWFWD,        LGUI(LCTL(KC_Q)), KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_A),     LGUI(KC_X),       LGUI(KC_C),                    LGUI(KC_V),     LGUI(KC_B),                                                    KC_TAB,         KC_LEFT,        KC_DOWN,        KC_RIGHT,       SWITCH,         KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_Z),     LGUI(LSFT(KC_Z)), KC_DOT,                        LGUI(KC_S),     LGUI(KC_U),     KC_TRANSPARENT,                KC_TRANSPARENT, QK_LLCK,        LALT(KC_BSPC),  LGUI(KC_SPACE), KC_BSPC,        KC_ENTER,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,                KC_TRANSPARENT,                                                                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_N,           KC_R,           KC_T,           KC_S,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_A,           KC_E,           KC_I,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_ergodox(
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 
  'L', 'L', 'L', 'L', 'L', 'L', 
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 
  'L', 'L', 'L', 'L', 'L',
  'L', 'L',
  'L', 'L', 'L', 'L',
  'R', 'R', 'R', 'R', 'R', 'R', 'R', 
  'R', 'R', 'R', 'R', 'R', 'R', 'R', 
  'R', 'R', 'R', 'R', 'R', 'R', 
  'R', 'R', 'R', 'R', 'R', 'R', 'R', 
  'R', 'R', 'R', 'R', 'R', 
  'R', 'R', 
  'R', 'R', 'R', 'R'
);

const uint16_t PROGMEM combo0[] = { LGUI(KC_N), LGUI(KC_W), COMBO_END};
const uint16_t PROGMEM combo1[] = { LGUI(KC_V), LGUI(KC_B), COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_UP, SELWFWD, COMBO_END};
const uint16_t PROGMEM combo3[] = { SELWBAK, KC_UP, COMBO_END};
const uint16_t PROGMEM combo4[] = { LGUI(KC_SPACE), KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo5[] = { LALT(KC_BSPC), LGUI(KC_SPACE), COMBO_END};
const uint16_t PROGMEM combo6[] = { LGUI(KC_S), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_DOT, LGUI(LSFT(KC_Z)), COMBO_END};
const uint16_t PROGMEM combo8[] = { LGUI(KC_X), LGUI(KC_C), COMBO_END};
const uint16_t PROGMEM combo9[] = { LGUI(KC_C), LGUI(KC_V), COMBO_END};
const uint16_t PROGMEM combo10[] = { LGUI(KC_W), LGUI(LCTL(KC_F)), COMBO_END};
const uint16_t PROGMEM combo11[] = { MT(MOD_LCTL, KC_R), MT(MOD_LGUI, KC_T), MT(MOD_LSFT, KC_S), COMBO_END};
const uint16_t PROGMEM combo12[] = { MT(MOD_RSFT, KC_H), MT(MOD_RGUI, KC_A), MT(MOD_RCTL, KC_E), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ESCAPE),
    COMBO(combo1, LALT(LGUI(LSFT(KC_V)))),
    COMBO(combo2, LCTL(KC_TAB)),
    COMBO(combo3, LCTL(LSFT(KC_TAB))),
    COMBO(combo4, LGUI(KC_GRAVE)),
    COMBO(combo5, LGUI(LSFT(KC_GRAVE))),
    COMBO(combo6, LGUI(KC_EQUAL)),
    COMBO(combo7, LGUI(KC_MINUS)),
    COMBO(combo8, LALT(LGUI(LCTL(LSFT(KC_L))))),
    COMBO(combo9, LALT(LGUI(LCTL(LSFT(KC_R))))),
    COMBO(combo10, LGUI(KC_Q)),
    COMBO(combo11, LALT(KC_BSPC)),
    COMBO(combo12, KC_ENTER),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // Switcher
  if(!process_switcher(keycode, record)) { return false; }

  // Sentence Case
  if (!process_sentence_case(keycode, record)) { return false; }

  // Custom Shift Keys
  if (!process_custom_shift_keys(keycode, record)) { return false; }

  // Select Word
  if (!process_select_word(keycode, record)) { return false; }

  switch (keycode) {
    case SELWBAK:  // Backward word selection.
      if (record->event.pressed) {
        select_word_register('B');
      } else {
        select_word_unregister();
      }
      break;

    case SELWFWD:  // Forward word selection.
      if (record->event.pressed) {
        select_word_register('W');
      } else {
        select_word_unregister();
      }
      break;

    case SELLINE:  // Line selection.
      if(record->event.pressed) {
        select_word_register('L');
      } else {
        select_word_unregister();
      }
      break;
  }

  // Oryx Stuff
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

char sentence_case_press_user(uint16_t keycode,
                              keyrecord_t* record,
                              uint8_t mods) {

  if ((mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
    const bool shifted = mods & MOD_MASK_SHIFT;
    switch (keycode) {
      
      case KC_A ... KC_Z:
        return 'a';  // Letter key.

      case KC_DOT:  // . is punctuation, Shift . is a symbol (>)
        return '.'; // DT Cutomisation - Shift-. is  ! rather than >
      
      case KC_COMM:
        return shifted ? '.' : '#'; // DT Cutomisation - Shift-, is  ? rather than <
      
      case KC_EXLM:
      case KC_QUES:
        return '.';
      
      case KC_2 ... KC_0:  // 2 3 4 5 6 7 8 9 0
      case KC_AT ... KC_RPRN:  // @ # $ % ^ & * ( )
      case KC_MINS ... KC_SCLN:  // - = [ ] backslash ;
      case KC_UNDS ... KC_COLN:  // _ + { } | :
      case KC_GRV:
        return '#';  // Symbol key.
      
      case KC_SPC:
      case KC_ENTER: // DT Cusomisation - Treat enter as a space, thus capitalising the start of paragraphs.
        return ' ';  // Space key.
      
      case KC_QUOT:
        return '\'';  // Quote key.
    }
  }

  // Otherwise clear Sentence Case to initial state.
  sentence_case_clear();
  return '\0';
}

uint8_t layer_state_set_user(uint8_t state) {
  return state;
};
