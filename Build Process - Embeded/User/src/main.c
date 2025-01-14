#include "GPIO.h"

void main()
{
    //HSI
    RCC->CR |= (1<<0);

    //Port B
    RCC->APB2ENR |= (1<<3);
    //Port C
    RCC->APB2ENR |= (1<<4);
    //PC13
    GPIOC->CRH &= ~(0xF << 20);
    GPIOC->CRH |= (0x02 << 20);
    //PB1
    GPIOB->CRL &= ~(0xF << 4);
    GPIOB->CRL |= (0x02 << 4);
    //PB2
    GPIOB->CRL &= ~(0xF << 8);
    GPIOB->CRL |= (0x02 << 8);

    while (1)
    {
        GPIOB->ODR ^= (1 << 1);
        myDelay(1000);
        // GPIOB->ODR ^= (1 << 2);
        // myDelay(200);
        GPIOC->ODR ^= (1 << 13);
        myDelay(1000);
    }
}