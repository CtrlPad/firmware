#include <Arduino.h>
#pragma once

struct ButtonConfig {
  int id;
  String name;
  String icon;
  String rasterizedIcon;
  String buttonColor;
  String action;
};

extern ButtonConfig buttonData[6];

void processIncomingConfig(String jsonConfig);
