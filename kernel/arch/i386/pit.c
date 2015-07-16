#include <kernel/gdtidt.h>
#include <drivers/pit.h>
#include <stdio.h>

/* This will keep track of how many ticks that the system
*	has been running for */
unsigned long timer_ticks = 0;

void timer_handler(struct regs *r)
{
		/* Increment our 'tick count' */
		timer_ticks++;

		/* Every 18 clocks (approximately 1 second), we will
		*	display a message on the screen */
		if (timer_ticks % 18 == 0)
		{
				printf("One second has passed\n");
		}
}

/* This will continuously loop until the given time has
*	been reached */
void timer_wait(unsigned long ticks)
{
		unsigned long eticks;

		eticks = timer_ticks + ticks;
		while(timer_ticks < eticks);
}

void timer_install()
{
	printf("timer installed");
	irq_install_handler(0, timer_handler);
}
