/*
 * node1_memory_map.c
 *
 * Created: 12.07.2019 06:44:26
 *  Author: siawashn
 */ 

#include <avr/io.h>
#include "node1_memory_map.h"

void memory_map_init(){
	MCUCR = (1 << SRE);
	SFIOR = (1 << XMM2);
	
}