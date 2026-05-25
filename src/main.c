#include "gpio.h"


int main(){
    int *gpio = get_gpiomem_addr();

    unsigned int val = gpio[GPFSEL0 / 4];

    val &= ~(0b111 << (3 * 6));
    val |=  (0b001 << (3 * 6));

    gpio[GPFSEL0 / 4] = val;

    gpio[GPSET0 / 4] = (1 << 6);

    sleep(5);

    gpio[GPCLR0 / 4] = (1 << 6);

    munmap((void*)gpio, 4096);
    

    return 0;
}