#ifdef DEBUG 1
	#ifndef _DEBUG_H
	#define _DEBUG_H

	#define BREAK() asm volatile ("int $0x3")

	#endif
#endif
