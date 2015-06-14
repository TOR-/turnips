#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdtidt.h>

void kernel_early(void)
{
	gdt_install();
	idt_install();
	isrs_install();
	irq_install();
	__asm__ __volatile__ ("sti"); 
	terminal_initialize();
}

void kernel_main(void)
{
	printf("Do newlines work?\n");
	printf("(is this on a new line?)\nHow bout this?");
	asm volatile ("int $0x3");
	//printf("Divide this!!!!  %d / %d = %d\n",7,0,7/0); 
}
