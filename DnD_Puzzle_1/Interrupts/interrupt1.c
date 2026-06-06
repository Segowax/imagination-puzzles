/*
 * interrupt1.c
 *
 *  Created on: 3 maj 2026
 *      Author: kosmi
 */

#include <avr/interrupt.h>

#include "../Headers/led_display.h"

// lang = 1 - common language (Arabic numerals)
// lang = 2 - elvish language

volatile uint8_t lang = 0b00000001;

ISR(INT1_vect) {
	lang <<= lang;
	if (lang >= 4)
		lang = 1;
}
