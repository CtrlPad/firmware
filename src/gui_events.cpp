#include <Arduino.h>
#include <lvgl.h>
#include "gui_events.h"
#include <ble_keyboard_handler.h>

void clicked(lv_event_t *e)
{   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = (lv_obj_t *)lv_event_get_target(e);

    if(code == LV_EVENT_RELEASED) {
        uint32_t id = lv_buttonmatrix_get_selected_button(obj);

        switch(id) {
          case 0:
            sendBLENotify(id);
            break;
          case 1:
            sendBLENotify(id);
            break;
          case 2:
            sendBLENotify(id);
            break;
          case 3:
            sendBLENotify(id);
            break;
          case 4:
            sendBLENotify(id);
            break;
          case 5:
            sendBLENotify(id);
            break;
        }
    }
}
