/////////////////////////////////////////
//	smart blinder (mini_project)	  ///
/////////////////////////////////////////
//	PE 5 		-> switch2		      ///
//	PA 0-3 		-> select FND digit	  ///
//	PC 0-7		-> FND DATA	 		  ///
//	PF 0 		-> Cds ( ADC )		  ///
//	PE 0-1		-> UART0			  ///
//  PD 2-3		-> UART1			  ///
//  PB 5		-> OC1A				  ///
/////////////////////////////////////////
//	Interrupt						  ///
//	TIMER 0 . normal         . 1msec  ///
//	TIMER 1 . fast PWM       . 20msec ///
//	ADC 0   . free running	 		  ///
//	EXTI 5  . INT5          		  ///
//	UART0   . 115,200 Baud rate		  ///
/////////////////////////////////////////
//	IOT 7기							  ///
// 	2017-09-01 / 최재민 , 한호성 	  ///
/////////////////////////////////////////

#ifndef _MYLIB_UTIL_H_
#define _MYLIB_UTIL_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "myLib_timer.h"
#include "myLib_7seg.h"
#include "myLib_adc.h"
#include "myLib_Uart.h"
#include "myLib_EXTI.h"

volatile int modeSelect;

void int2str(unsigned char *, int);



#endif
