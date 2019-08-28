/*
 * .c
 *
 * Created: 07.07.2019 19:18:23
 *  Author: siawashn
 */ 

#include "node1_UART.h"


//Synchronous definition of functions
 void UART_Init( unsigned int ubrr )
{
	// Set baud rate 
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	//Using asynchronous double speed mode
	UCSR0A |= 1 << U2X0;
	
	
	//8bit data, asynchronous, disabled parity mode, 2 stop bit
	UCSR0C = (1<<URSEL0) | (0 << UMSEL0) | (0 << UPM00) | (1 << USBS0) | ( 3 << UCSZ00) | (0 << UCPOL0);

	
	// Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	
	//fdevopen(put_char, get_char);
}


void UART_Transmit(unsigned char data )
{
	// Wait for empty transmit buffer
	while ( !( UCSR0A & (1<<UDRE0)) );
	// Put data into buffer, sends the data 
	UDR0 = data;
}


unsigned char UART_Receive( void )
{
	
	// Wait for data to be received 
	while ( !(UCSR0A & (1<<RXC0)) );
	// Get and return received data from buffer 
	return UDR0;
}


/*int put_char(char data, FILE* file){
	if(data=='\n'){
		UART_Transmit('\r');
	}
	UART_Transmit(data);
	return 0;


}

int get_char(FILE* file){
	return UART_Receive();

}
*/
