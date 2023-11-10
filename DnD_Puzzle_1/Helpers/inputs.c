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

	// Enable INT2 interrupt
	MCUCSR |= (1 << ISC2); // Rising edge on INT2 activates the interrupt
	GICR |= (1 << INT2); // External Interrupt Request 2 Enable
}
