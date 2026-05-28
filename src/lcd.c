#include "lcd.h"

private void lcd_init(){
    find_gpiomem_base_addr();

    clear_all_pins();
    usleep(50000);

    send_cmd(0x33);
    usleep(5000);

    send_cmd(0x33);
    usleep(5000);

    send_cmd(0x33);
    usleep(1000);

    send_cmd(0x32);   // 4-bit mode
    // Page 24 - HITACHI HD44780U manual
    send_cmd(0x28);   // function set
    send_cmd(0x08);   // display OFF
    send_cmd(0x01);   // clear display
    usleep(3000);     // important: >1.5ms safe margin
    send_cmd(0x06);   // entry mode 06
    send_cmd(0x0C);   // display ON 4; cursor ON 2; Cursor blink 1;

}



public void clear_display(){
    send_cmd(1);
}

public void lcd_close(){
    clear_all_pins();
    usleep(2000);
    unmap_gpiomem();
}

public void cursor_cnf(uint8_t cnf){
        send_cmd(0x0C + cnf);   // display ON 4; cursor ON 2; Cursor blink 1;

}

public void put_char(char chr){
    send_data(chr);
}

public void put_text(char *text){
    for (int i = 0; i < strlen(text) && i < 32; ++i){
        if (i==16){
            for (int j = 0; j < 40 - 16; j++){
                send_data(' ');
            }
        }
        send_data(text[i]);
    }
}