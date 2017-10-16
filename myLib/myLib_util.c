#include "myLib_util.h"

void int2str(unsigned char *str, int num)
{
	*str++ = num/1000 + '0';
	*str++ = num/100%10 + '0';
	*str++ = num/10%10 + '0';
	*str++ = num%10 + '0';
	*str++ = '\n';
	*str++ = '\r';
	*str   = '\0';
}
