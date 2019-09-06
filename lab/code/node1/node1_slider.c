#include "node1_slider.h"


void get_slider_position(SLIDER* slider) {
    CHANNEL left_value = CH3;
    CHANNEL right_value = CH4;

    uint8_t left = memory_map_read_adc(left_value);
    uint8_t right = memory_map_read_adc(right_value);

    float left_temp = left;
    float right_temp = right; 

    slider->left_analog = (left_temp/255)*100;  // x/256 * 100 gives encoder values 0 - 100
    slider->right_analog = (right_temp/255)*100;
}