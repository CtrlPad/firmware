#include <Arduino.h>
#include "FS.h"
#include <LittleFS.h>
#include <configReceiver.h>

#define FORMAT_LITTLEFS_IF_FAILED true

void saveConfig(String message) {
  File file = LittleFS.open("/config.json", FILE_WRITE);
  if(!file){
    Serial.println("Failed to open file for writing");
    return;
  }
  Serial.println("Saving config");
  file.print(message);
  file.close();
}

void loadConfig() {
  File file = LittleFS.open("/config.json");

  if(!file || file.isDirectory()) {
    Serial.println("No config found to load");
    return;
  }
  Serial.println("Loading config");
  String jsonConfig = file.readString();
  file.close();

  if (jsonConfig != "") {
    processIncomingConfig(jsonConfig);
  }
}

void initConfigStorage() {
  if(!LittleFS.begin(FORMAT_LITTLEFS_IF_FAILED)) {
    Serial.println("LittleFS Mount Failed");
    return;
  }
}

