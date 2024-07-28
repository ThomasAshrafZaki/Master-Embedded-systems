MEMORY
{
    
    FLASH(RX) : ORIGIN = 0x00000000, LENGTH = 512M
    SRAM(RWX) : ORIGIN = 0x20000000, LENGTH = 512M

}
SECTIONS
{
    .TEXT :
    {
        *(.vectors*)
        *(.text*)
        *(.rodata)
        _End_Text = .;  
        . = ALIGN(4);  
    } > FLASH
    
    .DATA :
    {
        _Start_Data = .;
        *(.data*)
        _End_Data = .;
        . = ALIGN(4);  


    } > SRAM AT> FLASH
    
    .BSS :
    {

        _Start_Bss = .;
        *(.bss*)
        _End_Bss = .;
        . = ALIGN(4);  

    } > SRAM




}