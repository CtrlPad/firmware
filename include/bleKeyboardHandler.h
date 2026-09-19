#include <Arduino.h>
#pragma once

void initBLEKeyboard();
void sendBLENotify(String config);
extern volatile bool configPending;
extern String pendingConfigJson;
