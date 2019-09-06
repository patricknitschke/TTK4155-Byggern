#include "node1_slider.h"

void return_slider_position(slider_position* slider) {
    CHANNEL left_value = CH3;
    CHANNEL right_value = CH4;

    uint8_t left = memory_map_read_adc(left_value);
    uint8_t right = memory_map_read_adc(right_value);

    slider->left_analog = (left/2.56);  // x/256 * 100 gives encoder values 0 - 100
    slider->right_analog = (right/2.56);
}