#include "myLib_Uart.h"
#include "myLib_util.h"
/*
	pc to avr
	uart0 : 115,200 baud, 1stop bit, none perity	
*/ 
void init_uart0(void)
{
	UCSR0B |= 1	<< RXCIE | 1 << RXEN | 1 << TXEN; //Rx, Tx enable
	UCSR0C |= 1 << UCSZ1 | 1 << UCSZ0;			//Rx interrupt set
												//no perity
		 										//1 stop bit
												// 8date
	UBRR0L = 7; 		// 115,200 baud
	sei();
}

void uart0_Transmit(const unsigned char *pChar)
{
	while(*pChar)
	{
		uart0_Transmit_Char(*pChar);
		*pChar++;
	}
}

void uart0_Transmit_Char(const unsigned char pChar)
{
	while(!(UCSR0A & 1 << UDRE0)) 
		; // UDRE check
	UDR0 = pChar;
}

unsigned char uart0_Receve_Char(void)
{
	while(!(UCSR0A & 1 << RXC0)) // RXC0 check
		;
	return UDR0;
}

SIGNAL(SIG_UART0_RECV)
{
	cli();
		modeSelect = uart0_Receve_Char() - '0';
	sei();
}

/*
	avr to bluetooth
	uart1 : 9,600 baud, 1stop bit, none perity	
*/
void init_uart1(void)
{
	UCSR1B |= 1	<< RXCIE | 1 << RXEN | 1 << TXEN; //Rx, Tx enable
	UCSR1C |= 1 << UCSZ1 | 1 << UCSZ0;			//Rx interrupt set
												//no perity
		 										//1 stop bit
												// 8date
	UBRR1L = 7; 		// 115,200 baud
	sei();
}

void uart1_Transmit(const unsigned char *pChar)
{
	while(*pChar)
	{
		uart1_Transmit_Char(*pChar);
		*pChar++;
	}
}

void uart1_Transmit_Char(const unsigned char pChar)
{
	while(!(UCSR1A & 1 << UDRE1)) 
		; // UDRE check
	UDR1 = pChar;
}

unsigned char uart1_Receve_Char(void)
{
	while(!(UCSR1A & 1 << RXC1)) // RXC0 check
		;
	return UDR1;
}

SIGNAL(SIG_UART1_RECV)
{
	cli();
	uart0_Transmit_Char(uart1_Receve_Char());
	sei();

}

