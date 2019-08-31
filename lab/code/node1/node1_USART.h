/*
 * node1_USART.h
 *
 * Created: 14.07.2019 12:06:12
 *  Author: siawashn
 */ 


#ifndef NODE1_USART_H_
#define NODE1_USART_H_

#include <avr/io.h>
#include <stdio.h>

#define F_CPU 4915200UL

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1


void USART_Init(unsigned int ubrr);

void USART_Transmit(unsigned char data);

char USART_Receive();

int put_char(char data, FILE* file);

int get_char(FILE* file);


#endif /* NODE1_USART_H_ */