/*startup cortex-m3
by:Eng THOMAS ASHRAF
*/


.section .vectors 
.word  0x20001000       /*stack top*/
.word  _reset           /*RESET*/
.word  vector_handler  /*MNI*/
.word  vector_handler  /*Hard Fault*/
.word  vector_handler  /*MM Fault*/ 
.word  vector_handler	/*Bus Fault*/
.word  vector_handler  /*Uasge Fault*/
.word  vector_handler	/*Reserved*/
.word  vector_handler	/*Reserved*/
.word  vector_handler	/*Reserved*/
.word  vector_handler	/*Reserved*/
.word  vector_handler	/*sv call*/
.word  vector_handler	/*Debug reserved*/
.word  vector_handler	/*Reserved*/	
.word  vector_handler	/*Pendsv*/
.word  vector_handler	/*Systick/
.word  vector_handler	/*IRQ0*/
.word  vector_handler	/*IRQ1*/
.word  vector_handler	/*IRQ2*/ 
.word  vector_handler	/*...*/ 

.section .text
_reset :
	bl main
	b .
.thumb_func
vector_handler :
	b _reset
