
#include "node1_USART.h"
#include "node1_memory_map.h"
#include <util/delay.h>
#include "node1_joystick.h"
#include "node1_slider.h"
#include "node1_oled.h"

void menu_init(){
    oled_goto_pos(3,0);
	for (int i = 0; i < 6; i++) {
    	char word[] = " Welcome to this session ";
        char wait[] = " Please wait.";
        char wait2[] = " Please wait..";
        char wait3[] = " Please wait...";
        char* wait_list[3];
        wait_list[0] = wait;
        wait_list[1] = wait2;
        wait_list[2] = wait3;

        oled_goto_line(3);
	    oled_write_word(word);	
        oled_goto_pos(4,0);
        oled_write_word(wait_list[i%3]);

	    _delay_ms(1000);
        oled_clear_line(4);
	}
    oled_clear();
    oled_goto_pos(3,0);
    char word[] = "Use the Joystick";
    char word2[] = "to navigate through the menu";
    oled_write_word(word);	
    oled_goto_pos(4,0);
    oled_write_word(word2);
    _delay_ms(3000);
    oled_clear();
    int joystick_pos = 1;
    int* position = &joystick_pos;

    JOYSTICK menu_joystick;
    while(1){
        menu_run(position, &menu_joystick);
        menu_get_position(position);
        oled_goto_line(5);
        oled_write_word("1");
        _delay_ms(1000);
        oled_clear();
    }

}
void menu_print(){
    oled_goto_pos(0,0);
    char line1[] = "Choose one of the following:";
    char line2[] = "   1. Suck a dick";
    char line3[] = "   2. Play ping pong";
    char line4[] = "   3. Exit game";

    oled_goto_pos(0,0);
    oled_write_word(line1);
    oled_goto_pos(1,3);
    oled_write_word(line2);

    oled_goto_pos(2,3);
    oled_write_word(line3);

    oled_goto_pos(3,3);
    oled_write_word(line4);
}

void menu_run(int* position){
    char arrow[] = "->";
    menu_print();
    oled_goto_pos(*position,0);
    oled_write_word(arrow);
}

void menu_get_position(int *position, JOYSTICK* menu_joystick){
    get_joystick_values(menu_joystick);
    if (menu_joystick->y_direction == UP){
        *position += 1;
    }
    else if (menu_joystick->y_direction == DOWN){
        *position -= 1;
    }
    *position = *position % 4;
}

void menu_test_joystick() {
    JOYSTICK test_j;
    while (1) {
        oled_goto_pos(0,0);
        get_joystick_values(&test_j);
        joystick_direction y_direction = test_j.y_direction;
        oled_write_word("hello");
        oled_goto_pos(1,0);
        char numbers[4];
        sprintf(numbers, "%d", y_direction);
        oled_write_word(numbers); 
        _delay_ms(100);
    }
}