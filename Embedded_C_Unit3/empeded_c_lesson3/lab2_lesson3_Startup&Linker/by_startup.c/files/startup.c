//toggle led by startup.c
//Eng:THOMAS ASHRAF 

#include "platform_t.h"

extern int main(void); 

extern vuint32_t _End_Text;
extern vuint32_t _Start_Data;
extern vuint32_t _End_Data;
extern vuint32_t _Start_Bss;
extern vuint32_t _End_Bss;
extern vuint32_t _stack_top;

void Default_handler();
void reset_handler();
void NMI_handler()  __attribute__((weak,alias("Default_handler")));
void Hard_Fault_handler()  __attribute__((weak,alias("Default_handler")));
void NM_Fault_handler()  __attribute__((weak,alias("Default_handler")));

uint32 vectors[] __attribute__((section(".vectors"))) ={
	(uint32) &_stack_top,
	(uint32) &reset_handler,
	(uint32) &NMI_handler,
	(uint32) &Hard_Fault_handler,
	(uint32) &NM_Fault_handler
	// we used casting like this uint32 not uint32* becouse we want to ensure that this address not a pointer but it store it variable of 4-byte
};

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
void Default_handler(){
	reset_handler();
}
