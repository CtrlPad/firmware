#include <Arduino.h>
#include <lvgl.h>
#include <lvgl_init.h>
#include <keyboard_init.h>
#include <touchscreen.h>
#include <ui.h>

void setup()
{
  Serial.begin(115200);
  lvgl_init();
  touchscreen_init();
  keyboard_init();
  ui();
}

void loop()
{  
  lv_task_handler();
  lv_tick_inc(5);
  delay(5);
}
