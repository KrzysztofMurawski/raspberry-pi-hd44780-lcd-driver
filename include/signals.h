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

// microseconds
#define PULSE_TIME 10
#define WAIT_BETWEEN_NIBBLES_TIME 5000
#define WAIT_AFTER_SENDING 10000


// Public API
// Sends full byte of data/instruction in two nibbles
void send_data(uint8_t data_8bit);
void send_cmd(uint8_t cmd);
// Sends 4 bits (one nibble) of data/instr 
// Only 4 lower order bits are sent when full byte is given
void send_data_4bits(uint8_t data_8bit);
void send_cmd_4bits(uint8_t cmd);

void clear_all_pins();

static void write_data_to_gpio(uint8_t data_4bit);
static void write_cmd(uint8_t cmd);
static void pulse_e(uint32_t time);
static void set_db_gpio_pins(uint8_t data);

void init_seq1();
void init_seq2();