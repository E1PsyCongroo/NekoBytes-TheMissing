#include "8052.h"
#include "stdint.h"

void delay_ms(uint16_t time);

#define LED P2_0 
uint16_t i;

void main()
{
    LED = 0;
    while (1)
    {
        delay_ms(200);
        LED = !LED;
        delay_ms(200);
        LED = !LED;
        delay_ms(1000);
        LED = !LED;
    }
}
void delay_ms(uint16_t time)		//@11.0592MHz
{
    uint16_t t=0;
    for(t=0;t<time;t++)
    {
        unsigned char i, j;
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
    }
}
