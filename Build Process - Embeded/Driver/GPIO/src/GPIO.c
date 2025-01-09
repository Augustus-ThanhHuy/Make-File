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

    RCC->APB2ENR |= (1 << 3); // Cấp xung cho PORT C
}

void GPIO_init(void){
    GPIOB->CRL |= (0x02 << 4);
}

// void GPIO_init(void)
// {
//     GPIOC->CRH &= ~(0xF << 20);
//     GPIOC->CRH |= (0x02 << 20);
// }

// void Clock_init(void){
//     RCC->CR |= (1<<0);
// }

// void Clock_enable_port(GPIO_RegDef_t *GPIOx)
// {
//     if(GPIOx == GPIOA){
//         RCC->APB2ENR |= (1<<2);
//     } else if (GPIOx == GPIOB)
//     {
//         RCC->APB2ENR |= (1<<3);
//     } else if (GPIOx == GPIOC)
//     {
//         RCC->APB2ENR |= (1<<4);
//     }
// }

// void GPIO_Init(GPIO_RegDef_t *GPIOx, uint8_t pin, uint8_t mode, uint8_t speed){
//     Clock_enable_port(GPIOx);
//     if(pin < 8){
//         GPIOx->CRL &= ~(0xF << pin*4);
//         GPIOx->CRL |= ((speed << 2) | mode) << (pin * 4); // Set configuration
//     } else {
//         pin-=8;
//         GPIOx->CRH &= ~(0xF << pin*4);
//         GPIOx->CRH |= ((speed << 2) | mode) << (pin * 4); // Set configuration
//     }
// }