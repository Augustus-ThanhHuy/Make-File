/*
 * Author: Thanh Huy
 * Created on: 2025-01-07
 */
#ifndef GPIO_H
#define GPIO_H

#define uint32_t unsigned int
#define uint8_t unsigned char
/*Peripheral memory map*/
#define PERIPH_Base 0x40000000U
#define APB1_Base PERIPH_Base
#define APB2_Base 0x40010000U
#define AHB_Base (APB2_Base + 0x8000U)

#define GPIOA_Base (APB2_Base + 0x0800U)
#define GPIOB_Base (APB2_Base + 0x0C00U)
#define GPIOC_Base (APB2_Base + 0x1000U)

#define RCC_Base (AHB_Base + 0x9000U)
#define EXTI_Base (APB2_Base + 0x0400U)
#define AFIO_Base (APB2_Base + 0x0000U)

#define TIM1_Base (APB1_Base)
#define TIM2_Base (APB1_Base + 0x0200U)
/*GPIO config*/
typedef struct
{
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_RegDef_t;

#define GPIOA ((GPIO_RegDef_t *)GPIOA_Base)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_Base)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_Base)

/* GPIO Modes */
#define GPIO_MODE_INPUT 0x00
#define GPIO_MODE_OUTPUT_PP 0x01
#define GPIO_MODE_OUTPUT_OD 0x02
#define GPIO_MODE_AF_PP 0x03
#define GPIO_MODE_AF_OD 0x04
#define GPIO_MODE_ANALOG 0x05
#define GPIO_MODE_INPUT_PU_PD 0x06

/* GPIO Speed */
#define GPIO_SPEED_10MHZ 0x01
#define GPIO_SPEED_2MHZ 0x02
#define GPIO_SPEED_50MHZ 0x03

/*RCC config*/
typedef struct
{
    volatile uint32_t CR;       /*Clock control register*/
    volatile uint32_t CFGR;     /*Clock config register*/
    volatile uint32_t CIR;      /*Clock Interrupt register*/
    volatile uint32_t APB2RSTR; /*APB2 peripheral reset register*/
    volatile uint32_t APB1RSTR; /*APB1 peripheral reset register*/
    volatile uint32_t AHBENR;   /*peripheral clock enable register*/
    volatile uint32_t APB2ENR;  /*APB2 peripheral clock enable register*/
    volatile uint32_t APB1ENR;  /*APB1 peripheral clock enable register*/
    volatile uint32_t BDCR;     /*Backup domain control register*/
    volatile uint32_t CSR;      /*Control/status register*/

} RCC_RegDef_t;

#define RCC ((RCC_RegDef_t *)RCC_Base)
/* EXTI Register config */
typedef struct
{
    volatile uint32_t IMR;   /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
    volatile uint32_t EMR;   /*!< EXTI Event mask register,                Address offset: 0x04 */
    volatile uint32_t RTSR;  /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
    volatile uint32_t FTSR;  /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
    volatile uint32_t SWIER; /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
    volatile uint32_t PR;    /*!< EXTI Pending register,                   Address offset: 0x14 */
} EXTI_TypeDef;

#define EXTI ((EXTI_TypeDef *)EXTI_BASE)

/* AFIO Register config */
typedef struct
{
    volatile uint32_t EVCR;      /*!< AFIO Event control register,                      Address offset: 0x00 */
    volatile uint32_t MAPR;      /*!< AFIO Remap and debug I/O configuration register,  Address offset: 0x04 */
    volatile uint32_t EXTICR[4]; /*!< AFIO External interrupt configuration registers, Address offset: 0x08-0x14 */
    uint32_t RESERVED;           /*!< Reserved,                                         Address offset: 0x18 */
    volatile uint32_t MAPR2;     /*!< AFIO Remap and debug I/O configuration register 2, Address offset: 0x1C */
} AFIO_TypeDef;

#define AFIO ((AFIO_TypeDef *)AFIO_BASE)
// void myDelay();
// void Clock_init();
// void GPIO_init();

typedef struct{

} TIM_TypeDef;
#define TIME2 ((TIM_TypeDef *)TIM2_Base)
#endif /* GPIO_H */