#pragma once

#include "signals.h"
#include <string.h>


#define DISPLAY_ROWS 2
#define DISPLAY_COLUMNS 16

#define BLINK_ON 1
#define BLINK_OFF 0
#define CURSOR_ON 2
#define CURSOR_OFF 0

void lcd_init();

void lcd_close();

void clear_display();

void cursor_cnf(uint8_t cnf);

void put_char(char chr);

void put_text(char *text);