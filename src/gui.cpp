#include <Arduino.h>
#include <gui.h>
#include <guiEvents.h>
#include <lvgl.h>
#include <configReceiver.h>

lv_obj_t *btns[6];
lv_obj_t *icons[6];
static lv_image_dsc_t iconDescs[6];

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
    lv_obj_set_flex_flow(btns[i], LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(btns[i], LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(btns[i], 2, 0);

    icons[i] = lv_image_create(btns[i]);

    lv_obj_t *label = lv_label_create(btns[i]);
    lv_label_set_text_fmt(label, "%d", i);
    lv_obj_add_event_cb(btns[i], clicked, LV_EVENT_CLICKED, NULL);
  }
}

void changeBtnLabel(int target, String value) {
  if (target < 0 || target >= 6 || btns[target] == NULL)
    return;
  lv_obj_t *label = lv_obj_get_child(btns[target], 1);
  if (label == NULL)
    return;
  lv_label_set_text(label, value.c_str());
}

void changeBtnColor(int target, String value) {
  if (target < 0 || target >= 6 || btns[target] == NULL)
    return;
  uint32_t buttonColor = strtoul(value.c_str() + 1, NULL, 16);
  lv_obj_set_style_bg_color(btns[target], lv_color_hex(buttonColor), 0);
}

void changeIcon(int target, const uint8_t *data, size_t len) {
  Serial.printf("changeIcon(%d): start\n", target);
  if (target < 0 || target >= 6 || btns[target] == NULL)
    return;

  iconDescs[target] = {
    .header = {
      .magic = LV_IMAGE_HEADER_MAGIC,
      .cf = LV_COLOR_FORMAT_A1,
      .w = 32,
      .h = 32,
      .stride = 4, 
    },
    .data_size = len,
    .data = data,
  };

  Serial.printf("changeIcon(%d): descriptor built, calling lv_image_set_src\n", target);
  lv_image_set_src(icons[target], &iconDescs[target]);
  Serial.printf("changeIcon(%d): lv_image_set_src returned\n", target);
}

void recolorIcon(int target, String value) {
  if (target < 0 || target >= 6 || btns[target] == NULL)
    return;

  uint32_t iconColor = strtoul(value.c_str() + 1, NULL, 16);
  lv_obj_set_style_image_recolor(icons[target], lv_color_hex(iconColor), LV_PART_MAIN);
};
