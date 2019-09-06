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
	
	volatile JOYSTICK joystick;
	while(1){
		get_joystick_values(&joystick);
		printf("%d    %d   %d   %d\n", joystick.x_direction, joystick.y_direction, joystick.x_analog, joystick.y_analog );	
	}
	return 0; 
}

