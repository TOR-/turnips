#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdtidt.h>
#include <drivers/pci.h>

#define DEBUG 1

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
	extern uint32_t endkernel;
	// asm volatile ("int $0x3"); Breakpoint Exception
	//pci_check_peripherals();
	printf("EEEEEEEEEEEE");
}
