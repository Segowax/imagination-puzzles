/*
 * main.c
 *
 *  Created on: Apr 30, 2023
 *      Author: KosmicznyBandyta
 */

#include <avr/io.h>
#include <util/delay.h>

#include "Configurations/rs232.h"

int main() {
	DDRB |= (1 << PB0);

	USART_Init(__UBRR);
	while (1) {
		if (USART_Receive()) {
			PORTB ^= (1 << PB0);
		}
	}
}
