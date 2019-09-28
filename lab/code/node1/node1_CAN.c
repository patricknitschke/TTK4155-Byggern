#include "node1_CAN.h"
#include "node1_USART.h"
#include <avr/delay.h>
#include <avr/interrupt.h>


void can_intr_init(){
    DDRE &= ~(1 << PD2);
}
