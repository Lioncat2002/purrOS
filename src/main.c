
#include "monitor.h"
#include "string.h"
int main(struct multiboot *mboot_ptr){
    monitor_clear();
    monitor_write("PurrOS lucipurr\n");
    monitor_write("version: 0.2\n");

    if(strcmp("bruh","bruh")==0){
        monitor_write("bruh strcmp works!\n");
    }

    return 0xCAFEBABE;
}