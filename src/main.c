#include "lcd.h"


int main(){

    lcd_init();
    // init_seq2();
    // usleep(500000);
    send_cmd(0x80);   // DDRAM address = 0 (first position)
    usleep(1000);
    send_data('N');
    send_data('o');
    send_data(' ');
    send_data('H');
    send_data('e');
    send_data('l');
    send_data('o');
    send_data('o');
    send_data('u');
    lcd_close();

    return 0;
}