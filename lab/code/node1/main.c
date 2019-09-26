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
#include "node1_slider.h"
#include "node1_oled.h"
#include "menu.h"

int main(void){
	USART_Init(MYUBRR);
	memory_map_init();
	oled_init();
	//menu_test_joystick();
	JOYSTICK testy;
	while(1){
		get_joystick_values(&testy);
		printf("y_dir: %d\n", testy.y_analog);
	}
	
	return 0; 
}