#pragma once

#include QMK_KEYBOARD_H

/**
 * Allows for Mac app switching (holding down cmd, then tab-ing multiple times)
 * from a single physical key.
 *
 * More generally, can be used anytime a modifier needs to be held while a key is
 * repeatedly tapped. In lieu of a physical key trigger, it's also possible to use
 * combos, tap dances, or any other means to generate the trigger_keycode.
 *
 * Optionally allows for a secondary trigger, facilitating an alternative action
 * without releasing the virtual_hold_key. In the Mac app switcher, this is useful
 * to send a 'Q' while cmd remains held, quitting the highlighted app. This does
 * not require a physical press of the 'Q' key but rather can be triggered by any
 * specified keycode.
 *
 * The virtual_hold_key (cmd in the Mac app switcher case) is released on the press
 * or release of any key other than the specified triggers. This means that if the
 * trigger is on a higher layer and you're holding a layer switch key to access it,
 * the virtual_hold_key will be released as soon as the layer switch key is released.
 */

/**
 * Custom switcher action keys. The `keycode` field is the keycode as it appears in
 * your layout and determines what is typed normally. The `virtual_keycode` is the
 * keycode that will be sent while in Switcher Mode.
 * 
 */
typedef struct {
  uint16_t keycode;
  uint16_t switcher_keycode;
} switcher_key_t;


/**
 * @brief Switcher trigger keycode
 *
 * Create a custom keycode (e.g. `SWITCH`) in keymap.c. Use this keycode in your layout
 * to trigger Switcher. Also define `SWITCHER_TRIGGER_KEYCODE` and assign it to your
 * new keycode. For example:
 *
 *     enum custom_keycodes {
 *       SWITCH = SAFE_RANGE,
 *       // Other custom keys...
 *     };
 *
 *     uint16_t SWITCHER_TRIGGER_KEYCODE = SWITCH;
 */
extern uint16_t SWITCHER_TRIGGER_KEYCODE;

extern uint16_t SWITCHER_VIRTUAL_HOLD_KEY;

extern uint16_t SWITCHER_VIRTUAL_TAP_KEY;

/** Table of switcher secondary keys */
extern const switcher_key_t switcher_keys[];
/** Number of entries in the switcher_keys table */
extern uint8_t NUM_SWITCHER_KEYS;

/**
 * Handler function for switcher.
 *
 * In keymap.c, call this function from your `process_record_user` function as follows.
 * Process Switcher should be at the top of your 'process_record_user' function,
 * or as a minimum above any other functions which process the same keycodes whenever
 * Switcher is not active.
 *
 *     #include "features/switcher.h"
 *
 *     bool process_record_user(uint16_t keycode, keyrecord_t* record) {
 *       if (!process_switcher(keycode, record)) { return false; }
 *       // Your macros ...
 *
 *       return true;
 *     }
 *
 * 
 */
bool process_switcher(uint16_t current_keycode, keyrecord_t *record);

bool process_switcher_with_secondary(
    uint16_t current_keycode,
    keyrecord_t *record,
    uint16_t secondary_trigger_keycode,
    uint16_t secondary_virtual_tap_key
);