/*
 * node1_memory_map.h
 *
 * Created: 12.07.2019 06:43:45
 *  Author: siawashn
 */ 
#include <avr/io.h>

#ifndef NODE1_MEMORY_MAP_H_
#define NODE1_MEMORY_MAP_H_


void memory_map_init();

typdef enum ADDR{
    OLED_commman = 0x1000
    OLED_data = 0x1200;
    ADC = 0x1400;
    SRAM = 0x1800;
}ADDR;


void memory_map_write_oled_command(uint8_t value);

void memory_map_write_oled_data(uint8_t value);

void memory_map_write_sram(uint16_t address, uint8_t data);

uint8_t memory_map_read_sram(uint16_t address);

uint8_t memory_map_read_sram(uint16_t address);

//void memory_map_read_adc(uint16_t address)



#endif /* NODE1_MEMORY_MAP_H_ */