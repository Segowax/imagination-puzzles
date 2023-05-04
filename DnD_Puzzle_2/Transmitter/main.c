/*
 * main.c
 *
 *  Created on: Apr 30, 2023
 *      Author: KosmicznyBandyta
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "Configurations/rs232.h"
#include "Headers/sentences.h"

int main() {
	USART_Init(__UBRR);
	int counter = 0;
	int table_length = 6;

	while (1) {
		if (table_length) {
			for (int i = 0; i < table_length; i++) {
				rs232_str_P(sentences[i]);
				_delay_ms(1000);
			}
			counter++;
			if (counter == 100) {
				if (table_length != 1)
					table_length--;
				counter = 0;
			}
		}
	}
}
