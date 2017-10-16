#ifndef _MYLIB_TIMER_H_
#define _MYLIB_TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//use timer 0 , internal clock, normal mode, overflow interrupt

volatile int secFlag;
static unsigned int msecond;
static unsigned int second;
static unsigned int adc;


void init_timer0(void);
void init_timer1(void);
unsigned int get_msec(void);
void clear_msec(void);

SIGNAL(SIG_OVERFLOW0);

#endif
