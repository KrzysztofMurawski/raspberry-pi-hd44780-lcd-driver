#pragma once

#include "signals.h"
#include <string.h>

#define public __attribute__((visibility("default")))
#define private __attribute__((visibility("hidden"))) static
#define init __attribute__((constructor))

#define DISPLAY_ROWS 2
#define DISPLAY_COLUMNS 16

#define BLINK_ON 1
#define BLINK_OFF 0
#define CURSOR_ON 2
#define CURSOR_OFF 0

private init void lcd_init();

public void lcd_close();

public void clear_display();

public void cursor_cnf(uint8_t cnf);

public void put_char(char chr);

public void put_text(char *text);