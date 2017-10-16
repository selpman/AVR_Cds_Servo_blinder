#include "myLib_timer.h"

//get msecond.r

void init_timer0(void)
{
	//timer counter control register
	TCCR0 |= 1 << CS02 | 1 << CS01 | 1 << CS00;
	//timer counter register
	//14.7456MHz / prescaler(1024) = 14400Hz -> 14Hz(clock) / 1msec
	TCNT0 |= 0xFF - 14;
	//Timer mask register
	TIMSK |= 1 << TOIE0;
	//timer flag register 
	TIFR  |= 1 << TOV0;
	sei();
}


void init_timer1(void)
{
	DDRB |= 1 << PB5;
    PORTB |= 1 << PB5;
 	TCCR1A = (1<<COM1A1)|(0<<COM1A0)| (0<<COM1B0)| (0<<COM1B0) | (0<<COM1C1) | (0<<COM1C0) | (1<<WGM11) | (0<<WGM10);  
    TCCR1B = (0<<ICNC1) |(0<<ICES1) | (1<<WGM13) | (1<<WGM12 ) | (1<<CS12  ) | (0<<CS11 )  | (1<<CS10 );  
	ICR1 = 288;
	TCNT1  = 0x0000;
}


SIGNAL(SIG_OVERFLOW0)
{
	cli();
	++msecond;

	if(1000 == msecond)
	{
		secFlag=1;
		msecond=0;
	}

	TCNT0 |= 0xFF - 14;

	sei();
}

unsigned int get_msec(void)
{
	return msecond;
}

void clear_msec(void)
{
	msecond = 0;
}
