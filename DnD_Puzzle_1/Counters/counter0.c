/*
 * counter0.c
 *
 *  Created on: 1 lis 2022
 *      Author: KosmicznyBandyta
 */

#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "../Headers/led_display.h"

const uint8_t humanDigitsTab[] PROGMEM = { SHOW_ZERO, SHOW_ONE, SHOW_TWO,
		SHOW_THREE, SHOW_FOUR,
		SHOW_FIVE, SHOW_SIX, SHOW_SEVEN, SHOW_EIGHT, SHOW_NINE };
static uint8_t i = 1;

// interrupt logic for timer/counter0
ISR(TIMER0_COMP_vect) {
	ANODE_PORT = (ANODE_PORT & 0xf0) | (~i & 0x0f);
	if (i == 1)
		SEGMENTS_PORT = pgm_read_byte(&humanDigitsTab[digit1]);
	else if (i == 2)
		SEGMENTS_PORT = pgm_read_byte(&humanDigitsTab[digit2]);
	else if (i == 4)
		SEGMENTS_PORT = pgm_read_byte(&humanDigitsTab[digit3]);
	else if (i == 8)
		SEGMENTS_PORT = pgm_read_byte(&humanDigitsTab[digit4]);
	i <<= 1;
	if (i > 8)
		i = 1;
}
