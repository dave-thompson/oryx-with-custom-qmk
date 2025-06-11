#include "switcher.h"
#define SWITCHER_WINDOWS_OPEN_DELAY 500

static bool switcher_active = false; // Is the app switcher in use?
static bool windows_active = false; // Is the window switcher in use?

static void exit_switcher(void) {
    unregister_code(SWITCHER_VIRTUAL_HOLD_KEY);
    switcher_active = windows_active = false;
}

bool process_switcher(uint16_t current_keycode, keyrecord_t *record) {
    if (current_keycode == SWITCHER_TRIGGER_KEYCODE) {
        if (record->event.pressed) {
            // primary trigger pressed
            if (!switcher_active) { // start of the switching sequence
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
    } else if (switcher_active) { // switcher active; some key (other than primary trigger) pressed / released
        for (int i = 0; i < NUM_SWITCHER_SECONDARY_KEYS; ++i) {
            // if it's a secondary trigger: send the corresponding secondary tap
            if (current_keycode == switcher_secondary_keys[i].keycode) {
                uint16_t virtual_keycode = switcher_secondary_keys[i].virtual_keycode;
                if (record->event.pressed) {
                    register_code(virtual_keycode);
                } else {
                    unregister_code(virtual_keycode);
                    // if entering window browsing (expose): preselect the first window in the list
                    if (!windows_active &&
                        ((virtual_keycode == KC_UP) || (virtual_keycode == KC_DOWN) || (virtual_keycode == KC_1))) {
                        wait_ms(500); // Waiting for the window switcher to be shown
                        tap_code(KC_RIGHT);
                        windows_active = true;
                    }
                    // if the user selected a window themselves: clean up
                    if (windows_active && (virtual_keycode == KC_ENTER)) {
                        exit_switcher();
                    }
                    // if app switcher cancelled: clean up
                    if ((virtual_keycode == KC_ESC) || (!windows_active && (virtual_keycode == KC_DOT))) {
                        exit_switcher();
                    }
                }
                return false; // swallow the secondary trigger, we don't want it being typed
            }
        }
        // it's not a secondary trigger: end the switching sequence
        if (windows_active) { // if window switcher in use: select the highlighted window
            tap_code(KC_ENTER);
            exit_switcher();
        }
        else { // app switcher in use: hold alt while exiting to instruct macos to open window even if minimised
            register_code(KC_LALT);
            exit_switcher();
            unregister_code(KC_LALT);
        }
        return true; // ensure the terminating keycode _is_ typed
    }
    return true;
}
