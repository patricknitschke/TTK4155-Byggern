#include <avr/io.h>
#include "node1_SPI.h"


typedef enum TRANSMITT_BUFFER{
    TXBo = 0b0001,
    TXB1 = 0b0010,
    TXB2 = 0b0100
}TRANSMITT_BUFFER;

/*
typedef enum MODE{
    NORMAL_MODE
    SLEEP_MODE
    LOOPBACK_MODE 

}*/

uint8_t mcp_read(uint8_t address);

void mcp_write(uint8_t address, uint8_t data);

void mcp_request_to_send(TRANSMITT_BUFFER buffer);

uint8_t mcp_read_status();

void mcp_reset();

void mcp_bit_modify();

void mcp_set_mode();