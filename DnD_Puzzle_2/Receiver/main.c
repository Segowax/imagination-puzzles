/*
 * main.c
 *
 *  Created on: Apr 30, 2023
 *      Author: KosmicznyBandyta
 */

#include <avr/io.h>
#include <util/delay.h>

#define UART_BAUD 9600
#define __UBRR ((F_CPU+UART_BAUD*8UL) / (16UL*UART_BAUD)-1)

void USART_Init(uint16_t baud);
uint8_t USART_Receive();

int main() {
	DDRB |= (1 << PB0);
	USART_Init(__UBRR);
	while (1) {
		if (USART_Receive()) {
			PORTB ^= (1 << PB0);
		}
	}
}

void USART_Init(uint16_t ubrr) {
	UBRRH = (uint8_t) (ubrr >> 8);
	UBRRL = (uint8_t) ubrr;
	UCSRB = (1 << RXEN) | (1 << TXEN);
	UCSRC = (1 << URSEL) | (3 << UCSZ0);
}

uint8_t USART_Receive() {
	while (!(UCSRA & (1 << RXC)))
		;

	return UDR;
}
