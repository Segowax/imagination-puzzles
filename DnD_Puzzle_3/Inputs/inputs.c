/*
 * inputs.c
 *
 *  Created on: 12 sie 2024
 *      Author: KosmicznyBandyta
 */

#include "inputs.h"

void inputs_init() {
	// set all inputs
	DDR(BUTTON_PORT) &= ~(1 << BUTTON);

	// enable internal VCC resistor
	PORT(BUTTON_PORT) |= (1 << BUTTON);
}

bool is_button_down() {
	if(IS_BUTTON_DOWN)
	{
		_delay_ms(10);
		if(IS_BUTTON_DOWN)
			return true;
	}

	return false;
}
