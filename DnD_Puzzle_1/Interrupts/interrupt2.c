/*
 * interrupt2.c
 *
 *  Created on: Nov 8, 2022
 *      Author: KosmicznyBandyta
 */

#include <avr/interrupt.h>

#include "../Headers/led_display.h"

// lang = 1 - common language (Arabic numerals)
// lang = 2 - elvish language

volatile uint8_t lang = 2;

ISR(INT2_vect) {
	lang <<= lang;
	if (lang >= 4)
		lang = 1;
}
