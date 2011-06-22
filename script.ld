ENTRY(ResetISR)
/*ENTRY(_start)*/
GROUP(-lgcc -lc -lDriversLPC17xxgnu)

MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K
	SRAM (rwx) : ORIGIN = 0x10000000, LENGTH = 32K
}

/* Section Definitions */
SECTIONS
{
	/* read-only */
   .text :
	{
		KEEP(*(.isr_vector .isr_vector.*))
		*(.text .text.*)
		*(.gnu.linkonce.t.*)
		*(.glue_7)
		*(.glue_7t)
		*(.gcc_except_table)
		*(.rodata .rodata*)
		*(.gnu.linkonce.r.*)
				
		/*_etext = .;*/
	} > FLASH

	/* .ARM.exidx is sorted, so has to go in its own output section.  */
	__exidx_start = .;
	.ARM.exidx   : { *(.ARM.exidx* .gnu.linkonce.armexidx.*) } > FLASH
	__exidx_end = .;

	.text.align :
	{
		. = ALIGN(8);
		_etext = .;
	} > FLASH

	/* random access */
	.data : AT (_etext)
	{
		_data = .;
		*(vtable vtable.*)
		*(.data .data.*)
		*(.gnu.linkonce.d*)
		. = ALIGN(8);
		_edata = . ;
	} > SRAM
 
	/* .bss section which is used for uninitialized data */
	.bss (NOLOAD) :
	{
		_bss = . ;
		*(.bss .bss.*)
		*(.gnu.linkonce.b*)
		*(COMMON)
		. = ALIGN(8);
		_ebss = . ;
	} > SRAM
  
	_end = . ;
	PROVIDE (end = .);
  
	.heap (NOLOAD) :
	{
		KEEP(*(.heap))
	} > SRAM
  
	.stack (NOLOAD):
	{
		*(.stack)
		_estack = .;
		PROVIDE(estack = .);
	} > SRAM
       
  /*.stackarea (NOLOAD) :
  {
	*(.stackarea .stackarea.*)
	. = ALIGN(8);
	/*_estack = .;
    PROVIDE(estack = .);
  } > SRAM*/
}