#include "node1_memory_map.h"

#ifndef NODE1_SLIDER_H_
#define NODE1_SLIDER_H_

typedef struct slider_position{
    uint8_t left_analog;
    uint8_t right_analog;
}slider_position;

void return_slider_position(slider_position* slider);

#endif /* NODE1_SLIDER_H_ */