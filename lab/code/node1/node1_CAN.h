#include <avr/io.h>
#include "node1_mcp.h"


typedef struct MESSAGE{
    uint8_t id;
    uint8_t length;
    uint8_t data;
}MESSAGE;


void can_init();

void can_transmitt(MESSAGE *message);

MESSAGE can_receive();

