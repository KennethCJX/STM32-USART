/*
 * Adc.h
 *
 *  Created on: Aug 31, 2021
 *      Author: ken chow
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include <stdint.h>
#include "IO.h"

//ADC Base Address
#define ADC1_BASE_ADDRESS		0x40012000

//All ADC handler
#define ADC1					((ADCReg*)ADC1_BASE_ADDRESS)

//ADC Mask
#define ADC1_CR1_MASK			0xFFFFFFFF
#define ADC1_CR2_MASK			0x7F

typedef struct ADCReg_t ADCReg;
struct ADCReg_t{
	_IO_ int32_t SR;
	_IO_ int32_t CR1;
	_IO_ int32_t CR2;
	_IO_ int32_t SMPR1;
	_IO_ int32_t SMPR2;
	_IO_ int32_t JOFR1;
	_IO_ int32_t JOFR2;
	_IO_ int32_t HTR;
	_IO_ int32_t LTR;
	_IO_ int32_t SQR1;
	_IO_ int32_t SQR2;
	_IO_ int32_t SQR3;
	_IO_ int32_t JSQR;
	_IO_ int32_t JDR1;
	_IO_ int32_t JDR2;
	_IO_ int32_t JDR3;
	_IO_ int32_t JDR4;
	_IO_ int32_t DR;
	_IO_ int32_t CCR;
};


typedef enum{
	//CR1
	ADC_ANALOG_IN_CH0 = 0 << 0, ADC_ANALOG_IN_CH1 = 1 << 0, ADC_ANALOG_IN_CH2 = 2 << 0, ADC_ANALOG_IN_CH3 = 3 << 0,
	ADC_ANALOG_IN_CH4 = 4 << 0, ADC_ANALOG_IN_CH5 = 5 << 0, ADC_ANALOG_IN_CH6 = 6 << 0, ADC_ANALOG_IN_CH7 = 7 << 0,
	ADC_ANALOG_IN_CH8 = 8 << 0, ADC_ANALOG_IN_CH9 = 9 << 0, ADC_ANALOG_IN_CH10 = 10 << 0, ADC_ANALOG_IN_CH11 = 11 << 0,
	ADC_ANALOG_IN_CH12 = 12 << 0, ADC_ANALOG_IN_CH13 = 13 << 0, ADC_ANALOG_IN_CH14 = 14 << 0, ADC_ANALOG_IN_CH15 = 15 << 0,
	ADC_ANALOG_IN_CH16 = 16 << 0,
	EOC_INTERRUPT_DISABLE = 0 << 5, EOC_INTERRUPT_EN = 1 << 5,
	AWD_INTERRUPT_DISABLE = 0 << 6, AWD_INTERRUPT_EN = 1 << 6,
	JEOC_INTERRUPT_DISABLE = 0 << 7, JEOC_INTERRUPT_EN = 1 << 7,
	SCAN_MODE_DISABLE = 0 << 8, SCAN_MODE_EN = 1 << 8,
	AWD_EN_ON_ALL_CH = 0 << 9, AWD_EN_ON_SINGLE_CH = 1 << 9,
	JAUTO_DISABLE = 0 << 10, JAUTO_EN = 1 << 10,
	DISC_MODE_DISABLE = 0 << 11, DISC_MODE_EN = 1 << 11,
	JDISC_MODE_DISABLE = 0 << 12, JDISC_MODE_EN = 1 << 12,
	DISC_NUM_1CH = 0 << 13, DISC_NUM_2CH = 1 << 13, DISC_NUM_3CH = 2 << 13, DISC_NUM_4CH = 3 << 13, DISC_NUM_5CH = 4 << 13,
	DISC_NUM_6CH = 5 << 13, DISC_NUM_7CH = 6 << 13, DISC_NUM_8CH = 7 << 13,
	JAWD_INJECTED_CH_DISABLE = 0 << 22, JAWD_INJECTED_CH_EN = 1 << 22,
	AWD_REGULAR_CH_DISABLE = 0 << 23, AWD_REGULAR_CH_EN = 1 << 23,
	RESOLUTION_12BIT = 0 << 24, RESOLUTION_10BIT = 1 << 24, RESOLUTION_8BIT = 2 << 24, RESOLUTION_6BIT = 0 << 24,
	OVERRUN_INTERRUPT_DISABLE = 0 << 26, OVERRUN_INTERRUPT_EN = 1 << 26,

	//CR2
	ADC_OFF = 0 << (0 + 16), ADC_ON = 1 << (0 + 16),
	CONT_SINGLE_CONV = 0 << (1 + 16), CONT_CONTINUOUS_CONV = 1 << (1 + 16),
	DMA_DISABLE = 0 << (8 + 16), DMA_EN = 1 << (8 + 16),
	DDS_DISABLE = 0 << (9 + 16), DDS_EN = 1 << (9 + 16),
	EOCS_CLEAR = 0 << (10 + 16), EOCS_SET = 1 << (10 + 16),
	RIGHT_ALIGN = 0 << (11 + 16), LEFT_ALIGN = 1 << (11 + 16),
}ADC_Config;

typedef enum{
	TIMER4_CC4_EVENT_REG = 9 << 24 ,TRIG_DET_RISING_REG = 1 << 28, START_CONV_REG_CH_SET = 1<< 30,
}ADC_Config_Regular_Ch;

typedef enum {
	SAMPLE_3_CYCLE = 0 << 0, SAMPLE_15_CYCLE = 1 << 0, SAMPLE_28_CYCLE = 2 << 0, SAMPLE_56_CYCLE = 3 << 0,
	SAMPLE_84_CYCLE = 4 << 0, SAMPLE_112_CYCLE = 5 << 0, SAMPLE_144_CYCLE = 6 << 0, SAMPLE_480_CYCLE = 7 << 0,
}ADC_Sampling_Config;

typedef enum{
	ADC_PSC_DIV_2 = 0 << 16, ADC_PSC_DIV_4 = 1 << 16, ADC_PSC_DIV_5 = 2 << 16, ADC_PSC_DIV_8 = 4 << 16,
	ADC_VBAT_DISABLE = 0 << 22, ADC_VBAT_EN = 1 << 22,
}ADC_CCR;

typedef enum{
	ADC_NO_WATCHDOG_OCCURED = 0 << 0, ADC_WATCHDOG_OCCURED = 1 << 0,
	ADC_END_OF_CONVERSION_NOT_COMPLETE = 0 << 1, ADC_END_OF_CONVERSION_COMPLETE = 1 << 1,
	ADC_INJECTED_EOC_NOT_COMPLETE = 0 << 2, ADC_INJECTED_EOC_COMPLETE = 1 << 2,
	ADC_NO_INJECTED_CONVERSION_STARTED = 0 << 3, ADC_INJECTED_CONVERSION_STARTED = 1 << 3,
	ADC_NO_REGULAR_CONVERSION_STARTED = 0 << 4, ADC_REGULAR_CONVERSION_STARTED = 1 << 4,
	ADC_NO_OVERRUN_OCCURRED = 0 << 5, ADC_OVERRUN_OCCURRED = 0 << 5,
}ADC_Status_Flag;

void Adc_setSampleTime(ADCReg *adc1, int channel, ADC_Sampling_Config cfg);
void Adc_setRegularChannel(ADCReg *adc1, ADC_Config_Regular_Ch configuration);
void Adc_CCR_config(ADC_CCR configuration);
void Adc_setChannelSequence(ADCReg *adc1, int channel, int sequence_len);
void Adc_Configuration(ADCReg *adc1, ADC_Config configuration);

#endif /* INC_ADC_H_ */
