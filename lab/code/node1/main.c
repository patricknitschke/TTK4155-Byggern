/*
 * node1.c
 *
 * Created: 09.07.2019 03:43:54
 *  Author: siawashn
 */ 
#include "node1_USART.h"
#include "node1_memory_map.h"
#include <util/delay.h>
//#include "node1_SRAM_test.h"
#include "node1_joystick.h"
#include "node1_slider.h"
#include "node1_oled.h"
#include "menu.h"

int main(void){
	USART_Init(MYUBRR);
	memory_map_init();
	oled_init();
	JOYSTICK my_joy;
	menu_init();
	while(1) {
		get_joystick_values(&my_joy);
		//printf("x: %d\ty: %d\n", my_joy.x_analog, my_joy.y_analog);
	}
	
	return 0; 
}