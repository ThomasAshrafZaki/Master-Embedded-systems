ENTRY(reset)

MEMORY
{
	mem (rwx) : ORIGIN = 0x0 ,LENGTH =64M
}

SECTIONS
{
	. = 0x10000;
	.startup . :
	{
		startup.o(.text)
	}>mem
	.text :
	{
		*(.text) *(.rodata)
	}>mem
	.data :
	{
		*(.data)
	}>mem
	.bss :
	{
		*(.bss) *(COMMON)
	. = . + 0x1000;
	}>mem
	stack_top = . ;
}	
