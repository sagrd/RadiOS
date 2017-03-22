#ifndef IDT_H
#define IDT_H

#include "types.h"

//selector
#define KERNEL_CS 0x08
#define IDT_ENTRIES 256

typedef struct { //each element of interupt disruptor table(array of 256 element)
    uint16 low_offset;
    uint16 sel; //selector
    uint8 always0;//tells a processor where a certain interupt can be executed from the kernel or userspace
    uint8 flags; 
    uint16 high_offset;
    //attribute tells compiler not to add anything else hence packed.
} __attribute__((packed)) idt_gate_t ;

//interupt descriptor table total size = 16+32 = 48 bits
typedef struct {
    uint16 limit; //size of idt array
    uint32 base; //address of the element of idt array
} __attribute__((packed)) idt_register_t;


idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg; //idt_reg takes first address and size of array idt[IDT_ENTRIES]


void set_idt_gate(int n, uint32 handler);
void set_idt();

#endif
