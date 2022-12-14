#include "monitor.h"

u16 *video_memory = (u16 *)0xB8000; // VGA frame buffer;
u8 cursor_x = 0;
u8 cursor_y = 0;

static void move_cursor()
{
    u16 cursorLocation = cursor_y * 80 + cursor_x;
    outb(0x3D4, 14);                  // setting high curosr byte to VGA
    outb(0x3D5, cursorLocation >> 8); // send high cursor byte
    outb(0x3D4, 15);                  // Setting low cursor byte
    outb(0x3D5, cursorLocation);      // send low curosr byte
}

static void scroll()
{
    u8 attributeByte = (0 /*black*/ << 4) | (15 /*white*/ & 0x0F);
    u16 blank = 0x20 /*space*/ | (attributeByte << 8);
    // row 25 is end
    if (cursor_y >= 25)
    {
        int i;
        for (i = 0; i < 24 * 80; i++)
        {
            video_memory[i] = video_memory[i + 80];
        }

        // last line should be blank now so change it to spaces
        for (i = 24 * 80; i < 25 * 80; i++)
        {
            video_memory[i] = blank;
        }
        cursor_y = 24;
    }
}

void monitor_put(char c)
{
    u8 backColor = 0;  // black
    u8 foreColor = 15; // white

    u8 attributeByte = (backColor << 4) | (foreColor & 0x0F);
    u16 attribute = attributeByte << 8;
    u16 *location;

    if (c == 0x08 && cursor_x) // handle backspace
        cursor_x--;
    else if (c == 0x09) // handle tab but only to a point where it's divisible by 8
        cursor_x = (cursor_x + 8) & ~(8 - 1);
    else if (c == '\r')
        cursor_x = 0;
    else if (c == '\n')
    {
        cursor_x = 0;
        cursor_y++;
    }
    else if (c >= ' ')
    {
        location = video_memory + (cursor_y * 80 + cursor_x);
        *location = c | attribute;
        cursor_x++;
    }
    if (cursor_x >= 80)
    {
        cursor_x = 0;
        cursor_y++;
    }
    scroll();
    move_cursor();
}

void monitor_clear(){
    u8 attributeByte = (0 << 4) | (15 & 0x0F);
    u16 blank = 0x20 | (attributeByte << 8);
    int i;
    for (i = 0; i < 80 * 25;i++){
        video_memory[i] = blank;
    }
    cursor_x = 0;
    cursor_y = 0;
    move_cursor();
}

void monitor_write(char *c){
    int i = 0;
    while(c[i]){
        monitor_put(c[i++]);
    }
}