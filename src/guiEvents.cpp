#include <Arduino.h>
#include <ArduinoJson.h>
#include <bleKeyboardHandler.h>
#include <guiEvents.h>
#include <lvgl.h>

struct ButtonConfig {
  int id;
  String name;
  String icon;
  String action;
};

extern ButtonConfig buttonData[6];

void clicked(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_target_obj(e);

  Serial.println("Button clicked");
  uint32_t id = lv_obj_get_index(obj);

  if (id >= 0 && id <= 5) {
    JsonDocument doc;
    doc["id"] = buttonData[id].id;
    doc["name"] = buttonData[id].name;
    doc["action"] = buttonData[id].action;
    doc["icon"] = buttonData[id].icon;

    String output;
    serializeJson(doc, output);
    sendBLENotify(output);
  }
}
