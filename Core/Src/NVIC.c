/*
 * NVIC.c
 *
 *  Created on: Sep 3, 2021
 *      Author: ken chow
 */


#include "NVIC.h"

void nvicEnableIrq(int IrqNum){
	int n, bitPos;

	n= IrqNum/32;
	bitPos = IrqNum%32;

	nvic->NVIC_ISER[n] = 1 << bitPos;
}

void nvicDisableIrq(int IrqNum){
	int n, bitPos;

	n= IrqNum/32;
	bitPos = IrqNum%32;

	nvic->NVIC_ICER[n] = 1 << bitPos;
}

void nvicEnablePendingIrq(int IrqNum){
	int n, bitPos;

	n= IrqNum/32;
	bitPos = IrqNum%32;

	nvic->NVIC_ISPR[n] = 1 << bitPos;
}

void nvicDisablePendingIrq(int IrqNum){
	int n, bitPos;

	n= IrqNum/32;
	bitPos = IrqNum%32;

	nvic->NVIC_ICPR[n] = 1 << bitPos;
}
