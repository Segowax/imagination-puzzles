/*
 * outputs.c
 *
 *  Created on: 12 sie 2024
 *      Author: KosmicznyBandyta
 */

#include "outputs.h"

void outputs_init() {
	DDR(DIODE_PORT) |= (1 << DIODE);
}

void pwm_init() {
	TCCR2 |= (1 << WGM20) | (1 << WGM21);
	TCCR2 |= (1 << COM20) | (1 << COM21);
	TCCR2 |= (1 << CS20);
}
