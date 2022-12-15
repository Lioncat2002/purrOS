
#include "monitor.h"
int main(struct multiboot *mboot_ptr){
    monitor_clear();
    monitor_write("PurrOS Muchkin\n");
    monitor_write("version: 0.2\n");
    return 0xCAFEBABE;
}