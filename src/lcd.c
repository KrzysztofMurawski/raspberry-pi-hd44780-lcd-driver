#include "lcd.h"

void lcd_init(){
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

    send_cmd(0x28);   // function set
    send_cmd(0x08);   // display OFF
    send_cmd(0x01);   // clear display
    usleep(3000);     // important: >1.5ms safe margin
    send_cmd(0x06);   // entry mode
    send_cmd(0x0C);   // display ON

}

void lcd_close(){
    clear_all_pins();
    unmap_gpiomem();
}