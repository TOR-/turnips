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
	char *ptr = "Hello world!";
	char *np = 0;
	int i = 5;
	unsigned int bs = sizeof(int)*8;
	int mi;

	mi = (1 << (bs-1)) + 1;
	printf("%s\n", ptr);
	printf("printf test\n");
	printf("%s is null pointer\n", np);
	printf("%d = 5\n", i);
	printf("%d = - max int\n", mi);
	printf("char %c = 'a'\n", 'a');
	printf("hex %x = ff\n", 0xff);
	printf("hex %02x = 00\n", 0);
	printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
	printf("%d %s(s)", 0, "message");
	printf("\n");
	printf("%d %s(s) with %%\n", 0, "message");
	pci_check_peripherals();
}
