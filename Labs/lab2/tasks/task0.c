#include "8052.h"

//  发光二极管正极接在Vcc(5V),负极接在P2_0引脚上
//  P2_0 = 1代表P2_0引脚输出5V电压,0代表接地

void delay_100ms();

void main() //  @11.0592MHZ
{
    while(1)
    {
        P2_0 = 1;
        delay_100ms();
        delay_100ms();
        delay_100ms();
        delay_100ms();
        delay_100ms();
        P2_0 = 0;
        delay_100ms();
    }
}

void delay_100ms()
{
    unsigned char i, j;

    i = 195;
    j = 138;

    do
    {
        while (--j)
            ;
    } while (--i);
}