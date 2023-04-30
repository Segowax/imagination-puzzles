/*
 * rs232.c
 *
 *  Created on: Apr 30, 2023
 *      Author: KosmicznyBandyta
 */

#include <avr/io.h>
#include <avr/pgmspace.h>

#include "rs232.h"

void USART_Init(uint16_t ubrr) {
	UBRRH = (uint8_t) (ubrr >> 8);
	UBRRL = (uint8_t) ubrr;
	UCSRB = (1 << RXEN) | (1 << TXEN);
	UCSRC = (1 << URSEL) | (3 << UCSZ0);
}

void rs232_str(char *str) {
	register char sign;
	while ((sign = *str++))
		USART_Transmit(sign);
}

void rs232_str_P(const char *str) {
	register char sign;
	while ((sign = pgm_read_byte(str++)))
		USART_Transmit(sign);
}

void USART_Transmit(char data) {
	while (!(UCSRA & (1 << UDRE)))
		;
	UDR = data;
}
