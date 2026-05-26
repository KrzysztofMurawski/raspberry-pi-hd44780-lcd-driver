#include "gpio.h"


void find_gpiomem_base_addr(){
    int fd = open("/dev/gpiomem", O_RDWR | O_SYNC);
    if (fd == -1){
        perror("Open /dev/gpiomem");
    }

    gpio_base =(volatile uint32_t *)mmap(
            NULL,
            4096,
            PROT_READ | PROT_WRITE,
            MAP_SHARED,
            fd,
            0
        );
    
        if (gpio_base == MAP_FAILED){
            perror("Mapping /dev/gpiomem");
        }

    close(fd);
}

void sel_pin(const uint8_t pin_nr, const unsigned int operation_def){

    if (pin_nr > 57) return;

    const unsigned int sel_reg = GPFSEL0 + (pin_nr / 10) * 4;

    unsigned int val = gpio_base[sel_reg / 4];

    val &= ~(0b111 << (3 * (pin_nr % 10)));
    val |=  (0b001 << (3 * (pin_nr % 10)));

    gpio_base[sel_reg / 4] = val;
}



void set_pin(const uint8_t pin_nr)
{
    if (pin_nr > 57)
        return;

    sel_pin(pin_nr, GPIO_OUTPUT);

    const uint32_t set_reg =
        GPSET0 + ((pin_nr / 32) * 4);


    const uint32_t bit =
        pin_nr % 32;

    gpio_base[set_reg / 4] = (1u << bit);
}


void clr_pin(const uint8_t pin_nr)
{
    if (pin_nr > 57)
        return;

    sel_pin(pin_nr, GPIO_OUTPUT);

    const uint32_t clr_reg =
        GPCLR0 + ((pin_nr / 32) * 4);

    const uint8_t bit =
        pin_nr % 32;

    gpio_base[clr_reg / 4] = (1u << bit);
}

void unmap_gpiomem(){
    if (munmap((void*)gpio_base, 4096) == -1){
        perror("Unmapping /dev/gpiomem");
    }
}

