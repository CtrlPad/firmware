#include "gui_events.h"
#include <Arduino.h>
#include <gui.h>
#include <lvgl.h>

LV_FONT_DECLARE(FontAwesome);

// bitwarden : f084
// mute: f130
// spotify: f1bc
// discord: f392
// Volume Down. f027
// Volume UP: f028

// #define BITWARDEN "\xEF\x82\x84" (UTF-8) => "f084" (Unicode)
// #define MUTE "\xEF\x84\xB0"
// #define SPOTIFY "\xEF\x86\xBC"
// #define DISCORD "\xEF\x8E\x92"
// #define VOLUME_DOWN "\xEF\x80\xA7"
// #define VOLUME_UP "\xEF\x80\xA8"

lv_obj_t *btnMatrix = NULL;

static const char *btnm_map[] = {"0", "1", "2", "\n", "3", "4", "5", NULL};

void gui() {
  btnMatrix = lv_buttonmatrix_create(lv_screen_active());
  lv_buttonmatrix_set_map(btnMatrix, btnm_map);
  lv_obj_set_style_text_font(btnMatrix, &FontAwesome, 0);
  lv_obj_set_size(btnMatrix, LV_PCT(100), LV_PCT(100));
  lv_obj_align(btnMatrix, LV_ALIGN_CENTER, 0, 0);

  lv_obj_set_style_pad_all(btnMatrix, 0, LV_PART_MAIN);

  lv_obj_set_style_border_width(btnMatrix, 0, LV_PART_MAIN);

  lv_obj_set_style_radius(btnMatrix, 0, LV_PART_MAIN);

  lv_obj_add_event_cb(btnMatrix, clicked, LV_EVENT_ALL, NULL);
}
