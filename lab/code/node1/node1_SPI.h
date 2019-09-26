
#include <avr/io.h>
#include "node1_USART.h"


void spi_init();

void spi_transmitt(uint8_t cData);

uint8_t spi_receive();