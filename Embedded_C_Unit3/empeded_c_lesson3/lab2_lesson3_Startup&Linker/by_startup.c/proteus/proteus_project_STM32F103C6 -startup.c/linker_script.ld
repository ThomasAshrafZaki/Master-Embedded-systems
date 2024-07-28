/*linker_script cortec-m3
by eng THOMAS ASHRAF 
*/


MEMORY
{
	sram(RWX) :ORIGIN =0x20000000 , LENGTH =20K
	flash(RX) :ORIGIN =0x08000000 , LENGTH =128K
}	

SECTIONS
{
	.TEXT : {
		*(.vectors)
		*(.text)
		*(.rodata)
		_End_Text = .;
	}>flash

	.DATA : {
		_Start_Data = .;
		*(.data)
		. = ALIGN(4);
		_End_Data = .;

	}>sram AT>flash

	.BSS : {
		_Start_Bss = .;
		*(.bss)
		. = ALIGN(4);
		_End_Bss = .;
		. = . + 0x1000 ;
		_stack_top = . ;
	}>sram
}