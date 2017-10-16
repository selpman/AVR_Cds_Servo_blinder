#ifndef _MYLIB_7SEG_H_
#define _MYLIB_7SEG_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SEG_DATA 	PORTC
#define SEG_SELECT 	PORTA

void init_7seg(void);
void disp_7seg(unsigned int);

#endif
