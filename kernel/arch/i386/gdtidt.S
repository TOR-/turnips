/*This will set up our new segment registers. We need to do
	something special in order to set CS. We do what is called a
	far jump. A jump that includes a segment as well as an offset.
	This is declared in C as 'extern void gdt_flush()' */

.globl gdt_flush     # Allows the C code to link to this
.extern gp           # Says that 'gp' is in another file
gdt_flush:
    lgdt gp        # Load the GDT with our 'gp' which is a special pointer
    mov $0x10, %ax     # 0x10 is the offset in the GDT to our data segment
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss
    #jmp 0x08:flush2  # 0x08 is the offset to our code segment: Far jump!
		jmp $0x08, $flush2
flush2:
    ret              # Returns back to the C code!
    
# Loads the IDT defined in '_idtp' into the processor.
# This is declared in C as 'extern void idt_load();'
.globl idt_load
.extern idtp
idt_load:
    lidt idtp
    ret
