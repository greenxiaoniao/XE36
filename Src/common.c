#include "stdint.h"

uint8_t Display_Num_LCD(uint8_t num)
{
		if(num == 1)
			return 0x06;
		else if(num == 2)
			return 0xe3;
		else if(num == 3)
			return 0xa7;
		else if(num == 4)
			return 0x36;
		else if(num == 5)
			return 0xb5;
		else if(num == 6)
			return 0xf5;
		else if(num == 7)
			return 0x07;
		else if(num == 8)
			return 0xf7;
		else if(num == 0)
			return 0xd7;
		else if(num == 9)
			return 0xB7;
	return 0x0;
}
