/*
 * inputs.c
 *
 *  Created on: Nov 10, 2023
 *      Author: KosmicznyBandyta
 */

#include "../Headers/inputs.h"

void init_inputs() {
	// set all inputs
	DDR(PHOTOTRANSITOR_PORT) &= ~(1 << PHOTOTRANSITOR);
	DDR(BUTTON_PORT) &= ~(1 << BUTTON);
	DDR(SECRET_PORT) &= ~(1 << SECRET);

	// enable internal VCC resistor
	PORT(PHOTOTRANSITOR_PORT) |= (1 << PHOTOTRANSITOR);
	PORT(BUTTON_PORT) |= (1 << BUTTON);
	PORT(SECRET_PORT) |= (1 << SECRET);

	// Enable INT1 interrupt
	GICR |= (1 << INT1); // External Interrupt Request 1 Enable
}
