#ifndef COMMON_H
#define COMMON_H

typedef unsigned int u32;
typedef int i32;
typedef unsigned short u16;
typedef short i16;
typedef unsigned char u8;
typedef char i8;

void outb(u16 port, u8 value);
u8 inb(u16 port);
u16 inw(u16 port);

#endif