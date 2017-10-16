#include "myLib.h"

void init_7seg(void)
{
	DDRC=0xFF;
	DDRD|=0xF;
}

void disp_7seg(int num)
{
	SEG_SELECT = 0x00;

	const unsigned char segment[10]= { 0x3f, 0x06, 0x5b, 0x4f,
									   0x66, 0x6D, 0x7D, 0x27,
								 	   0x7f, 0x6f};

	int num1 = num/1000;
	SEG_SELECT = ~(1 << 0);
	SEG_DATA = segment[num1];
	_delay_ms(5);
	
	int num2 = num/100%10;
	SEG_SELECT = ~(1 << 1);
	SEG_DATA = segment[num2];
	_delay_ms(5);

	int num3 = num/10%10;
	SEG_SELECT = ~(1 << 2);
	SEG_DATA = segment[num3];
	_delay_ms(5);

	int num4 = num%10;
	SEG_SELECT = ~(1 << 3);
	SEG_DATA = segment[num4];
	_delay_ms(5);
}

void init_interrupt(void)
{
	//  USE EXIT 4 
	EIMSK |= 1 << INT4 | 1 << INT5;
	//  TRIGGER OF EXIT
	EICRB |= 1 << ISC51 | 1 << ISC50 | 1 << ISC41 | 1 << ISC40;
	//  SREG I bit setting
	sei(); 
}

SIGNAL(SIG_INTERRUPT4)
{
	// interrupt block
	cli();
		
	//do it
	
	// interrupt activate
	sei();
}

SIGNAL(SIG_INTERRUPT5)
{
	// interrupt block
	cli();
		
	//do it
	
	// interrupt activate
	sei();
}




void init_timer0(void)
{
	//WGM(1:0)  = "00"
	//COM0(1:0) = "00"
	//CS0(2:0)	= "111" -PRESCAILER 1024
	TCCR0 = 0x07;
	//(1/(14745600Hz / 1024 presaler)) * 80 -> 0.022s
	TCNT0 = 0xff - 80; 
	//timer overflow interrupt
	TIMSK |=  1<<TOIE0;
	//timer0 overflow flag
	TIFR |=  1<<TOV0;
	sei();
}

void init_adc(void)
{
/*
	//REFS(1:0 = "11" internal 2.56V
	//ADLAR = "0" Default right sorting
	//MUX(4:0) = "00000" ADC0 ´Ü±Ø¼º
	ADMUX = 0xC0;
	//ADFR = "1" Free running
	//ADPS = "110" 64 prescailer
	//ADEN = "1" ADC Enable
	ADSCR = 0xA6;
	//ADC conversion start
	ADSCR |= 0x40;
*/ 
}

SIGNAL(SIG_OVERFLOW0)
{
	cli();
	TCNT0 = 0xff - 80; 
	int cnt = 0;
	cnt ++;
	if(45 ==cnt)
	{
		cnt = 0;
		while((ADCSR & (1 << 4)) == 0)
		{
			adcValue = ADCH << 8 | ADCL;			
		}
	}

}

/*
	115,200 baud, 1stop bit, none perity	
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
	for(int i=0 ; pChar+i ; ++i)
	{
		while(!(UCSR0A & 1 << UDRE))
		 	; // UDRE setting
		UDR0 = pChar+i;
	}
}

void uart0_Transmit_Char(const unsigned char pChar)
{
	while(!(UCSR0A & 1 << UDRE)) 
		; // UDRE check
	UDR0 = pChar;
}

unsigned char uart0_Receve_Char(void)
{
	while(!(UCSR0A & 1 << RXC)) // RXC0 check
		;
	return UDR0;
}

SIGNAL(SIG_UART0_RECV)
{
	cli();
	uart0Char = uart0_Receve_Char();
	uart0_Transmit_Char(uart0Char);
	sei();

}
