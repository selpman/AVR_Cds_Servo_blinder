#include "myLib_EXTI.h"
#include "myLib_util.h"

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
//do it
}

SIGNAL(SIG_INTERRUPT5)
{
	cli();

	if(modeSelect==0)
		modeSelect++;
	else if(modeSelect==1)
		modeSelect++;
	else
		modeSelect=0;	

	sei();
}

