#include <Arduino.h>
#include <ArduinoJson.h>
#include <configReceiver.h>
#include <lvgl.h>

extern lv_obj_t *btnMatrix;
static JsonDocument doc;

struct ButtonConfig {
  int id;
  String name;
  String icon;
  String exec;
};
ButtonConfig buttonData[6];

static const char *dynamicMap[8];

void processIncomingConfig(String jsonConfig) {
  DeserializationError error = deserializeJson(doc, jsonConfig);
  if (error) {
    Serial.println(error.c_str());
    return;
  }

  JsonArray array = doc.as<JsonArray>();

  for (int i = 0; i < 6; i++) {
    buttonData[i].id = array[i]["id"].as<int>();
    buttonData[i].name = array[i]["name"].as<String>();
    buttonData[i].icon = array[i]["icon"].as<String>();
    buttonData[i].exec = array[i]["exec"].as<String>();
  }

  dynamicMap[0] = buttonData[0].name.c_str();
  dynamicMap[1] = buttonData[1].name.c_str();
  dynamicMap[2] = buttonData[2].name.c_str();
  dynamicMap[3] = "\n";
  dynamicMap[4] = buttonData[3].name.c_str();
  dynamicMap[5] = buttonData[4].name.c_str();
  dynamicMap[6] = buttonData[5].name.c_str();
  dynamicMap[7] = NULL;

  lv_buttonmatrix_set_map(btnMatrix, dynamicMap);
}
