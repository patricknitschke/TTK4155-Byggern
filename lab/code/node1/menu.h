#include "node1_USART.h"
#include "node1_memory_map.h"
#include <util/delay.h>
#include "node1_joystick.h"
#include "node1_slider.h"
#include "node1_oled.h"

#ifndef MENU_H_
#define MENU_H_

typedef struct menu_node_t {
    char* name;
    struct menu_node_t* parent;
    struct menu_node_t* first_child;
    struct menu_node_t* head;
    struct menu_node_t* tail;
    struct menu_node_t* nxt;
    struct menu_node_t* prv;
    int num_siblings; //including the node itself == length of linked list
    void (*action)();
} menu_node_t;

void oled_print_arrow(uint8_t row, uint8_t col);

void create_linked_list();

void print_loading_screen();

void print_settings();

void print_menu();

void menu_node_init(menu_node_t* node, char* name, int num_siblings, menu_node_t* parent,menu_node_t* first_child, menu_node_t* head, menu_node_t* tail, void* action);

void menu_init();

void menu_get_position(int *position, JOYSTICK* joystick);

#endif