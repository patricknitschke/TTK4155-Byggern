/*
 * node1.c
 *
 * Created: 09.07.2019 03:43:54
 *  Author: siawashn
 */ 
#include "node1_USART.h"
#include "node1_memory_map.h"
#include <util/delay.h>
#include "node1_SRAM_test.h"

int main(void){
	
	USART_Init(MYUBRR);
	memory_map_init();
	volatile char *ext_ram = (char *) 0x1400;

	while(1){
	//SRAM_test();
	//ext_ram[0] = 4;
	printf('%02X', get_adc());

	}
	return 0; 
}

