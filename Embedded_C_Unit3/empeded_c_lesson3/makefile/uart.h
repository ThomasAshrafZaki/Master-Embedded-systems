
#ifndef UART_H_
#define UART_H_
typedef volatile unsigned char  vuint8_t;
void uart_send_string(vuint8_t * uart_tx_string);

#endif