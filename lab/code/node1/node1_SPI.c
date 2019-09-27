

#include "node1_SPI.h"

/* The MISO, MOSI, SS and CLK must be set by the user as either input or output
SS = PB4
MOSI = PB5
MISO = PB6
CLK = PB7
*/

void spi_init(){
    /* Set MOSI, CLK and SS as output*/
    DDRB = (1 << PB4)|(1 << PB5)|(1 << PB7);

    /*Set MISO as input */
    DDRB &= ~(1 << PB6); 

    /* Enable SPI, Master, set clock rate fck/16 */
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void spi_transmitt(uint8_t cData){
    /* Start transmission */
    SPDR = cData; 
    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)));
}

uint8_t spi_receive(){
    /* Wait for reception complete */
    while(!(SPSR & (1<<SPIF)));
    /* Return data register */
    return SPDR;
}