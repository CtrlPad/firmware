#include <Arduino.h>
#include <lvgl.h>
#include "events.h"
#include <BleKeyboard.h>

extern BleKeyboard bleKeyboard;

void clicked(lv_event_t *e)
{   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = (lv_obj_t *)lv_event_get_target(e);

    if(code == LV_EVENT_CLICKED) {
        uint32_t id = lv_buttonmatrix_get_selected_button(obj);

        switch(id) {
          case 0:
            bleKeyboard.print("0");
            break;
          case 1:
            bleKeyboard.print("1");
            break;
          case 2:
            bleKeyboard.print("2");
            break;
          case 3:
            bleKeyboard.print("3");
            break;
          case 4:
            bleKeyboard.print("4");
            break;
          case 5:
            bleKeyboard.print("5");
            break;
        }
    }
}
