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

bool process_switcher(
    uint16_t current_keycode,
    keyrecord_t *record,
    bool *mid_sequence,
    uint16_t trigger_keycode,
    uint16_t virtual_hold_key,
    uint16_t virtual_tap_key
);

bool process_switcher_with_secondary(
    uint16_t current_keycode,
    keyrecord_t *record,
    bool *mid_sequence,
    uint16_t trigger_keycode,
    uint16_t virtual_hold_key,
    uint16_t virtual_tap_key,
    uint16_t secondary_trigger_keycode,
    uint16_t secondary_virtual_tap_key
);