#include "node1_memory_map.h"

#ifndef NODE1_SLIDER_H_
#define NODE1_SLIDER_H_

typedef struct SLIDER{
    uint8_t left_analog;
    uint8_t right_analog;
}SLIDER;

void get_slider_position(SLIDER* slider);

#endif /* NODE1_SLIDER_H_ */