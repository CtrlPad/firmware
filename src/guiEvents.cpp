#include <Arduino.h>
#include <ArduinoJson.h>
#include <bleKeyboardHandler.h>
#include <guiEvents.h>
#include <lvgl.h>

struct ButtonConfig {
  int id;
  String name;
  String icon;
  String exec;
};

extern ButtonConfig buttonData[6];

void clicked(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = (lv_obj_t *)lv_event_get_target(e);

  if (code == LV_EVENT_RELEASED) {
    uint32_t id = lv_buttonmatrix_get_selected_button(obj);

    if (id >= 0 && id <= 5) {
      JsonDocument doc;
      doc["id"] = buttonData[id].id;
      doc["name"] = buttonData[id].name;
      doc["exec"] = buttonData[id].exec;
      doc["icon"] = buttonData[id].icon;

      String output;
      serializeJson(doc, output);
      sendBLENotify(output);
    }
  }
}
