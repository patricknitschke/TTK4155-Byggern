
#include "node1_joystick.h"


void get_joystick_values(JOYSTICK *joystick){
    CHANNEL x_value = CH2;
    CHANNEL y_value = CH1;

    uint8_t x = memory_map_read_adc(x_value);
    uint8_t y = memory_map_read_adc(y_value);

    float x_temp = x;
    float y_temp = y;

    joystick->x_analog = (x_temp/255)*100;
    joystick->y_analog = (y_temp/255)*100;

    if(0x60 < x < 0x85){
        joystick->x_direction = NEUTRAL;
    }
    if(x < 0x5F){
        joystick->x_direction = LEFT;
    }
    if(x > 0x86){
        joystick->x_direction = RIGHT;
    }
        
    if(0x60 < y < 0x85){
        joystick->y_direction = NEUTRAL;
    }
    if(y < 0x5F){
        joystick->y_direction = DOWN;
    }
    if(y > 0x86){
        joystick->y_direction = UP;
    }
}
