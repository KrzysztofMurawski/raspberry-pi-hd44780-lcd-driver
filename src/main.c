#include "lcd.h"


int main(){

    lcd_init();
    // init_seq2();
    // usleep(500000);
    send_cmd(0x80);   // DDRAM address = 0 (first position)
    usleep(1000);

    send_data('A');
    
    // char text_to_write[] = "Some example text to write";

    // for (int i = 0; i < strlen(text_to_write); i++){
    //     send_data(text_to_write[i]);
        
    // }

    lcd_close();

    return 0;
}