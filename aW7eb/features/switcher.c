#include "switcher.h"

bool process_switcher(
    uint16_t current_keycode,
    keyrecord_t *record,
    bool *mid_sequence,
    uint16_t trigger_keycode,
    uint16_t virtual_hold_key,
    uint16_t virtual_tap_key
) {
    return process_switcher_with_secondary(keycode, record, mid_sequence, trigger_keycode, virtual_hold_key, virtual_tap_key, KC_NO, KC_NO);
}

bool process_switcher_with_secondary(
    uint16_t current_keycode,
    keyrecord_t *record,
    bool *mid_sequence,
    uint16_t trigger_keycode,
    uint16_t virtual_hold_key,
    uint16_t virtual_tap_key,
    uint16_t secondary_trigger_keycode,
    uint16_t secondary_virtual_tap_key
) {
    if (current_keycode == trigger_keycode) {
        if (record->event.pressed) {
            // primary trigger pressed
            if (!*mid_sequence) {
                // start of the switching sequence
                *mid_sequence = true;
                // hold the hold key
                register_code(virtual_hold_key);
            }
            // tap the tap_key //
            register_code(virtual_tap_key);
        } else {
            unregister_code(virtual_tap_key);
        }
        return false;
    } else if (*mid_sequence) {
        // mid-sequence; some other key pressed / released
        if ((current_keycode == secondary_trigger_keycode) && (secondary_trigger_keycode != KC_NO)) {
            // it's the secondary trigger - send the secondary tap
            if (record->event.pressed) {
                register_code(secondary_virtual_tap_key);
            } else {
                unregister_code(secondary_virtual_tap_key);
            }
            return false; // swallow the secondary trigger - we don't want it being typed
        } else {
            // it's something else - end the switching sequence
            unregister_code(virtual_hold_key);
            *mid_sequence = false;
            return true; // ensure the terminating keycode _is_ typed
        }
    }
    return true;
}