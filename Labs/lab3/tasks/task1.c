#include "8052.h"

#define LED P2_0

unsigned char cnt = 0;

void main()
{
	LED = 0;
	while(1)
	{
		unsigned char i = 0;
		LED=!LED;
		for(i = 0;i<cnt;i++);
		cnt++;
		LED=!LED;
		i = 0;
		for(i = 0;i<255-cnt;i++);
	}
}