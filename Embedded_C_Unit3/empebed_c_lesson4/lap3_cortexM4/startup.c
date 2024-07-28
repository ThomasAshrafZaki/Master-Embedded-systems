// startup.c by using array of pointer to function (.vectors)
//Eng:THOMAS ASHRAF 

#include "platform_t.h"

extern int main(void); 

//decleration of variables to use there address
extern vuint32_t _End_Text;
extern vuint32_t _Start_Data;
extern vuint32_t _End_Data;
extern vuint32_t _Start_Bss;
extern vuint32_t _End_Bss;
//decleration of funcions
void Default_handler();
void reset_handler();
void NMI_handler()  __attribute__((weak,alias("Default_handler")));
void Hard_Fault_handler()  __attribute__((weak,alias("Default_handler")));
void NM_Fault_handler()  __attribute__((weak,alias("Default_handler")));

//un init array of unsigned int to make stack_top (the size of stack =1024byte) ---->1024/4= 256 element
static vuint32_t stack_top[256]; //store in .bss

//array of pointer to function to return void (.vectors)
void(*const G_P_Array[])() __attribute__((section(".vectors")))={
	(void(*)()) (stack_top + sizeof(stack_top)),
	&reset_handler,
	&NMI_handler,
	&Hard_Fault_handler,
	&NM_Fault_handler
};
//reset ()

void reset_handler(){
    //copy the .data from flash to sram in run time
    vuint32_t data_size =(vuint32_t)&_End_Data - (vuint32_t)&_Start_Data;
    vuint8_t * p_scr = (vuint8_t *)&_End_Text;//the end byte before storing .data in flash
    vuint8_t * p_dst = (vuint8_t *)&_Start_Data;//the first byte for storing .data in sram
    for (int i = 0; i < data_size; ++i)
    {
        * p_dst ++ = * p_scr ++;
    }
    //init .bss in sram in run time
    vuint32_t bss_size =(vuint32_t)&_End_Bss - (vuint32_t)&_Start_Bss;
    p_dst = (vuint8_t *)&_Start_Bss;//the first byte for storing .bss in sram
    for (int i = 0; i < bss_size; ++i)
    {
        * p_dst ++ = (vuint8_t)0;//vuint8_t not vuint8_t* becouse * p_dst is value not pointer
    }
    //jump main
    main();
}
//default handler ()
void Default_handler(){
	reset_handler();
}
