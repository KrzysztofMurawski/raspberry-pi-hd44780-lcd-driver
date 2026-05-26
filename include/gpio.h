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

#define GPFSEL0 0x00
// Other SEL registers derived from adding 4 to the above
// Every SEL register manages 10 GPIO pins => 5 SEL registers in total

// SET and CLR registers are calculated similarly
#define GPSET0 0x1C
#define GPCLR0 0x28

//
// Base address for /dev/gpiomem
static volatile uint32_t *gpio_base;
void find_gpiomem_base_addr();  

void sel_pin_as_output(const uint16_t pin_nr);

void set_pin(const uint16_t pin_nr);
void clr_pin(const uint16_t pin_nr);
void read_pin(const uint16_t pin_nr);


void unmap_gpiomem();