#ifndef _MYLIB_ADC_H_
#define _MYLIB_ADC_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned int read_ADC(void);

void init_adc(void);
void start_ADC(void);

SIGNAL(SIG_ADC);


#endif
