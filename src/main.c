#include "signals.h"


int main(){
    find_gpiomem_base_addr();

    // int pins[] = {22, 27, 17, 16, 5, 6, 13};
    // int i = 0;
    // while (1){
        
    //     set_pin(pins[i]);
    //     usleep(600000);
    //     clr_pin(pins[i]);
    //     i++;
    //     if(i==7){
    //         i = 0;
    //     }
    // }

    struct signal sig1;
    sig1.rs = LOW;
    sig1.rw = HIGH;
    sig1.db = 0b1110;

    send_signal(sig1);

    printf("%d\n", sig1.db);

    return 0;
}