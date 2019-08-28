/*
 * UART.h
 *
 * Created: 07.07.2019 19:20:35
 *  Author: siawashn
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <stdio.h>

#define F_CPU 4915200// External Clock
//#define F_CPU 8000000// Calibrated internal RC Oscillator. When in asynchronous mode, this will be the clock source
#define BAUD 9600
#define MYUBRR F_CPU/8/BAUD-1

//The function initializes the UART module
//the baud rate is given as function parameter
//The function sends frames of 5-8 Data Bit
void UART_Init( unsigned int ubrr );

///Function waits for the transmit
// bugger to get empty and then writes to it.
void UART_Transmit(unsigned char data );

//Function waits for 5-8 bi data to be received
//the function returns the data
unsigned char UART_Receive( void );

int put_char(char data, FILE* file);

int get_char(FILE* file);



#endif /* UART_H_ */

