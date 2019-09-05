
#include "node1_joystick.h"

void return_joystick_direction(joystick_direction *x_direction, joystick_direction *y_direction){
    CHANNEL x_value = CH1;
    CHANNEL y_value = CH2;

    uint8_t x = memory_map_read_adc(x_value);
    uint8_t y = memory_map_read_adc(y_value);

    if(0x70 < x < 0x7A){
        *x_direction = NEUTRAL;
    }
    if(x < 0x6E){
        *x_direction = LEFT;
    }
    if(x > 0x7B){
        *x_direction = RIGHT;
    }
        
    if(0x70 < y < 0x7A){
        *y_direction = NEUTRAL;
    }
    if(y < 0x6E){
        *y_direction = DOWN;
    }
    if(y > 0x7B){
        *y_direction = UP;
    }
}

void return_joystick_position(joystick_position * joystick){
    CHANNEL x_value = CH1;
    CHANNEL y_value = CH2;

    uint8_t x = memory_map_read_adc(x_value);
    uint8_t y = memory_map_read_adc(y_value);

    joystick->x = (x/5)*100;
    joystick->y = (y/5)*100;
}

