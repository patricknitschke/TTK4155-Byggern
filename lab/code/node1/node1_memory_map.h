/*
 * node1_memory_map.h
 *
 * Created: 12.07.2019 06:43:45
 *  Author: siawashn
 */ 
#include <avr/io.h>
#include "node1_USART.h"
#include <stdlib.h>
#include <util/delay.h>

#ifndef NODE1_MEMORY_MAP_H_
#define NODE1_MEMORY_MAP_H_


void memory_map_init();

void memory_map_write_oled_command(uint8_t value);

void memory_map_write_oled_data(uint8_t value);

void memory_map_write_sram(uint16_t address, uint8_t data);

uint8_t memory_map_read_sram(uint16_t address);

uint8_t memory_map_read_sram(uint16_t address);

//void memory_map_read_adc(uint16_t address)

uint8_t get_adc();

#endif /* NODE1_MEMORY_MAP_H_ */