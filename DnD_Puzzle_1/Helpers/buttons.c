/*
 * buttons.c
 *
 *  Created on: 1 lis 2022
 *      Author: KosmicznyBandyta
 */

#include <avr/io.h>
#include <util/delay.h>

#include "../Headers/buttons.h"

void initMyButtons() {
	BUTTONS_DDR &= ~(BUTTON1_PIN | BUTTON2_PIN | BUTTON3_PIN | BUTTON4_PIN
			| BUTTON5_PIN);
	BUTTONS_PORT |=
	BUTTON1_PIN | BUTTON2_PIN | BUTTON3_PIN | BUTTON4_PIN | BUTTON5_PIN; // enable internal VCC resistor
}

uint8_t isKeyDown(uint8_t key) {
	switch (key) {
	case 1:
		_delay_ms(20);
		if (IS_BUTTON1_DOWN) {
			return 1;
		}
		break;
	case 2:
		_delay_ms(20);
		if (IS_BUTTON2_DOWN) {
			return 1;
		}
		break;
	case 3:
		_delay_ms(20);
		if (IS_BUTTON3_DOWN) {
			return 1;
		}
		break;
	case 4:
		_delay_ms(20);
		if (IS_BUTTON4_DOWN) {
			return 1;
		}
		break;
	case 5:
		_delay_ms(20);
		if (IS_BUTTON5_DOWN) {
			return 1;
		}
		break;
	default:
		return 0;
		break;
	}

	return 0;
}
