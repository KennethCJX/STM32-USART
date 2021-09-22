/*
 * Usart_config.h
 *
 *  Created on: Jul 16, 2021
 *      Author: ken chow
 */

#ifndef INC_USART_CONFIG_H_
#define INC_USART_CONFIG_H_

#include <stdint.h>
#include "IO.h"
#include "BaseAddress.h"

/*
//Usart Base Address
#define USART1_BASE_ADDRESS				0x40011000
#define USART2_BASE_ADDRESS				0x40004400
#define USART6_BASE_ADDRESS				0x40011400
*/

//All Usart handler
#define	usart1							((UsartReg*)USART1_BASE_ADDRESS)
#define	usart2							((UsartReg*)USART2_BASE_ADDRESS)
#define	usart6							((UsartReg*)USART6_BASE_ADDRESS)

//Usart Control Register Mask
#define USART_CR1_MASK					0xBFFF
#define USART_CR2_MASK					0x7F7F0000
#define USART_CR3_MASK					0xFFF00000000

typedef struct UsartReg_t UsartReg;
struct UsartReg_t{
	_IO_ uint32_t SR;
	_IO_ uint32_t DR;
	_IO_ uint32_t BRR;
	_IO_ uint32_t CR1;
	_IO_ uint32_t CR2;
	_IO_ uint32_t CR3;
	_IO_ uint32_t GTPR;
};

typedef enum{
	//CR1(bits 0-15)
	USART_SEND_BREAK		= 1 << 0,
	USART_RCV_WAKEUP 		= 1 << 1,
	USART_RX_EN 			= 1 << 2,
	USART_TX_EN 			= 1 << 3,
	USART_IDLE_IE			= 1 << 4,
	USART_RXNE_IE			= 1 << 5,
	USART_TC_IE				= 1 << 6,
	USART_TXE_IE			= 1 << 7,
	USART_PE_IE				= 1 << 8,		//parity error interrupt enable
	USART_ODD_PARITY		= 0x3 << 9,
	USART_EVEN_PARITY		= 0x2 << 9,
	USART_WAKE_ON_IDLE		= 0 << 11,
	USART_WAKE_ON_ADDR		= 0 << 11,
	USART_8_DATA_BIT		= 0 << 12,
	USART_9_DATA_BIT		= 1 << 12,
	USART_EN				= 1 << 13,
	USART_OVER8				= 1 << 15,
	USART_OVER16			= 0 << 15,

	//CR2 (bits 16-31)
	USART_LBDL 				= 1 << (5+16),	//LIN break detection length
	USART_LBD_IE			= 1 << (6+16),	//LIN break detection interrupt enable
	USART_LBCL				= 1 << (8+16),	//last bit clock pulse
	USART_CPHA				= 1 << (9+16),	//clock pulse
	USART_CPOL				= 1 << (10+16),	//clock polarity
	USART_CLK_EN			= 1 << (11+16),	//clock enable
	USART_1_STOPBIT			= 0 << (12+16),
	USART_0_5_STOPBIT		= 1 << (12+16),
	USART_2_STOPBIT			= 2 << (12+16),
	USART_1_5_STOPBIT		= 3 << (12+16),
	USART_LIN_EN			= 1 << (14+16),

	//CR3
	USART_E_IE				= (1LL << (0+32)),
	USART_IRDA_EN			= (1LL << (1+32)),
	USART_IRDA_LP			= (1LL << (2+32)),
	USART_HALF_DUPLEX		= (1LL << (3+32)),
	USART_SCARD_NACK		= (1LL << (4+32)),
	USART_SCARD_EN			= (1LL << (5+32)),
	USART_DMA_RX_EN			= (1LL << (6+32)),
	USART_DMA_TX_EN			= (1LL << (7+32)),
	USART_RTS_EN			= (1LL << (8+32)),
	USART_CTS_EN			= (1LL << (9+32)),
	USART_CTS_IE			= (1LL << (10+32)),
	USART_ONEBIT			= (1LL << (11+32)),	//one bit sampling
	USART_THREEBIT			= (0LL << (11+32)),	//three bit sampling
}UsartConfig;

void usartconfigure(UsartReg *usart, UsartConfig configuration);
void usartSetBaudRate(UsartReg *usart, int baudrate);
void Usart_Tx_character(UsartReg *usart, uint8_t character);
void Usart_Tx_String(UsartReg *usart, char *string);

#endif /* INC_USART_CONFIG_H_ */
