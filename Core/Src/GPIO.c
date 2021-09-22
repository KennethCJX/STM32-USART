/*
 * GPIO.c
 *
 *  Created on: Jul 16, 2021
 *      Author: ken chow
 */

#include "GPIO.h"

void gpioWritePin(Gpio *gpio, int pin, int state){
	if(state)
		gpio->BSRR = 1 << pin;
	else
		gpio->BSRR = 1 << (16 + pin);
}

int gpioReadPin(Gpio *gpio, int pin){
	return (gpio->IDR >> pin) & 1;
}

void gpioConfigurePin(Gpio *gpio, int pin, GpioConfig cfg)
{
	//configure GPIO mode
	gpio->MODER &= GPIO_MODE_MASK(pin);
	gpio->MODER |= (cfg & 0xF) << (2 * pin);


	//configure GPIO output driver type
	gpio->OTYPER &= GPIO_DRVR_MASK(pin);
	gpio->OTYPER |= ((cfg & 0xF0) >> 4) << pin;

	//Configure GPIO speed
	gpio->OSPEEDR &= GPIO_SPEED_MASK(pin);
	gpio->OSPEEDR |= ((cfg & 0xF00) >> 8) << (2 * pin);

	//Configure GPIO pull type
	gpio->PUPDR &= GPIO_PULL_MASK(pin);
	gpio->PUPDR |= ((cfg & 0xF000) >> 12) << (2 * pin);

	//Configure GPIO Alternate Function
	//if ALT functon is selected, then store into upper and lower AFR
	if((gpio->MODER & (0x3 << (2 * pin))) >> (2 * pin) == GPIO_ALT_FUNC)
		if(pin <= 0x07){
			gpio->AFR[0] &= GPIO_AFR_MASK(pin);
			gpio->AFR[0] |= ((cfg & 0xF0000) >> 16) << (4 * pin);
		}
		else{
			gpio->AFR[1] &= GPIO_AFR_MASK(pin);
			gpio->AFR[1] |= ((cfg & 0xF0000) >> 16) << (4 * (pin - 8));
		}
}
