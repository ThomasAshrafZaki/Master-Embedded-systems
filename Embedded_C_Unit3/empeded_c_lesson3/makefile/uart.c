#include "uart.h"
#include "platform_t.h"
#define UART0DR  *(( vuint8_t*)((vuint8_t*)(0x101f1000+0x0)))
void uart_send_string(vuint8_t * uart_tx_string)
{
	while(*uart_tx_string !='\0')
	{
		UART0DR = *uart_tx_string;
		uart_tx_string++;
	}
}