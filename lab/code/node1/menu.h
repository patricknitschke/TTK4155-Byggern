#include "node1_USART.h"
#include "node1_memory_map.h"
#include <util/delay.h>
#include "node1_SRAM_test.h"
#include "node1_joystick.h"
#include "node1_slider.h"
#include "node1_oled.h"

#ifndef MENU_H_
#define MENU_H_


void menu_init();

void menu_print();

void menu_run(int* position);

void menu_get_position(int *position, JOYSTICK* menu_joystick);

void menu_test_joystick();
#endif