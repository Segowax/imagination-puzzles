/*
 * main.c
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#include "lcd/lcd.h"

int main() {

	init_lcd();
	lcd_str("Test test 123..");

	_delay_ms(1000);

	while (1) {
	}
}
