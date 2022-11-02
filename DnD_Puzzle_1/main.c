/*
 * main.c
 *
 *  Created on: 6 sty 2022
 *      Author: kosmicznyBandyta
 */

// provided header files
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// my header files
#include "Headers/leds.h"
#include "Headers/buttons.h"
#include "Headers/led_display.h"

int main(void) {
	uint8_t tab[] = { 1, 3, 7, 15, 31, 63, 127, 255, 254, 252, 248, 240, 224,
			192, 128, 128, 192, 224, 240, 248, 252, 254, 255, 127, 63, 31, 15,
			7, 3, 1 };
	uint8_t i = 0;

	initMyLeds();
	initMyButtons();

	sei();
	initLedDisplay();
	countToZeroFrom(1000, 300);
	while (1) {
		if (isKeyDown(1)) {
			LEDS_PORT = 0xff;
			i = 0;
			while (isKeyDown(1)) {
				_delay_ms(1);
			}
		}
		if (isKeyDown(2)) {
			i = 1;
			for (;;) {
				while (i < 128) {
					i <<= 1;
					LEDS_PORT = ~i;
					_delay_ms(50);
				}
				while (i > 1) {
					i >>= 1;
					LEDS_PORT = ~i;
					_delay_ms(50);
				}
				if (isKeyDown(1))
					break;
			}
		}
		if (isKeyDown(3)) {
			i = 0;
			for (;;) {
				LEDS_PORT = ~tab[i++];
				_delay_ms(50);
				if (i == sizeof(tab))
					i = 0;
				if (isKeyDown(1)) {
					break;
				}
			}
		}
		if (isKeyDown(4)) {
		}
		if (isKeyDown(5)) {
			disposeLedDisplay();
		}
	}
}
