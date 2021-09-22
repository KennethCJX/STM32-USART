/*
 * NVIC.h
 *
 *  Created on: Sep 3, 2021
 *      Author: ken chow
 */

#ifndef INC_NVIC_H_
#define INC_NVIC_H_

#include <stdint.h>
#include "IO.h"

#define NVIC_BASE_ADDRESS		0xE000E100

#define nvic					((NvicReg *)NVIC_BASE_ADDRESS)

typedef struct NvicReg_t NvicReg;
struct NvicReg_t{
	_IO_ int32_t NVIC_ISER[8];
	_IO_ int32_t Reserved0[24];
	_IO_ int32_t NVIC_ICER[8];
	_IO_ int32_t Reserved1[24];
	_IO_ int32_t NVIC_ISPR[8];
	_IO_ int32_t Reserved2[24];
	_IO_ int32_t NVIC_ICPR[8];
	_IO_ int32_t Reserved3[24];
	_IO_ int32_t NVIC_IABR[8];
	_IO_ int32_t Reserved4[56];
	_IO_ int32_t NVIC_IPR[60];
	_IO_ int32_t Reserved5[644];
	_IO_ int32_t STIR;
};

void nvicEnableIrq(int IrqNum);
void nvicDisableIrq(int IrqNum);
void nvicEnablePendingIrq(int IrqNum);
void nvicDisablePendingIrq(int IrqNum);
#endif /* INC_NVIC_H_ */
