#pragma once

#include "gpio.h"

#include <stdbool.h>
#include <stdint.h>

// HD44780 supports 4-bit and 8-bit parrallel communication
// 8-bit data bus unsupported !!!
#define OPERATION_LEN 4

// HD44780 pinout to Raspberry Pi GPIO Pins
#define RS_GPIO 17
#define RW_GPIO 27
#define E_GPIO 22

#define DB4_GPIO 13
#define DB5_GPIO 6
#define DB6_GPIO 5
#define DB7_GPIO 16


// Signal Levels
#define HIGH 1
#define LOW 0

// Register Select = HIGH/LOW, Read/Write = HIGH/LOW, 
// Data Bus = 8 bit integer 

struct signal
{
    bool rs;
    bool rw;
    // Expects OPERATION_LEN-bit long integer
    uint8_t db;
};

void send_signal(struct signal sig);
