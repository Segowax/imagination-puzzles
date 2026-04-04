/*
 * rs232.c
 *
 *  Created on: 4 kwi 2026
 *      Author: kosmi
 */

#include <avr/io.h>
#include "rs232.h"

void USART_Init(uint16_t ubrr) {
	UBRRH = (uint8_t) (ubrr >> 8);
	UBRRL = (uint8_t) ubrr;

	UCSRB = (1 << RXEN);
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
}

uint8_t USART_Receive() {
	while (!(UCSRA & (1 << RXC)))
		;

	return UDR;
}
