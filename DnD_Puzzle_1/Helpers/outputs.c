/*
 * outputs.c
 *
 *  Created on: Nov 10, 2023
 *      Author: KosmicznyBandyta
 */

#include "../Headers/outputs.h"

void init_outputs() {
	// set all outputs
	DDR(SPEAKER_PORT) |= (1 << SPEAKER);
	// set state of all outputs connected to VCC to high
	PORT(SPEAKER_PORT) |= (1 << SPEAKER);
}
