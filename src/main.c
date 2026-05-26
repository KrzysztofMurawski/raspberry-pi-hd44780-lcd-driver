#include "gpio.h"


int main(){
    find_gpiomem_base_addr();

    int pins[] = {5, 6, 17, 20};
    int i = 0;
    while (1){
        
        set_pin(pins[i]);
        usleep(100000);
        clr_pin(pins[i]);
        i++;
        if(i==4){
            i = 0;
        }
    }
    return 0;
}