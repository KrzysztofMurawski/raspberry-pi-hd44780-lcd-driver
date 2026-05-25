#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>

#include <sys/mman.h>

// Offsets for different GPIO registers
#define GPFSEL0 0x00
#define GPSET0  0x1C
#define GPCLR0  0x28

// Base address for /dev/gpiomem
static volatile uint32_t *gpio_base;
void set_gpiomem_base_addr();  

void set_pin(const uint16_t pin_nr);
void clr_pin(const uint16_t pin_nr);
void read_pin(const uint16_t pin_nr);


void unmap_gpiomem();