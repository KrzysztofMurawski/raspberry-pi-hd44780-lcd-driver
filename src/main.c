#include "signals.h"


int main(){
    find_gpiomem_base_addr();
    // clear_all_pins();

    init_seq1();
    // init_seq2();
    // usleep(500000);
    send_cmd(0x80);   // DDRAM address = 0 (first position)
    usleep(1000);

    send_data('A');
    send_data('B');
    send_data('c');
    send_data('4');
    send_data('[');
    unmap_gpiomem();

    return 0;
}