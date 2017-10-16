#include "myLib_util.h"

int main(void)
{
	init_timer0();
	init_timer1();
	init_7seg();
	init_adc();
	init_uart0();
	init_interrupt();

	unsigned char buffer[20] = "Cds value : ";
	unsigned int adc;

	//modeSelect - 0 : auto, 1 : close, 2 : open
	uart0_Transmit("if you select mode, press : #0 , #1, #2\r\n");

	while(1)
	{
		if(0==modeSelect)
		{
			if(secFlag)
			{
				start_ADC();
				adc = read_ADC();

				int2str(buffer+11,adc);
				uart0_Transmit(buffer);
		
				secFlag=0;
			
	
			if(550 < adc)
			{
				OCR1A  = ICR1*0.05; //0  degree - close
			}
			else
			{
				OCR1A  = ICR1*0.1;  //90 degree - open
			}
			}
		}
		
		else if(1==modeSelect)
		{
			OCR1A  = ICR1*0.05;
		}
		else
		{
			OCR1A  = ICR1*0.1;
		}
		disp_7seg(modeSelect);
		

	}
 return 0;
}
