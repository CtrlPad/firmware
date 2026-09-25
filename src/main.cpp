#include <Arduino.h>
#include <bleKeyboardHandler.h>
#include <displayManager.h>
#include <gui.h>
#include <configStorage.h>
#include <configReceiver.h>

void setup() {
  Serial.begin(115200);
  initConfigStorage();
  initDisplaySubsystem();
  initBLEKeyboard();
  gui();
  loadConfig();
}

void loop() {
  updateDisplaySubsystem();
  delay(5);
 
  if (configPending) {
    processIncomingConfig(pendingConfigJson);  
    configPending = false;
  };
}
