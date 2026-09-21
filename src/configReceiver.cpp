#include "gui.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include <configReceiver.h>
#include <iconRenderer.h>
#include <lvgl.h>

extern lv_obj_t *btnMatrix;
static JsonDocument doc;

ButtonConfig buttonData[6];

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
    buttonData[i].rasterizedIcon = array[i]["icon"].as<String>();
    buttonData[i].color = array[i]["color"].as<String>();
    buttonData[i].action = array[i]["action"].as<String>();
  }

  for (int i = 0; i < 6; i++) {
    if (buttonData[i].color != "") {
      changeBtnColor(i, buttonData[i].color);
    } else {
      changeBtnColor(i, "#AEC6CF"); 
    };

    if (buttonData[i].name != "") {
      changeBtnLabel(i, buttonData[i].name);
    } else {
      changeBtnColor(i, "Empty"); 
    };

    if (buttonData[i].rasterizedIcon != "") {
      renderIcon(i, buttonData[i].rasterizedIcon);
    };
  }
}
