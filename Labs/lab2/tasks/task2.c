#include "8052.h"
#include "stdint.h"

void delay_ms(uint16_t time);

#define LED P2_0 
uint16_t i;

void main()
{
    while (1)
    {
        for(i=500;i<65535;i--)
        {
            LED = 0;
            delay_ms(1);
            LED = 1;
            delay_ms(5);
        }
        for(i=1000;i<65535;i--)
        {
            LED = 1;
            delay_ms(1);
            LED = 0;
            delay_ms(5);
        }
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
