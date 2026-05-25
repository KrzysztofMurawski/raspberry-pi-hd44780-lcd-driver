#include "gpio.h"



int *get_gpiomem_addr(){
    int fd = open("/dev/gpiomem", O_RDWR | O_SYNC);
    if (fd == -1){
        perror("Open /dev/gpiomem");
    }

    volatile unsigned int *gpio =
        (volatile unsigned int *)mmap(
            NULL,
            4096,
            PROT_READ | PROT_WRITE,
            MAP_SHARED,
            fd,
            0
        );

    close(fd);
    return gpio;
}