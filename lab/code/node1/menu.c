
#include "node1_USART.h"
#include "node1_memory_map.h"
#include <util/delay.h>
#include "node1_joystick.h"
#include "node1_slider.h"
#include "node1_oled.h"
#include "menu.h"

static menu_node_t* node_home;
static menu_node_t* node_exit;
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

void oled_clear_arrow(uint8_t row, uint8_t col){
    oled_goto_pos(row, col);
    for (int i = 0; i < 10; ++i){
        oled_write_data(0x00);
    }
}

void menu_node_init(menu_node_t* node, char* name, int num_siblings, menu_node_t* parent, menu_node_t* first_child, menu_node_t* head, menu_node_t* tail, void* action){
    node->name = name;
    node->num_siblings = num_siblings;
    node->parent = parent;   
    node->first_child = first_child;
    node->head = head;
    node->tail = tail;
    node->action = action;
}

void create_linked_list(){
    node_home = (menu_node_t*) malloc(sizeof(menu_node_t));
    node_exit = (menu_node_t*) malloc(sizeof(menu_node_t));
    node_play_game = (menu_node_t*) malloc(sizeof(menu_node_t));
    node_highscores = (menu_node_t*) malloc(sizeof(menu_node_t));
    node_settings = (menu_node_t*) malloc(sizeof(menu_node_t));
    node_set_brightness = (menu_node_t*) malloc(sizeof(menu_node_t));
    node_calibrate_joystick = (menu_node_t*) malloc(sizeof(menu_node_t));
    current_node = (menu_node_t*) malloc(sizeof(menu_node_t));

    menu_node_init(node_home, "1. Enter Main Menu", 2, NULL, node_play_game, node_home, node_exit, &print_menu);
    menu_node_init(node_exit, "2. Exit", 2, NULL, NULL, node_home, node_exit, NULL);
    menu_node_init(node_play_game, "1. Play Game", 3, node_home, NULL, node_play_game, node_settings, NULL);
    menu_node_init(node_highscores, "2. Highscores", 3, node_home, NULL, node_play_game, node_settings, NULL);
    menu_node_init(node_settings, "3. Settings", 3, node_home, node_calibrate_joystick, node_play_game, node_settings, &print_menu);
    menu_node_init(node_calibrate_joystick, "1. Calibrate Joystick", 2, node_settings, NULL, node_calibrate_joystick, node_set_brightness, NULL);   
    menu_node_init(node_set_brightness, "2. Set brightness", 2, node_settings, NULL, node_calibrate_joystick, node_set_brightness, NULL);

    //Create linked lists
    node_home->nxt = node_exit;
    node_home->prv = NULL;
    node_exit->nxt = NULL;
    node_exit->prv = node_home;

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

void print_menu(menu_node_t* node) {
    oled_clear();
    menu_node_t* curr_node = node->head;
    int line = 0;
    while (curr_node != node->tail) {
        oled_goto_pos(line,10);
        oled_write_word(curr_node->name);
        curr_node = curr_node->nxt;
        line++;
    }
    oled_goto_pos(line,10);
    oled_write_word(node->tail->name);
}


void menu_init(){
    create_linked_list();
    //printf("%s\n", node_set_brightness->parent->name);
    volatile int joystick_pos = 0;
    JOYSTICK menu_joystick;
    current_node = node_home;
    int linked_list_len = current_node->num_siblings;
    print_menu(current_node);
    while(1){
        get_joystick_values(&menu_joystick);
        if (menu_joystick.y_direction == UP) {
            if (joystick_pos == 0){
                joystick_pos = linked_list_len-1;
                current_node = current_node->tail;
            } else {
                (joystick_pos)--;
                current_node = current_node->prv;
            }
        }
        if (menu_joystick.y_direction == DOWN) {
            if (joystick_pos == linked_list_len-1){
                joystick_pos = 0;
                current_node = current_node->head;
            } else {
                (joystick_pos)++;
                current_node = current_node->nxt;
            }
        }
        if ((menu_joystick.x_direction == RIGHT) && (current_node->first_child != NULL)){
            (*current_node->action)(current_node->first_child);
            current_node = current_node->first_child;
            joystick_pos = 0;
        }
        if ((menu_joystick.x_direction == LEFT) && (current_node->parent != NULL)){
            current_node = current_node->parent;
            (*current_node->action)(current_node);
            joystick_pos = 0;
        }
        linked_list_len = current_node->num_siblings;
        joystick_pos = abs(joystick_pos % linked_list_len);

        printf("pos %d\t", joystick_pos);
        printf("node is at %s\n", current_node->name);

        oled_print_arrow(joystick_pos,0);

        uint8_t neutral = 50;
        int diff = abs(((int)neutral - (int)menu_joystick.y_analog)/5);
        int delay_time = (1000/(diff+1));
        printf("speed: %d\n", delay_time);
        if (diff > 1) {
            for (int i = 0; i < delay_time; i++) {
                _delay_ms(1);
            }
        } else  {
            _delay_ms(200);
        }
        oled_clear_arrow(joystick_pos,0);
    }
    _delay_ms(3000);
    print_settings();
}

void menu_loop(){

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

