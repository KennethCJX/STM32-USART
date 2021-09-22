/*
 * GPIO.h
 *
 *  Created on: Jul 16, 2021
 *      Author: ken chow
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include <stdint.h>
#include "IO.h"

#define PORT_A						0x40020000
#define PORT_B						0x40020400
#define PORT_C						0x40020800
#define PORT_D						0x40020C00
#define PORT_E						0x40021000
#define PORT_H						0x40021C00

//All GPIO handler
#define gpioA						((Gpio *)PORT_A)
#define gpioB						((Gpio *)PORT_B)
#define gpioC						((Gpio *)PORT_C)
#define gpioD						((Gpio *)PORT_D)
#define gpioE						((Gpio *)PORT_E)
#define gpioH						((Gpio *)PORT_H)

//GPIO Mask
#define GPIO_MODE_MASK(pin)			(~(3 << 2 * (pin)))
#define GPIO_DRVR_MASK(pin)			(~(1 << (pin)))
#define GPIO_SPEED_MASK(pin)		(~(3 << 2 * (pin)))
#define GPIO_PULL_MASK(pin)			(~(3 << 2 * (pin)))
#define GPIO_AFR_MASK(pin)			(~(15 << 2 * (pin)))

typedef struct Gpio_t Gpio;
struct Gpio_t{
	_IO_ int32_t MODER;
	_IO_ int32_t OTYPER;
	_IO_ int32_t OSPEEDR;
	_IO_ int32_t PUPDR;
	_IO_ int32_t IDR;
	_IO_ int32_t ODR;
	_IO_ int32_t BSRR;
	_IO_ int32_t LCKR;
	_IO_ int32_t AFR[2];
};

typedef enum {
  // GPIO Mode
  GPIO_INPUT, GPIO_OUTPUT, GPIO_ALT_FUNC, GPIO_ANALOG_IN,
  // GPIO Type
  GPIO_PUSH_PULL  = 0 << 4, GPIO_OPEN_DRAIN = 1 << 4,
  // GPIO Speed
  GPIO_LOW_SPEED  = 0 << 8, GPIO_MEDIUM_SPEED = 1 << 8,
  GPIO_FAST_SPEED = 2 << 8, GPIO_HIGH_SPEED   = 3 << 8,
  // GPIO Pull type
  GPIO_NO_PULL    = 0 << 12, GPIO_PULL_UP = 1 << 12,
  GPIO_PULL_DOWN  = 2 << 12,
  // GPIO Alternate Function
  AF_0  =  0 << 16, AF_1  =  1 << 16, AF_2  =  2 << 16, AF_3  =  3 << 16,
  AF_4  =  4 << 16, AF_5  =  5 << 16, AF_6  =  6 << 16, AF_7  =  7 << 16,
  AF_8  =  8 << 16, AF_9  =  9 << 16, AF_10  =  10 << 16, AF_11  =  11 << 16,
  AF_12  =  12 << 16, AF_13  =  13 << 16, AF_14  =  14 << 16, AF_15  =  15 << 16,
}GpioConfig;

/**
* @desc  Configure GPIO pin of a port to the given mode, output driver,
*        input pull-type, speed, and alternate function.
*
* @param port is the GPIO port of the pin
* @param pin  is the GPIO pin to configure*
* @param cfg  is the mode, output driver, input pull-type, and
*             alternate function number for the pin
*
* @note  The alternate function number is configured only if the mode is
*        GPIO_ALT_FUNC. For all other mode, the alternate function
*        configuration is ignored.
*/

int gpioReadPin(Gpio *gpio, int pin);
void gpioConfigurePin(Gpio *gpio, int pin, GpioConfig cfg);

#endif /* INC_GPIO_H_ */
