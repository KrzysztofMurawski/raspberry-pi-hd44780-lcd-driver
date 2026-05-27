#include "signals.h"


int data_bus_gpios[] = {0, 0, 0, 0, DB4_GPIO, DB5_GPIO, DB6_GPIO, DB7_GPIO};


void clear_all_pins(){
    int to_write = 0b0;
    for (int i = 0; i < 8; i++){
        to_write |= (1u << data_bus_gpios[i]);
    }
    to_write |= (1u << RS_GPIO);
    to_write |= (1u << RW_GPIO);
    to_write |= (1u << E_GPIO);

    clr_pins(to_write);
}


void pulse_e(uint32_t time){
    pin_high(E_GPIO);
    usleep(time);
    pin_low(E_GPIO);
}


void write_data_to_gpio(uint8_t data_4bit){
    pin_high(RS_GPIO);
    pin_low(RW_GPIO);
    set_db_gpio_pins(data_4bit);
    pulse_e(PULSE_TIME);
    clear_all_pins();
}

void write_cmd_to_gpio(uint8_t cmd_4bit){
    pin_low(RS_GPIO);
    pin_low(RW_GPIO);
    printf("%d\n", cmd_4bit);
    set_db_gpio_pins(cmd_4bit);
    usleep(5000);
    pulse_e(PULSE_TIME);
    clear_all_pins();
}

void set_db_gpio_pins(uint8_t data){
    int to_write = 0b0;
    for (int i =4; i < 8 ; i++){
        if(data % 2){
            to_write |= (1u << data_bus_gpios[i]);
            printf("%d %d %d\n", data, i, data_bus_gpios[i]);
        }
        data /= 2;
    }
    set_pins(to_write);
}


void send_data(uint8_t data_8bit){
    write_data_to_gpio(data_8bit / 16);
    usleep(WAIT_BETWEEN_NIBBLES_TIME);
    write_data_to_gpio(data_8bit % 16);
    usleep(WAIT_AFTER_SENDING);
}

void send_cmd(uint8_t cmd){
    write_cmd_to_gpio(cmd / 16);
    usleep(WAIT_BETWEEN_NIBBLES_TIME);
    write_cmd_to_gpio(cmd % 16);
    usleep(WAIT_AFTER_SENDING);
}

