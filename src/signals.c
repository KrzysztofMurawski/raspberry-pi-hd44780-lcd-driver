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
    set_db_gpio_pins(cmd_4bit);
    usleep(5000);
    pulse_e(PULSE_TIME);
    clear_all_pins();
}

void set_db_gpio_pins(uint8_t data){
    int to_write = 0b0;
    for (int i = 7; i >= 8 - OPERATION_LEN; i--){
        if(data % 2){
            to_write |= (1u << data_bus_gpios[i]);
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

void send_data_4bits(uint8_t data_4bit){
    write_data_to_gpio(data_4bit % 16);
    usleep(WAIT_AFTER_SENDING);
}
void send_cmd_4bits(uint8_t cmd){
    write_cmd_to_gpio(cmd % 16);
    usleep(WAIT_AFTER_SENDING);
}

void init_seq1(){
    clear_all_pins();
    usleep(50000);

    send_cmd(0x33);
    usleep(5000);

    send_cmd(0x33);
    usleep(5000);

    send_cmd(0x33);
    usleep(1000);

    send_cmd(0x32);   // 4-bit mode

    send_cmd(0x28);   // function set
    send_cmd(0x08);   // display OFF
    send_cmd(0x01);   // clear display
    usleep(3000);     // important: >1.5ms safe margin
    send_cmd(0x06);   // entry mode
    send_cmd(0x0C);   // display ON

}
void init_seq2(){
    clear_all_pins();
    send_cmd_4bits(2);
    send_cmd_4bits(2);
    send_cmd_4bits(0);
    send_cmd_4bits(0);
    send_cmd_4bits(14);

    send_cmd_4bits(0);
    send_cmd_4bits(6);

    send_data_4bits(4);
    send_data_4bits(8);

};