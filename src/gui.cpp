#include <Arduino.h>
#include <gui.h>
#include <guiEvents.h>
#include <lvgl.h>

lv_obj_t *btns[6];

void gui() {
  lv_obj_t *screen = lv_screen_active();

  static int32_t col_dsc[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1),
                              LV_GRID_TEMPLATE_LAST};
  static int32_t row_dsc[] = {LV_GRID_FR(1), LV_GRID_FR(1),
                              LV_GRID_TEMPLATE_LAST};

  lv_obj_remove_flag(screen, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_style_pad_all(screen, 4, 0);
  lv_obj_set_style_pad_row(screen, 4, 0);
  lv_obj_set_style_pad_column(screen, 4, 0);
  lv_obj_set_grid_dsc_array(screen, col_dsc, row_dsc);

  for (uint8_t i = 0; i < 6; i++) {
    btns[i] = lv_button_create(screen);
    lv_obj_set_grid_cell(btns[i], LV_GRID_ALIGN_STRETCH, i % 3, 1,
                         LV_GRID_ALIGN_STRETCH, i / 3, 1);

    lv_obj_t *label = lv_label_create(btns[i]);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_label_set_text_fmt(label, "%d", i);
    lv_obj_add_event_cb(btns[i], clicked, LV_EVENT_CLICKED, NULL);
  }
}

void changeBtnLabel(int target, String value) {
  if (target < 0 || target >= 6 || btns[target] == NULL)
    return;
  lv_obj_t *label = lv_obj_get_child(btns[target], 0);
  if (label == NULL)
    return;
  lv_label_set_text(label, value.c_str());
}

void changeBtnColor(int target, String value) {
  if (target < 0 || target >= 6 || btns[target] == NULL)
    return;
  uint32_t color = strtoul(value.c_str() + 1, NULL, 16);
  lv_obj_set_style_bg_color(btns[target], lv_color_hex(color), 0);
}
