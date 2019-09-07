
#include "node1_oled.h"


void write_oled(uint8_t data){
    memory_map_write_oled_data(data);
}