
#include "node1_oled.h"


void oled_write_data(uint8_t data){
    memory_map_write_oled_data(data);
}

void oled_write_comand(uint8_t data){
    memory_map_write_oled_command(data);
}


void oled_init(){
    oled_write_comand(0xae);//display off
    oled_write_comand(0xa1);//segment remap (columns address 0 is mapped to SEG0)
    oled_write_comand(0xda);//common pads hardware: alternative
    oled_write_comand(0x12);
    oled_write_comand(0xc8);//common output scan direction:comm63- comm0
    oled_write_comand(0xa8);//multiplex ratio mode: 63
    oled_write_comand(0x3f);
    oled_write_comand(0xd5);//display divide ratio/osc: fre.Mode
    oled_write_comand(0x80);
    oled_write_comand(0x81);//contrast control
    oled_write_comand(0x50);
    oled_write_comand(0xd9);//set charge period
    oled_write_comand(0x21);
    oled_write_comand(0x20);//set memory addressing mode
    oled_write_comand(0x02);
    oled_write_comand(0xdb);//VCOM deselect level mode
    oled_write_comand(0x30);
    oled_write_comand(0xad);//master configuration
    oled_write_comand(0x00);
    oled_write_comand(0xa4);//out follows RAM content
    oled_write_comand(0xa6);//set normal display
    oled_write_comand(0xaf);//display on
}

void oled_set_addressing_mode(ADDR_MODE mode){
    oled_write_comand(0x20);
    oled_write_comand(mode);
}
 
void oled_set_entire_display_on(){
    oled_write_comand(0xa5);
}

void oled_set_sleep_mode(){
    oled_write_comand(0xae);
}

void oled_set_normal_mode(){
    oled_write_comand(0xaf);
}

void goto_line(uint8_t line){
    oled_set_addressing_mode(page_addr);
    oled_write_comand(0xB0+line);
}


void oled_reset(){
    oled_write_comand(0x00);
    for(int i = 0; i < 8; i++) {
        goto_line(i);
        for(int j = 0; j < 128; j++){
            oled_write_data(0);
        }
    }
}

void oled_home();

void oled_clear_line( uint8_t data);

void oled_pos(uint8_t row, uint8_t column);

void oled_print(uint8_t data);

void oled_set_brightness(uint8_t data);



