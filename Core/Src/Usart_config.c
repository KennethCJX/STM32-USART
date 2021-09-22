/*
 * Usart_config.c
 *
 *  Created on: Jul 16, 2021
 *      Author: ken chow
 */

#include <math.h>
#include "Usart_config.h"

void usartconfigure(UsartReg *usart, UsartConfig configuration){
	usart->CR1 = (configuration & USART_CR1_MASK);
	usart->CR2 = (configuration & USART_CR2_MASK) >> 16;
	usart->CR3 = (configuration & USART_CR3_MASK) >> 32;
}

uint32_t getUsartFreq(UsartReg *usart){
	if(usart == usart2)
	{
		return HAL_RCC_GetPCLK1Freq();
	}
	else
	{
		return HAL_RCC_GetPCLK2Freq();
	}
}

void usartSetBaudRate(UsartReg *usart, int baudrate){
	double fractional, decimal;
	uint32_t apbfreq = getUsartFreq(usart);
	int over8 = (usart->CR1 & 0x8000) >> 15;
	float usart_div = (double)apbfreq/(8*(2-over8)*baudrate);//Over8=0 is fractional*16, oversampling by 16 ;Over8=1 is fractional*8, oversampling by 8
	fractional = modf(usart_div, &decimal);
	usart->BRR = ((int)(decimal) << 4 | (int)(fractional*8*(2-over8)));
}

void Usart_Tx_character(UsartReg *usart, uint8_t character){
	while (!(usart-> SR & 0x80));
		usart-> DR =  character;
	while (!(usart-> SR & 0x40));
}

void Usart_Tx_String(UsartReg *usart, char *string){
	while (*string)
		Usart_Tx_character(usart, (*string++));
}

