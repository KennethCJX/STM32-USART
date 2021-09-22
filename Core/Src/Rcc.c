/*
 * Rcc.c
 *
 *  Created on: Jul 13, 2021
 *      Author: ken chow
 */

#include "Rcc.h"

void rccResetUnresetDevice(_IO_ uint32_t *io, int bitnum){
	*io &= ~(1 << bitnum);
	*io |= 1 << bitnum;				//Reset
	*io &= ~(1 << bitnum);			//Unreset
}

void rccEnableClock(_IO_ uint32_t *io, int bitnum){
	*io &= ~(1 << bitnum);			//Clear
	*io |= 1 << bitnum;				//Enable

}

void rccResetAndUnresetGpio(RccGpio rccGpio){
	rccResetUnresetDevice(ahb1ResetReg, rccGpio);	//Reset and Unreset
	rccEnableClock(ahb1_EnClkReg, rccGpio);			//Enable Clock
}


void rccResetAndUnresetUsart(RccUsart rccUsart){
	if(rccUsart == Rcc_USART2){
		rccResetUnresetDevice(apb1ResetReg, rccUsart);	//Reset and Unreset
		rccEnableClock(apb1_EnClkReg, rccUsart);		//Enable Clock
	}
	else
	{
		rccResetUnresetDevice(apb2ResetReg, rccUsart);	//Reset and Unreset
		rccEnableClock(apb2_EnClkReg, rccUsart);		//Enable Clock
	}
}

void rccUnresetAndEnableTimer(RccTimer rccTimer){
	if(rccTimer == 0)
		rccResetUnresetDevice(apb2ResetReg, rccTimer);
	else
		rccResetUnresetDevice(apb1ResetReg, rccTimer);		//Reset and Unreset
		rccEnableClock(apb1_EnClkReg, rccTimer);			//Enable Clock
}

void rccUnresetAndEnableADC(RccADC rccAdc){
	rccResetUnresetDevice(apb2ResetReg, rccAdc);
	rccEnableClock(apb2_EnClkReg, rccAdc);
}
