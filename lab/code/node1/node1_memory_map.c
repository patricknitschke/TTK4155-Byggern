/*
 * node1_memory_map.c
 *
 * Created: 12.07.2019 06:44:26
 *  Author: siawashn
 */ 
#include "node1_memory_map.h"

static volatile char* memory = (char*) 0x0000;

void memory_map_init(){
	MCUCR |= (1 << SRE);
	SFIOR |= (1 << XMM2);
}

void memory_map_write_oled_command(uint8_t value){
	memory[0x1000] = value;
}
void memory_map_write_oled_data(uint8_t value){
	memory[0x1200] = value;
}

void memory_map_write_sram(uint16_t address, uint8_t data){
	memory[0x1800 + address] = data;
}

uint8_t memory_map_read_sram(uint16_t address){
	return memory[0x1800 + address];
}

uint8_t get_adc(){
	memory[0x1400] = 0b0100;
	_delay_ms(1);
	return memory[0x1400];
}


//uint8_t memory_map_read_adc(uint16_t address){}