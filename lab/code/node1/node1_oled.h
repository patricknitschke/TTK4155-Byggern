
#include "node1_memory_map.h"
#include <stdlib.h>
#ifndef NODE1_OLED_H_
#define NODE1_OLED_H_

typedef enum ADDR_MODE {
    horisontal_addr = 0b00,
    vertical_addr = 0b01,
    page_addr = 0b10
} ADDR_MODE;




void oled_clear(); //resets the oled, clears the sram

void oled_clear_line( uint8_t line);//clear the4 line were pointing to 

void oled_print(uint8_t data);




//these functions works
void oled_set_entire_display_on();//turn all the pixels in the oled 

void oled_set_sleep_mode();

void oled_set_normal_mode();

void oled_init(); //initializes the oled

void oled_write_data(uint8_t data);//writes data

void oled_write_comand(uint8_t data);//writes command

void oled_set_brightness(uint8_t data);//sets the brightness of the oled

void oled_set_addressing_mode(ADDR_MODE mode);//sets the addressng mode. vertical, horizontal og page

void oled_goto_line(uint8_t line);//does to the line we want to go to 

void oled_goto_column(uint8_t column);

void oled_goto_pos(uint8_t line, uint8_t column);//bring the oled to the line and column pointet to 

void oled_goto_home(); //brings the pointer to line 0 and column 0
#endif /* NODE1_OLED_H_ */