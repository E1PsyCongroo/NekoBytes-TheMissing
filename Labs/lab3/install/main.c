#include <8052.h>

void delay100ms()        //@11.0592MHz
{
    unsigned char i, j;

    i = 180;
    j = 73;
    do
    {
        while (--j);
    } while (--i);
}

void main()
{
    while(1)
    {
        P2_0 = !P2_0;
        delay100ms();
    }
}
