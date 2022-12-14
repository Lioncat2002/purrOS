
#include "monitor.h"
int main(struct multiboot *mboot_ptr){
    monitor_clear();
    monitor_write("PurrOS Deadalus\n");
    monitor_write("version: 0.2\n");
    return 0xDEADBABA;
}