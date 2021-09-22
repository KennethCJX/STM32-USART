/*
 * Rcc.h
 *
 *  Created on: Jul 6, 2021
 *      Author: ken chow
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include<stdint.h>
#include "IO.h"

#define RCC_BASE_ADDRESS		0x40023800
#define rcc						((RccReg *)RCC_BASE_ADDRESS)

#define ahb1ResetReg			(&rcc->AHB1RSTR)
#define ahb2ResetReg			(&rcc->AHB2RSTR)
#define apb1ResetReg			(&rcc->APB1RSTR)
#define apb2ResetReg			(&rcc->APB2RSTR)

//Addr enable clock register
#define ahb1_EnClkReg			(&rcc->AHB1ENR)
#define ahb2_EnClkReg			(&rcc->AHB2ENR)
#define apb1_EnClkReg			(&rcc->APB1ENR)
#define apb2_EnClkReg			(&rcc->APB2ENR)

typedef struct RccReg_t RccReg;
struct RccReg_t{
	_IO_ int32_t CR;
	_IO_ int32_t PLLCFGR;
	_IO_ int32_t CFGR;
	_IO_ int32_t CIR;
	_IO_ int32_t AHB1RSTR;
	_IO_ int32_t AHB2RSTR;
	_IO_ int32_t Reserved0[2];
	_IO_ int32_t APB1RSTR;
	_IO_ int32_t APB2RSTR;
	_IO_ int32_t Reserved1[2];
	_IO_ int32_t AHB1ENR;
	_IO_ int32_t AHB2ENR;
	_IO_ int32_t Reserved2[2];
	_IO_ int32_t APB1ENR;
	_IO_ int32_t APB2ENR;
	_IO_ int32_t Reserved3[2];
	_IO_ int32_t AHB1LPENR;
	_IO_ int32_t AHB2LPENR;
	_IO_ int32_t Reserved4[2];
	_IO_ int32_t APB1LPENR;
	_IO_ int32_t APB2LPENR;
	_IO_ int32_t Reserved5[2];
	_IO_ int32_t BDCR;
	_IO_ int32_t CSR;
	_IO_ int32_t Reserved6[2];
	_IO_ int32_t SSCGR;
	_IO_ int32_t PLLI2SCFGR;
	_IO_ int32_t Reserved7[1];
	_IO_ int32_t DCKCFGR;
};

typedef enum{
Rcc_GPIOA,
Rcc_GPIOB,
Rcc_GPIOC,
Rcc_GPIOD,
Rcc_GPIOE,
Rcc_GPIOH = 7,
}RccGpio;

typedef enum{
Rcc_USART1 = 4,
Rcc_USART2 = 17,
Rcc_USART6 = 5,
}RccUsart;

typedef enum{
Rcc_I2C_1 = 21,
Rcc_I2C_2 = 22,
Rcc_I2C_3 = 23,
}RccI2C;

typedef enum{
RCC_TIM1 = 0,
RCC_TIM2 = 0,
RCC_TIM3 = 1,
RCC_TIM4 = 2,
RCC_TIM5 = 3,
RCC_TIM9 = 16,
RCC_TIM10 = 17,
RCC_TIM11 = 18,
}RccTimer;

typedef enum{
RCC_ADC1 = 8
}RccADC;

void rccResetUnresetDevice(_IO_ uint32_t *io, int bitnum);
void rccEnableClock(_IO_ uint32_t *io, int bitnum);
void rccUnresetAndEnableGpio(RccGpio rccGpio);
void rccUnresetAndEnableTimer(RccTimer rccTimer);
void rccUnresetAndEnableADC(RccADC rccAdc);
#endif /* INC_RCC_H_ */
