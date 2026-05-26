#include "signals.h"



void send_signal(struct signal sig){
    if (sig.rs){
        set_pin(RS_GPIO);
    } else {
        clr_pin(RS_GPIO);
    }
        
    if (sig.rw){
        set_pin(RW_GPIO);
    } else {
        clr_pin(RW_GPIO);
    }

    if (OPERATION_LEN == 4){
        if (sig.db % 2 == 1){
            set_pin(DB4_GPIO);
        } else {
            clr_pin(DB4_GPIO);
        }

        sig.db /= 2;

        if (sig.db % 2 == 1){
            set_pin(DB5_GPIO);
        } else {
            clr_pin(DB5_GPIO);
        }

        sig.db /= 2;

        if (sig.db % 2 == 1){
            set_pin(DB6_GPIO);
        } else {
            clr_pin(DB6_GPIO);
        }

        sig.db /= 2;

        if (sig.db % 2 == 1){
            set_pin(DB7_GPIO);
        } else {
            clr_pin(DB7_GPIO);
        }

    } else {
        perror("Unsupported Operation length");
    }
    
}