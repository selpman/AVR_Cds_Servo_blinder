#include "myLib_7seg.h"

void init_7seg(void)
{
	DDRC=0xFF;
	DDRA|=0xF;
}

void disp_7seg(const unsigned int num)
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
