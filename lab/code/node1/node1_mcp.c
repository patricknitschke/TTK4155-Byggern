#include "node1_mcp.h"

/* 
Overview
MCP is desgined to interface directly with the SPI interface
data and command is clocked in on a rising edge into the SI pin
data is clocked out on falling edge fra the SO pin

MCP expects the first byte written to be command
so the clock must be go high before another command is suppose to be invoked

Command and data are written to the SI pin

*/

uint8_t mcp_read(uint8_t address){
    //first wwrite the comand for read instruciton
    spi_transmitt(0b00000011);
    spi_transmitt(address);
    return (spi_receive());
}

void mcp_write(uint8_t address, uint8_t data){
    spi_transmitt(0b00000010);
    spi_transmitt(address);
    spi_transmitt(data);
}

//RTS command can be used to initiated message transmission for one or more of the transmitt buffers
//The command buffer will TxBnCTRL.TXREQ for the respective buffer(s)
void mcp_request_to_send(TRANSMITT_BUFFER buffer){
    spi_transmitt(0b10000000 | buffer);
}

//Read status allows single instruction access to some of the often used status
// bits for reception and transmission
uint8_t mcp_read_status(){
    spi_transmitt(0b10100000);
    return(spi_receive());
}

void mcp_reset(){
    spi_transmitt(0b11000000);
}

void mcp_bit_modify();

void mcp_set_mode();


