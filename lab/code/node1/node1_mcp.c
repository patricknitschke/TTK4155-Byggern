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

void mcp_cs(uint8_t c){
    if(c){
        PORTB |= (1 << PB4); 
    }
    else{
        PORTB &= ~(1 << PB4); 
    }
}

void mcp_init();

uint8_t mcp_read(uint8_t address){
    //first wwrite the comand for read instruciton
    mcp_cs(0);
    spi_transmitt(MCP_READ);
    spi_transmitt(address);
    uint8_t data = spi_receive();
    mcp_cs(1);
    return data;
}

void mcp_write(uint8_t address, uint8_t data){
    mcp_cs(0);
    spi_transmitt(MCP_WRITE);
    spi_transmitt(address);
    spi_transmitt(data);
    mcp_cs(1);
}

//RTS command can be used to initiated message transmission for one or more of the transmitt buffers
//The command buffer will TxBnCTRL.TXREQ for the respective buffer(s)
void mcp_request_to_send(){
    mcp_cs(0);
    //only use buffer 0
    spi_transmitt(MCP_RTS_TX0);
    mcp_cs(1);
}

//Read status allows single instruction access to some of the often used status
// bits for reception and transmission
uint8_t mcp_read_status(){
    mcp_cs(0);
    spi_transmitt(MCP_READ_STATUS);
    uint8_t data = spi_receive();
    mcp_cs(1);
    return data;
}

void mcp_reset(){
    mcp_cs(0);
    spi_transmitt(MCP_RESET);
    mcp_cs(1);
}

/* The bit modify instruction provides a means for setting or clearing individual bits in specific status and control registers
*/
void mcp_bit_modify(uint8_t address, uint8_t mask, uint8_t data){
    mcp_cs(0);
    spi_transmitt(MCP_BITMOD);
    spi_transmitt(address);
    spi_transmitt(mask);
    spi_transmitt(data);
    mcp_cs(1);
}


