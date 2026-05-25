
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

// Offsets for different GPIO registers
#define GPFSEL0 0x00
#define GPSET0  0x1C
#define GPCLR0  0x28


int *get_gpiomem_addr();  // addr of mmapped /dev/gpiomem

void set_pin(int pin_nr);
void clr_pin(int pin_nr);
void read_pin(int pin_nr);


