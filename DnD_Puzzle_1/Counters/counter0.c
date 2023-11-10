/*
 * counter0.c
 *
 *  Created on: 1 lis 2022
 *      Author: KosmicznyBandyta
 */

#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "../Headers/led_display.h"

const uint8_t commonDigitsTab[] PROGMEM = { SHOW_COMMON_ZERO, SHOW_COMMON_ONE,
SHOW_COMMON_TWO,
SHOW_COMMON_THREE, SHOW_COMMON_FOUR,
SHOW_COMMON_FIVE, SHOW_COMMON_SIX, SHOW_COMMON_SEVEN, SHOW_COMMON_EIGHT,
SHOW_COMMON_NINE };
const uint8_t elfDigitsTab[] PROGMEM = { SHOW_ELF_ZERO, SHOW_ELF_ONE,
SHOW_ELF_TWO,
SHOW_ELF_THREE, SHOW_ELF_FOUR,
SHOW_ELF_FIVE, SHOW_ELF_SIX, SHOW_ELF_SEVEN, SHOW_ELF_EIGHT,
SHOW_ELF_NINE };

static uint8_t i = 1;

// private method
void turn_on_anode(uint8_t anode);

// interrupt logic for timer/counter0
ISR(TIMER0_COMP_vect) {
	turn_on_anode(i);
	if (lang == 1) {
		if (i == 1)
			PORT(PORT_FOR_ALL_SEGMENTS) = pgm_read_byte(
					&elfDigitsTab[digit1]);
		else if (i == 2)
			PORT(PORT_FOR_ALL_SEGMENTS) = pgm_read_byte(
					&elfDigitsTab[digit2]);
		else if (i == 3)
			PORT(PORT_FOR_ALL_SEGMENTS) = pgm_read_byte(
					&elfDigitsTab[digit3]);
		else if (i == 4)
			PORT(PORT_FOR_ALL_SEGMENTS) = pgm_read_byte(
					&elfDigitsTab[digit4]);
	} else if (lang == 2) {
		if (i == 1)
			PORT(PORT_FOR_ALL_SEGMENTS) = pgm_read_byte(
					&commonDigitsTab[digit1]);
		else if (i == 2)
			PORT(PORT_FOR_ALL_SEGMENTS) = pgm_read_byte(
					&commonDigitsTab[digit2]);
		else if (i == 3)
			PORT(PORT_FOR_ALL_SEGMENTS) = pgm_read_byte(
					&commonDigitsTab[digit3]);
		else if (i == 4)
			PORT(PORT_FOR_ALL_SEGMENTS) = pgm_read_byte(
					&commonDigitsTab[digit4]);
	}
	i++;
	if (i > 4)
		i = 1;
}

void turn_on_anode(uint8_t anode) {
	// turn off all anodes
	PORT(ANODE1_PORT) |= (1 << ANODE1);
	PORT(ANODE2_PORT) |= (1 << ANODE2);
	PORT(ANODE3_PORT) |= (1 << ANODE3);
	PORT(ANODE4_PORT) |= (1 << ANODE4);

	// turn on proper anode
	if (anode == 1)
		PORT(ANODE1_PORT) &= ~(1 << ANODE1);
	else if (anode == 2)
		PORT(ANODE2_PORT) &= ~(1 << ANODE2);
	else if (anode == 3)
		PORT(ANODE3_PORT) &= ~(1 << ANODE3);
	else if (anode == 4)
		PORT(ANODE4_PORT) &= ~(1 << ANODE4);
}
