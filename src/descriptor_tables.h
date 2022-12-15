#include "common.h"
struct gdt_entry_struct{
    u16 limit_low; //lower 16 bits of the limit
    u16 base_low; //lower 16 bits of the base
    u8 base_middle;//mext 8 bit of the base
    u8 access; //access flags determine what ring this segment can be used in
    u8 granularity;
    u8 base_high;//the last 8 bits of the base
} __attribute__((packed));

typedef struct gdt_entry_struct gdt_entry_t;

struct gdt_ptr_struct{
    u16 limit; //the upper 16 bits of all selector limits
    u32 base; // The address of the first gdt_entry_t struct
} __attribute__((packed)); //so that gcc doesn't make any change

typedef struct gdt_ptr_struct gdt_ptr_t;

// init function is publicly accessible
void init_descriptor_tables();