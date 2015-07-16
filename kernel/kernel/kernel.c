#define DEBUG 1

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdtidt.h>
#include <drivers/pci.h>
#include <drivers/keyboard.h>
#include <drivers/pit.h>

void kernel_early(void)
{
	gdt_install();
	idt_install();
	isrs_install();	
	irq_install();
	terminal_initialize();
	timer_install();
	keyboard_install();
	__asm__ __volatile__ ("sti"); 
	
	
}

void kernel_main(void)
{
	//extern uint32_t endkernel;
	//pci_check_peripherals();
	printf("EEEEEEEEEEEE");
	timer_wait(30);
	printf("Waited");
}
