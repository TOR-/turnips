#ifndef _KERNEL_GDTIDT_H
#define _KERNEL_GDTIDT_H

void gdt_install();
extern void gdt_flush();

void idt_install();

#endif
