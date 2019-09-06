
#include "node1_memory_map.h"


//Vil legge inn enumen inne i structen så jeg bare kan legge inn en variable av type struct inne i funksjonen
//vil så sammen funksjonene til en stor funksjon
typedef enum joystick_direction{
    LEFT, RIGHT, UP, DOWN, NEUTRAL
}joystick_direction;

typedef struct JOYSTICK{
    uint8_t x_analog;
    uint8_t y_analog;
    joystick_direction x_direction;
    joystick_direction y_direction;
}JOYSTICK;


void get_joystick_values(JOYSTICK *joystick);