#ifndef _MYLIB_UART_H_
#define _MYLIB_UART_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void init_uart0(void);
void init_uart1(void);
void uart0_Transmit(const unsigned char*);
void uart1_Transmit(const unsigned char*);
void uart0_Transmit_Char(const unsigned char);
void uart1_Transmit_Char(const unsigned char);
unsigned char uart0_Receve_Char(void);
unsigned char uart1_Receve_Char(void);

SIGNAL(SIG_UART0_RECV);
//SIGNAL(SIG_UART1_RECV);

#endif
