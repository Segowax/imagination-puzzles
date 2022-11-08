/*
 * buttons.c
 *
 *  Created on: 1 lis 2022
 *      Author: KosmicznyBandyta
 */

#include <avr/io.h>
#include <util/delay.h>

#include "../Headers/keys.h"

void init_buttons() {
	KEYS_DDR &= ~(KEY1_PIN | KEY2_PIN | KEY3_PIN | KEY4_PIN | KEY5_PIN);
	KEYS_PORT |=
	KEY1_PIN | KEY2_PIN | KEY3_PIN | KEY4_PIN | KEY5_PIN; // enable internal VCC resistor

	// Enable INT2 interrupt
	MCUCSR |= (1 << ISC2); // Rising edge on INT2 activates the interrupt
	GICR |= (1 << INT2); // External Interrupt Request 2 Enable
}

uint8_t is_key_down(uint8_t key) {
	switch (key) {
	case 1:
		_delay_ms(20);
		if (IS_KEY1_DOWN) {
			return 1;
		}
		break;
	case 2:
		_delay_ms(20);
		if (IS_KEY2_DOWN) {
			return 1;
		}
		break;
	case 3:
		_delay_ms(20);
		if (IS_KEY3_DOWN) {
			return 1;
		}
		break;
	case 4:
		_delay_ms(20);
		if (IS_KEY4_DOWN) {
			return 1;
		}
		break;
	case 5:
		_delay_ms(20);
		if (IS_KEY5_DOWN) {
			return 1;
		}
		break;
	default:
		return 0;
		break;
	}

	return 0;
}
