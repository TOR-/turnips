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
	terminal_initialize();
}

void kernel_main(void)
{
	printf("Do newlines work?\n");
	printf("(is this on a new line?)\nHow bout this?");
}
