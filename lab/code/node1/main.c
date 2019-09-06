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
#include "node1_joystick.h"
//#include "node1_slider.h"

int main(void){
	USART_Init(MYUBRR);
	memory_map_init();
	
	joystick_position joystick;


	while(1){
		return_joystick_position(&joystick);
		//printf("%d    %d\n", x_direction, y_direction);
		printf("%02X   %02X\n", joystick.x_analog, joystick.y_analog);
	}
	return 0; 
}

