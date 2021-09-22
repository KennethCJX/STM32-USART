/*
 * Adc.c
 *
 *  Created on: Aug 31, 2021
 *      Author: ken chow
 */


#include "Adc.h"

void Adc_setSampleTime(ADCReg *adc1, int channel, ADC_Sampling_Config cfg){
	if(channel < 10){
		if(cfg == SAMPLE_3_CYCLE)
			adc1->SMPR2 = 0x0;
		else if(cfg == SAMPLE_15_CYCLE)
			adc1->SMPR2 = 0x1;
		else if(cfg == SAMPLE_28_CYCLE)
			adc1->SMPR2 = 0x2;
		else if(cfg == SAMPLE_56_CYCLE)
			adc1->SMPR2 = 0x3;
		else if(cfg == SAMPLE_84_CYCLE)
			adc1->SMPR2 = 0x4;
		else if(cfg == SAMPLE_112_CYCLE)
			adc1->SMPR2 = 0x5;
		else if(cfg == SAMPLE_144_CYCLE)
			adc1->SMPR2 = 0x6;
		else
			adc1->SMPR2 = 0x7;
	}
	else{
		if(cfg == SAMPLE_3_CYCLE)
			adc1->SMPR1 = 0x0;
		else if(cfg == SAMPLE_15_CYCLE)
			adc1->SMPR1 = 0x1;
		else if(cfg == SAMPLE_28_CYCLE)
			adc1->SMPR1 = 0x2;
		else if(cfg == SAMPLE_56_CYCLE)
			adc1->SMPR1 = 0x3;
		else if(cfg == SAMPLE_84_CYCLE)
			adc1->SMPR1 = 0x4;
		else if(cfg == SAMPLE_112_CYCLE)
			adc1->SMPR1 = 0x5;
		else if(cfg == SAMPLE_144_CYCLE)
			adc1->SMPR1 = 0x6;
		else
			adc1->SMPR1 = 0x7;
	}
}

void Adc_setRegularChannel(ADCReg *adc1, ADC_Config_Regular_Ch configuration){
	adc1->CR2 &= ~(ADC1_CR2_MASK << 24);
	adc1->CR2 |= configuration;
}

void Adc_CCR_config(ADC_CCR configuration){
	ADC_COM->CCR &= cfg;
	ADC_COM->CCR |= cfg;
}

void Adc_setChannelSequence(ADCReg *adc1){
	adc1->SQR1 = 0x0;
	adc1->SQR3 = 0x1;
}

void Adc_Configuration(ADCReg *adc1, ADC_Config configuration){
	adc1->CR1 &= ~(configuration & ADC1_CR1_MASK);
	adc1->CR1 |= (configuration & ADC1_CR1_MASK);
	adc1->CR2 &= ~(configuration >> 16);
	adc1->CR2 |= (configuration >> 16);
}
