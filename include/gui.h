#pragma once

#include <Arduino.h>
#include <lvgl.h>

extern lv_obj_t *btns[6];

void gui();
void changeBtnLabel(int target, String value);
void changeBtnColor(int target, String value);
void changeIcon(int target, const uint8_t *data, size_t len);
