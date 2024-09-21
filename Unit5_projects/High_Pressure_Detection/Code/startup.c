volatile unsigned char _end_text;
volatile unsigned char _start_data;
volatile unsigned char _end_data;
volatile unsigned char _start_bss;
volatile unsigned char _end_bss;
//init handlers
void Default_handler();
void reset_handler();
void NMI_handler()  __attribute__((weak,alias("Default_handler")));
//init satckTop
static volatile unsigned int stackTop[256];
//init array of Vector Section
void (*const arr[])() __attribute__((section(".vectors")))={
	(void(*)())  stackTop+(sizeof(stackTop)),
	&reset_handler,
	&NMI_handler
};
//reset
void reset_handler(){
	unsigned int i;
	//copy .data
	volatile unsigned char data_size =(volatile unsigned char)&_end_data - (volatile unsigned char)&_start_data;
	volatile unsigned char * ptr1 =&_end_text ;
	volatile unsigned char * ptr2 =&_start_data ;
	for(i=0;i<data_size;i++){
		* ptr2 =* ptr1;
		ptr1++;ptr2++;
	}
	//init .bss
	volatile unsigned char bss_size =(volatile unsigned char)&_end_bss - (volatile unsigned char)&_start_bss;
	ptr1 =&_start_bss ;
	for(i=0;i<data_size;i++){
		* ptr1 =(volatile unsigned char)0;
		ptr1++;
	}
	main();
}
void Default_handler(){
	reset_handler();
}