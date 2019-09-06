
#include "node1_joystick.h"

void return_joystick_direction(joystick_direction *x_direction, joystick_direction *y_direction){
    CHANNEL x_value = CH1;
    CHANNEL y_value = CH2;

    uint8_t x = memory_map_read_adc(x_value);
    uint8_t y = memory_map_read_adc(y_value);

    if(0x60 < x < 0x85){
        *x_direction = NEUTRAL;
    }
    if(x < 0x5F){
        *x_direction = LEFT;
    }
    if(x > 0x86){
        *x_direction = RIGHT;
    }
        
    if(0x60 < y < 0x85){
        *y_direction = NEUTRAL;
    }
    if(y < 0x5F){
        *y_direction = DOWN;
    }
    if(y > 0x86){
        *y_direction = UP;
    }
}

void return_joystick_position(joystick_position * joystick){
    CHANNEL x_value = CH1;
    CHANNEL y_value = CH2;

    uint8_t x = memory_map_read_adc(x_value);
    uint8_t y = memory_map_read_adc(y_value);

    joystick->x_analog = (x/2.56);
    joystick->y_analog = (y/2.56);
}


void get_joystick_values(JOYSTICK *joystick){
    CHANNEL x_value = CH1;
    CHANNEL y_value = CH2;

    uint8_t x = memory_map_read_adc(x_value);
    uint8_t y = memory_map_read_adc(y_value);
    
    joystick->x_analog = (x/2.56);
    joystick->y_analog = (y/2.56);

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
