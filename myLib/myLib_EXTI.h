#ifndef _MYLIB_EXTI_H_
#define _MYLIB_EXTI_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void init_interrupt(void);

SIGNAL(SIG_INTERRUPT4);
SIGNAL(SIG_INTERRUPT5);

#endif
