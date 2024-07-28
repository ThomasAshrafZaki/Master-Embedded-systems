#include "uart.h"
#include "platform_t.h"
vuint8_t  buffer[100]="learn-in-depth:thomas";
void main(void)
{
	uart_send_string(buffer);
}
