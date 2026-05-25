#include "gpio.h"


void set_gpiomem_base_addr(){
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


void set_pin(const uint16_t pin_nr){
    unsigned int val = gpio_base[GPFSEL0 / 4];

    val &= ~(0b111 << (3 * pin_nr));
    val |=  (0b001 << (3 * pin_nr));

    gpio_base[GPFSEL0 / 4] = val;
    gpio_base[GPSET0 / 4] = (1 << pin_nr);
}


void clr_pin(const uint16_t pin_nr){
    unsigned int val = gpio_base[GPFSEL0 / 4];

    val &= ~(0b111 << (3 * pin_nr));
    val |=  (0b001 << (3 * pin_nr));
    
    gpio_base[GPFSEL0 / 4] = val;
    gpio_base[GPCLR0 / 4] = (1 << pin_nr);
}


void unmap_gpiomem(){
    if (munmap((void*)gpio_base, 4096) == -1){
        perror("Unmapping /dev/gpiomem");
    }
}