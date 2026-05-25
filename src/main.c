#include "gpio.h"


int main(){
    set_gpiomem_base_addr();

    int pins[] = {5, 6, 2, 3};
    int i = 0;
    while (1){
        set_pin(pins[i]);
        usleep(10000);
        clr_pin(pins[i]);
        i++;
        if(i==4){
            i = 0;
        }
    }
    return 0;
}