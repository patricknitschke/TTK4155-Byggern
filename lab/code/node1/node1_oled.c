
#include "node1_oled.h"

//these are the lowest abstraction functions
void oled_write_data(uint8_t data){
    memory_map_write_oled_data(data);
}

void oled_write_comand(uint8_t data){
    memory_map_write_oled_command(data);
}

//this is the initialization function 
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
    oled_write_comand(0x02);//sets into page addressnign mode
    oled_write_comand(0xdb);//VCOM deselect level mode
    oled_write_comand(0x30);
    oled_write_comand(0xad);//master configuration
    oled_write_comand(0x00);
    oled_write_comand(0xa4);//out follows RAM content
    oled_write_comand(0xa6);//set normal display
    oled_write_comand(0xaf);//display on
}

//these functioons are navigating functions
void oled_goto_line(uint8_t line){
    oled_write_comand(0xB0 | line);
}

void oled_goto_column(uint8_t column){
    oled_write_comand(0x00 | (column & 0x0F));
    oled_write_comand(0X10 | ((column & 0xF0) >> 4));
}

void oled_goto_pos(uint8_t line, uint8_t column){
    oled_goto_column(column);
    oled_goto_line(line);
}

void oled_goto_home(){
    oled_goto_column(0);
    oled_goto_line(0);
}


//these function are clearing functions
void oled_clear_line(uint8_t line){
    oled_goto_line(line);
    oled_goto_column(0);
    for (int i = 0; i < 128; ++i){
        oled_write_data(0x00);
    }
}

void oled_clear(){
    for (int i = 0; i < 8; i++){
        oled_clear_line(i);
    }
    oled_goto_home();
}



//these functions are for extra functionality 
void oled_set_brightness(uint8_t data){
    oled_write_comand(0x81);
    oled_write_comand(data);
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

void oled_set_addressing_mode(ADDR_MODE mode){
    oled_write_comand(0x20);
    oled_write_comand(mode);
}
 
/*
void oled_write_data(char data);

void oled_print(uint8_t * data);
*/
