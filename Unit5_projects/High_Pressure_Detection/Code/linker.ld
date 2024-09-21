
MEMORY {
	SRAM(RWX) : ORIGIN =0x20000000 , LENGTH =20K
	FLASH(RX) : ORIGIN =0x08000000 , LENGTH =128K
}

SECTIONS{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		. = ALIGN(4);
		_end_text = . ;
	} > FLASH
	.data :
	{
		_start_data = . ;
		*(.data*)
		. = ALIGN(4);
		_end_data = . ;
	} > SRAM AT> FLASH
	.bss :
	{
		_start_bss = . ;
		*(.bss*)
		. = ALIGN(4);
		_end_bss = . ;
	} > SRAM 
}