#include "myLib_adc.h"

volatile static unsigned int adcValue;

void init_adc(void)
{
	//external 3.3v, ADC0 chennel.
	//ADMUX |= 0 << REFS1 | 0 << REFS0;
	//free runing, prescaler, enable
	ADCSRA |= 1 << ADIE | 1 << ADPS1 | 1 << ADPS0 | 1 << ADEN | 1 << ADSC;
	ADC = 0;
	sei();
}

void start_ADC(void)
{
	ADCSRA |= 1 << ADSC;
}

SIGNAL(SIG_ADC)
{
	cli();
	adcValue = ADC;
	sei();
}

unsigned int read_ADC(void)
{
	return adcValue;
}
