/*
 * leds.c
 *
 *  Created on: 1 lis 2022
 *      Author: KosmicznyBandyta
 */

#include <avr/io.h>

#include "../Headers/outputs.h"

void init_leds() {
	OUTPUTS_DDR |= OUTPUT1_PIN | OUTPUT2_PIN | OUTPUT3_PIN | OUTPUT4_PIN
			| OUTPUT5_PIN | OUTPUT6_PIN | OUTPUT7_PIN | OUTPUT8_PIN;
	OUTPUTS_PORT |= OUTPUT1_PIN | OUTPUT2_PIN | OUTPUT3_PIN | OUTPUT4_PIN
			| OUTPUT5_PIN | OUTPUT6_PIN | OUTPUT7_PIN | OUTPUT8_PIN;
}
