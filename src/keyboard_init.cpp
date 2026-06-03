#include <keyboard_init.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard(
  "Elgato_Kick_Off", //deviceName
  "", // deviceManufacture
  67 // batteryLevel
);

void keyboard_init()
{
  bleKeyboard.begin();
}
