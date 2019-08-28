/*
 * node1_USART.c
 *
 * Created: 14.07.2019 12:05:50
 *  Author: siawashn
 */ 

#include "node1_USART.h"


void USART_Init(unsigned int ubrr)
{
	/*//syncrhonous slave mode
	DDRD = (1 << PIND4);
	*/

	/*Set baud rate*/
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	/*Set frame format: 8data, 2stop bit, synchronous mode */
	UCSR0C = (1 << URSEL0) | (1<<USBS0) | (3<<UCSZ00);

	/* transmission speed normal (not doubled) */
	UCSR0A = 0 << U2X0;
	
	/*Enable receiver and transmitter*/
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);

	fdevopen(put_char, get_char);
	
}

void USART_Transmit(unsigned char data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1 << UDRE0)) ) {}
	/* Put data into buffer, sends the data */
	
	UDR0 = data;

}

char USART_Receive()
{
	/* Wait for the data to be recieved */
	while ( !(UCSR0A & (1 << RXC0)) ) {}
	
	/* Get and return recieved data from buffer */
	return UDR0;
}

int put_char(char data, FILE* file){
	if(data=='\n'){
		USART_Transmit('\r');
	}
	USART_Transmit(data);
	return 0;


}

int get_char(FILE* file){
	return USART_Receive();

}
