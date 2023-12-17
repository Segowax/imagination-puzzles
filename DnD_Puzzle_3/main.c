/*
 * main.c
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#include "lcd_hd44780/lcd.h"
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <util/delay.h>

const uint8_t tab1[] = { 0, 0, 14, 1, 15, 17, 15, 2 };
const uint8_t tab2[] PROGMEM = { 0, 0, 14, 1, 15, 17, 15, 2 };
const uint8_t tab3[] EEMEM = { 0, 0, 14, 1, 15, 17, 15, 2 };

//private zone
void display_text(char text[]);
void display_text_for(char text[], uint16_t ms);

int main() {
	lcd_init();

	_delay_ms(100);

	// display LED test
	SET_LED;
	_delay_ms(100);
	CLR_LED;
	_delay_ms(100);
	SET_LED;

	lcd_defchar(0x80, tab1);
	lcd_defchar_P(0x81, tab2);
	lcd_defchar_E(0x86, tab3);

	_delay_ms(100);

	while (1) {
		display_text_for("Test " "\x80", 1000);
		display_text_for("Test1 " "\x81", 1000);
		display_text_for("Test2 " "\x86", 1000);
		display_text_for("Test3 ", 1000);
	}
}

void display_text(char text[]) {
	lcd_cls();
	lcd_str(text);
}

void display_text_for(char text[], uint16_t ms) {
	lcd_cls();
	lcd_str(text);
	while (ms) {
		_delay_ms(1);
		ms--;
	}
}
