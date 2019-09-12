
#include "node1_memory_map.h"
#include <stdlib.h>
#ifndef NODE1_OLED_H_
#define NODE1_OLED_H_

typedef enum ADDR_MODE {
    horisontal_addr = 0b00,
    vertical_addr = 0b01,
    page_addr = 0b10
} ADDR_MODE;

void oled_init();

void oled_reset();

void oled_home();

void goto_line(uint8_t line);

void oled_clear_line( uint8_t data);

void oled_pos(uint8_t row, uint8_t column);

void oled_write_data(uint8_t data);

void oled_write_comand(uint8_t data);

void oled_print(uint8_t data);

void oled_set_brightness(uint8_t data);

void oled_set_addressing_mode(ADDR_MODE mode);

void oled_set_entire_display_on();

void oled_set_sleep_mode();

void oled_set_normal_mode();

#endif /* NODE1_OLED_H_ */