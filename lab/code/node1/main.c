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

int main(void){
	USART_Init(MYUBRR);
	memory_map_init();
	
	joystick_direction x_direction;
	joystick_direction y_direction;
	joystick_position joystick;


	while(1){
		return_joystick_direction(& x_direction, & y_direction);
		/*if(x_direction = NEUTRAL){
			printf("true");
		}*/
		printf("%d   %d\n", x_direction, y_direction);


	}
	return 0; 
}

