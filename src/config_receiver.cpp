#include <Arduino.h>
#include <ArduinoJson.h>
#include <config_receiver.h>
#include <lvgl.h>

extern lv_obj_t *btnMatrix;
static JsonDocument doc;

static const char *dynamicMap[8];

void processIncomingConfig(String jsonConfig) {
  DeserializationError error = deserializeJson(doc, jsonConfig);
  if (error) {
    Serial.println(error.c_str());
    return;
  }

  JsonArray array = doc.as<JsonArray>();

  dynamicMap[0] = array[0]["icon"].as<const char *>();
  dynamicMap[1] = array[1]["icon"].as<const char *>();
  dynamicMap[2] = array[2]["icon"].as<const char *>();
  dynamicMap[3] = "\n";
  dynamicMap[4] = array[3]["icon"].as<const char *>();
  dynamicMap[5] = array[4]["icon"].as<const char *>();
  dynamicMap[6] = array[5]["icon"].as<const char *>();
  dynamicMap[7] = NULL;

  lv_buttonmatrix_set_map(btnMatrix, dynamicMap);
}
