#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>

#include <sys/mman.h>

//
// Offsets for different GPIO registers
// Found in BCM2711 ARM Peripherals documentation
//
#define GPFSEL0 0x00
// Other SEL registers derived from adding 4 to the above
// Every SEL register manages 10 GPIO pins => 5 SEL registers in total
//
// SET and CLR registers are calculated similarly
#define GPSET0 0x1C
#define GPCLR0 0x28

//
// GPIO operation definitions
#define GPIO_INPUT 0b000
#define GPIO_OUTPUT 0b001
//
// Base address for /dev/gpiomem
static volatile uint32_t *gpio_base;
void find_gpiomem_base_addr();  

// operation_def - 0b001 for selecting pin as output (GPIO_OUTPUT)
//                 0b000 for input (GPIO_INPUT)
//                 0b010 - 0b111 for alternate functions
void sel_pin(const uint8_t pin_nr, const unsigned int operation_def);

void pin_high(const uint8_t pin_nr);
void pin_low(const uint8_t pin_nr);
void read_pin(const uint8_t pin_nr); // TODO

void clr_pins(const uint32_t pins);
void set_pins(const uint32_t pins);

void unmap_gpiomem();

