#include <Arduino.h>
#include <bleKeyboardHandler.h>
#include <displayManager.h>
#include <gui.h>

void setup() {
  Serial.begin(115200);
  initDisplaySubsystem();
  gui();
  initBLEKeyboard();
}

void loop() {
  updateDisplaySubsystem();
  delay(5);
}
