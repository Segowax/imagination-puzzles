/*
 * leds.c
 *
 *  Created on: 1 lis 2022
 *      Author: KosmicznyBandyta
 */

#include <avr/io.h>

#include "../Headers/leds.h"

void init_leds() {
	LEDS_DDR |= LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN | LED5_PIN | LED6_PIN
			| LED7_PIN | LED8_PIN;
	LEDS_PORT |= LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN | LED5_PIN | LED6_PIN
			| LED7_PIN | LED8_PIN;
}
