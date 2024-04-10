#ifdef OLED_ENABLE

#include "layers.h"

// Rotate OLED
// oled_rotation_t oled_init_user(oled_rotation_t rotation)
// {
//   return OLED_ROTATION_180;
// }

// Draw to OLED
bool oled_task_user()
{
  // Set cursor position
  oled_set_cursor(0, 1);

  if (is_keyboard_master())
  {
    switch (get_highest_layer(layer_state))
    {
      case _COLEMAK:
        oled_write_P(PSTR("COLEMAK\n"), false);
        break;

      case _NUM:
        oled_write_P(PSTR("NUM\n"), false);
        break;

      case _FN:
        oled_write(PSTR("FUNCTION\n"), false);
        break;

      default:
        oled_write_P(PSTR("UNDEFINED\n"), false);
        break;
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAP") : PSTR("   "), false);
  }

  else
  {
    oled_write_P(PSTR("UwU <3"), false);
  }

  return false;
}

#endif
