#ifndef _KERNEL_GDTIDT_H
#define _KERNEL_GDTIDT_H

void gdt_install();
extern void gdt_flush();

void idt_install();


void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

//installs interrupt service routines
//probably shouldn't be here
void isrs_install();
/* This defines what the stack looks like after an ISR was running */
struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
};

#include <stdint.h>

void outportb (unsigned short _port, unsigned char _data);
void irq_install();

#endif
