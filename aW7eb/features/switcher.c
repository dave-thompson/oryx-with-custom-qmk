#include "switcher.h"

bool process_switcher(uint16_t current_keycode, keyrecord_t *record) {
  static bool switcher_active = false;
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
        } else if (switcher_active) {
        // switcher active; some key (other than primary trigger) pressed / released
          for (int i = 0; i < NUM_SWITCHER_SECONDARY_KEYS; ++i) {
            if (current_keycode == switcher_secondary_keys[i].keycode) {
              // it's a secondary trigger: send the corresponding secondary tap
              if (record->event.pressed) {
                register_code(switcher_secondary_keys[i].virtual_keycode);
              } else {
                unregister_code(switcher_secondary_keys[i].virtual_keycode);
              }
                return false; // swallow the secondary trigger, we don't want it being typed
              }
            }
        // it's something else: end the switching sequence
            unregister_code(SWITCHER_VIRTUAL_HOLD_KEY);
            switcher_active = false;
        return true; // ensure the terminating keycode _is_ typed
      }
      return true;
    }
