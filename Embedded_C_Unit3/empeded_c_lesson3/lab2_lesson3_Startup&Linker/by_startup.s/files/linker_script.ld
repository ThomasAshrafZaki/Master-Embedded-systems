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
	}>flash

	.DATA : {
		*(.data)
	}>flash

	.BSS : {
		*(.bss)
	}>sram
}