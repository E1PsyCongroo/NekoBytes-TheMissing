/*************************************
 * 
 *        89c52 sdcc blink demo
 * 
 * CPU: 89C52
 * FREQ: 12MHz
 * PIN: P20
 * 
 * ***********************************
*/

#include <reg52.h>
#include <stdio.h>

void delay_100ms(); //@12MHz

void main()
{
    while (1)
    {
        P20 = !P20;
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

