#include "GPIO.h"

void main()
{
    Clock_init();
    GPIO_init();
    while (1)
    {
        GPIOC->ODR ^= (1 << 13);
        myDelay(500);
    }
}