#include <Arduino.h>
#include <ble_keyboard_handler.h>
#include <gui.h>
#include <display_manager.h>

void setup()
{
  Serial.begin(115200);
  initDisplaySubsystem();
  gui();
  initBLEKeyboard();
}

void loop()
{  
  updateDisplaySubsystem();
  delay(5);
}
