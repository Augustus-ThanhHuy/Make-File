#include "GPIO.h"

void myDelay(uint32_t time)
{
    uint32_t i;
    while (time--)
    {
        for (i = 0; i < 1000; i++)
            ;
    }
}
void Clock_init(void)
{
    RCC->CR |= (1 << 0); // Bật HSI

    RCC->APB2ENR |= (1 << 4); // Cấp xung cho PORT C
}

void GPIO_init(void)
{
    GPIOC->CRH &= ~(0xF << 20);
    GPIOC->CRH |= (0x02 << 20);
}