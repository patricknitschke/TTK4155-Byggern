/*
 * node1.c
 *
 * Created: 09.07.2019 03:43:54
 *  Author: siawashn
 */ 

#include "node1_USART.h"
#include <avr/io.h>
#include <util/delay.h>



int main(void){
	
	USART_Init(MYUBRR);
	while(1){

		//printf('a');
		USART_Transmit('a');
	}
	return 0; 
}

