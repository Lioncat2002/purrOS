
#include "monitor.h"
#include "string.h"
int main(struct multiboot *mboot_ptr){
    monitor_clear();
    monitor_write("PurrOS lucipurr\n");
    monitor_write("version: 0.2\n");

    char s[20] = "bruh";
    char s1[40] = "meow";
    strcpy(s1,s);

    if(strcmp("bruh","bruh")==0){
        monitor_write(s1);
    }

    return 0xCAFEBABE;
}