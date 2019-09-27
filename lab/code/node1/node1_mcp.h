#include <avr/io.h>
#include "node1_SPI.h"
#include "mcp2515.h"




void mcp_cs(uint8_t c);

void mcp_init();

uint8_t mcp_read(uint8_t address);

void mcp_write(uint8_t address, uint8_t data);

void mcp_request_to_send();

uint8_t mcp_read_status();

void mcp_reset();

void mcp_bit_modify(uint8_t address, uint8_t mask, uint8_t data);

