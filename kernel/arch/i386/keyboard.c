#include <kernel/gdtidt.h>
#include <sys/io.h>
#include <drivers/keyboard.h>

void keyboard_wait_ack()
{
	while((inb(0x64) & 2) == 0);
}

//remove after testing
#include <stdio.h>

// Handles the keyboard interrupt 
void keyboard_handler(struct regs *r)
{
printf("kbdhandler");
	unsigned char scancode;
	// Read from the keyboard's data buffer
	scancode = inb(0x60);
	// If top bit of keyboard byte set : key just released
	if (scancode & 0x80)
	{
			// shift, alt, or control key released
	}
	else
	{
		printf("%#x gg",scancode);
	}
}

void keyboard_install()
{
	irq_install_handler(1,keyboard_handler);
	printf("keyboard installed");
}
