
#include "node1_USART.h"
#include "node1_memory_map.h"
#include <util/delay.h>
#include "node1_joystick.h"
#include "node1_slider.h"
#include "node1_oled.h"
#include "menu.h"

static menu_node_t* node_home;
static menu_node_t* node_play_game;
static menu_node_t* node_highscores;
static menu_node_t* node_settings;
static menu_node_t* node_calibrate_joystick;
static menu_node_t* node_set_brightness;
static menu_node_t* current_node;


void oled_print_arrow(uint8_t row, uint8_t col){
    oled_goto_pos(row, col);
    oled_write_data(0b00011000);
    oled_write_data(0b00011000);
    oled_write_data(0b01111110);
    oled_write_data(0b00111100);
    oled_write_data(0b00011000);
}

void create_linked_list(){
    node_home = (menu_node_t*) malloc(sizeof(menu_node_t));
    node_play_game = (menu_node_t*) malloc(sizeof(menu_node_t));
    node_highscores = (menu_node_t*) malloc(sizeof(menu_node_t));
    node_settings = (menu_node_t*) malloc(sizeof(menu_node_t));
    node_set_brightness = (menu_node_t*) malloc(sizeof(menu_node_t));
    node_calibrate_joystick = (menu_node_t*) malloc(sizeof(menu_node_t));
    current_node = (menu_node_t*) malloc(sizeof(menu_node_t));

    menu_node_init(node_home, "Home", NULL, node_play_game, &print_menu);
    menu_node_init(node_play_game, "1. Play Game", node_home, NULL, NULL);
    menu_node_init(node_highscores, "2. Highscores", node_home, NULL, NULL);
    menu_node_init(node_settings, "3. Settings", node_home, node_calibrate_joystick, &print_settings);
    menu_node_init(node_calibrate_joystick, "1. Calibrate Joystick", node_settings, NULL, NULL);   
    menu_node_init(node_set_brightness, "2. Set brightness", node_settings, NULL, NULL);

    //Create linked lists
    node_play_game->nxt = node_highscores;
    node_play_game->prv = NULL;
    node_highscores->nxt = node_settings;
    node_highscores->prv = node_play_game;
    node_settings->nxt = NULL;
    node_settings->prv = node_highscores;

    node_calibrate_joystick->nxt = node_set_brightness;
    node_calibrate_joystick->prv = NULL;
    node_set_brightness->nxt = NULL;
    node_set_brightness->prv = node_calibrate_joystick;
    
    node_home->head = node_play_game;
    node_home->tail = node_settings;
    node_settings->head = node_calibrate_joystick;
    node_settings->tail = node_set_brightness;
}

void print_loading_screen() {
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
}
void print_settings(){
    oled_clear();
    oled_goto_pos(0,0);
    menu_node_t* current_node = node_settings->head;
    int line = 0;
    oled_write_word(node_home->name);

    while (current_node != current_node->tail) {
        oled_goto_pos(line,0);
        oled_write_word(current_node->name);
        current_node = current_node->nxt;
        line++;
    }
}
void print_menu() {
    oled_clear();
    oled_goto_pos(0,0);
    menu_node_t* current_node = node_home->head;
    int line = 0;
    while (current_node != current_node->tail) {
        oled_goto_pos(line,0);
        oled_write_word(current_node->name);
        current_node = current_node->nxt;
        line++;
    }
}
void menu_node_init(menu_node_t* node, char* name, menu_node_t* parent, menu_node_t* head, void* action){
    node->name = name;
    node->parent = parent;
    node->head = head;
    node->action = action;
}

void menu_init(){
    create_linked_list();
    //printf("%s\n", node_set_brightness->parent->name);
    volatile int joystick_pos = 1;
    volatile int* position = &joystick_pos;
    JOYSTICK menu_joystick;
    print_menu();
    _delay_ms(3000);
    print_settings();

}


void menu_get_position(int *position, JOYSTICK* menu_joystick){
    get_joystick_values(menu_joystick);
    if (menu_joystick->y_direction == UP){
        *position += 1;
    }
    else if (menu_joystick->y_direction == DOWN){
        *position -= 1;
    }
    *position = (*position % 4);
}

