#include "gui.h"
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
  String color;
  String action;
};
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
    buttonData[i].icon = array[i]["icon"].as<String>();
    buttonData[i].color = array[i]["color"].as<String>();
    buttonData[i].action = array[i]["action"].as<String>();
  }

  for (int i = 0; i < 6; i++) {
    changeBtnLabel(i, buttonData[i].name);
    changeBtnColor(i, buttonData[i].color);
  }
}
