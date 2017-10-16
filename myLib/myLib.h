//	PE4, PE5 	-> interrupt 4, 5;
//	PA 0-3 		-> select FND digit
//	PC 0-7		-> FND DATA
//	timer 0 use
//	PF 0 		-> ADC
//	PE 0-1		-> UART0

#ifndef _MYLIB_H_
#define _MYLIB_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void init_7seg(void);
void disp_7seg(int);
#define SEG_DATA 	PORTC
#define SEG_SELECT 	PORTD


void init_interrupt(void);
void init_timer0(void);

void init_adc(void);
volatile int adcValue;

void init_uart0(void);
void uart0_Transmit(const unsigned char*);
void uart0_Transmit_Char(const unsigned char);
unsigned char uart0_Receve_Char(void);
volatile unsigned char uart0Char;

#endif
