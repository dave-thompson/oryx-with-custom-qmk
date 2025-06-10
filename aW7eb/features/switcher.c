#include "switcher.h"

bool process_switcher(
    uint16_t current_keycode,
    keyrecord_t *record
) {
    return process_switcher_with_secondary(current_keycode, record, KC_NO, KC_NO);
}

bool process_switcher_with_secondary(
    uint16_t current_keycode,
    keyrecord_t *record,
    uint16_t secondary_trigger_keycode,
    uint16_t secondary_virtual_tap_key
) {
    static bool switcher_active = false;

    if (current_keycode == SWITCHER_TRIGGER_KEYCODE) {
        if (record->event.pressed) {
            // primary trigger pressed
            if (!switcher_active) {
                // start of the switching sequence
                switcher_active = true;
                // hold the hold key
                register_code(SWITCHER_VIRTUAL_HOLD_KEY);
            }
            // tap the tap_key //
            register_code(SWITCHER_VIRTUAL_TAP_KEY);
        } else {
            unregister_code(SWITCHER_VIRTUAL_TAP_KEY);
        }
        return false;
    } else if (switcher_active) {
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
            unregister_code(SWITCHER_VIRTUAL_HOLD_KEY);
            switcher_active = false;
            return true; // ensure the terminating keycode _is_ typed
        }
    }
    return true;
}