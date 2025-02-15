/*
 * lcd.c
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#include "../lcd_hd44780/lcd.h"
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <avr/io.h>
#include <util/delay.h>

// ********* private zone **********
void data_dir_out(void);
void data_dir_in(void);
static inline void lcd_send_half(uint8_t data);
void lcd_write_byte(unsigned char _data);
void lcd_write_cmd(uint8_t cmd);
void lcd_write_data(uint8_t data);

// to remove the warnings?
char* itoa(int, char*, int);
size_t strlen( const char * str );
char* strcpy( char * dest, const char * src );
char* strcat( char * destination, const char * source );
void* malloc( size_t size );
void free(void *ptr);
// *********************************

void lcd_init(void) {
	data_dir_out();
	DDR(LCD_RSPORT) |= (1 << LCD_RS);
	DDR(LCD_EPORT) |= (1 << LCD_E);
#if USE_RW == 1
	DDR(LCD_RWPORT) |= (1 << LCD_RW);
#endif
	PORT(LCD_RSPORT) |= (1 << LCD_RS);
	PORT(LCD_EPORT) |= (1 << LCD_E);
#if USE_RW == 1
	PORT(LCD_RWPORT) |= (1 << LCD_RW);
#endif
#if USE_LCD_LED
	DDR(LCD_LEDPORT) |= (1 << LCD_LED);
#endif

	_delay_ms(15);
	PORT(LCD_RSPORT) &= ~(1 << LCD_RS);
	PORT(LCD_EPORT) &= ~(1 << LCD_E);
#if USE_RW == 1
	PORT(LCD_RWPORT) &= ~(1 << LCD_RW);
#endif

	SET_E;
	lcd_send_half(0x03);
	CLR_E;
	_delay_ms(4.1);

	SET_E;
	lcd_send_half(0x03);
	CLR_E;
	_delay_us(100);

	SET_E;
	lcd_send_half(0x03);
	CLR_E;
	_delay_us(100);

	SET_E;
	lcd_send_half(0x02);
	CLR_E;
	_delay_us(100);

	lcd_write_cmd(LCDC_FUNC | LCDC_FUNC_4B | LCD_FUNC_2L | LCD_FUNC_5x7);
	lcd_write_cmd(LCDC_ONOFF | LCDC_CURSOR_OFF);
	lcd_write_cmd(LCDC_ONOFF | LCDC_DISPLAY_ON);
	lcd_write_cmd(LCDC_ENTRY | LCDC_ENTRYR);
	lcd_cls();
}

void data_dir_out(void) {
	DDR(LCD_D7PORT) |= (1 << LCD_D7);
	DDR(LCD_D6PORT) |= (1 << LCD_D6);
	DDR(LCD_D5PORT) |= (1 << LCD_D5);
	DDR(LCD_D4PORT) |= (1 << LCD_D4);
}

void data_dir_in(void) {
	DDR(LCD_D7PORT) &= ~(1 << LCD_D7);
	DDR(LCD_D6PORT) &= ~(1 << LCD_D6);
	DDR(LCD_D5PORT) &= ~(1 << LCD_D5);
	DDR(LCD_D4PORT) &= ~(1 << LCD_D4);
}

static inline void lcd_send_half(uint8_t data) {
	if (data & (1 << 0))
		PORT(LCD_D4PORT) |= (1 << LCD_D4);
	else
		PORT(LCD_D4PORT) &= ~(1 << LCD_D4);

	if (data & (1 << 1))
		PORT(LCD_D5PORT) |= (1 << LCD_D5);
	else
		PORT(LCD_D5PORT) &= ~(1 << LCD_D5);

	if (data & (1 << 2))
		PORT(LCD_D6PORT) |= (1 << LCD_D6);
	else
		PORT(LCD_D6PORT) &= ~(1 << LCD_D6);

	if (data & (1 << 3))
		PORT(LCD_D4PORT) |= (1 << LCD_D7);
	else
		PORT(LCD_D7PORT) &= ~(1 << LCD_D7);
}

#if USE_RW == 1
static inline uint8_t lcd_read_half(void) {
	uint8_t result = 0;
	if (PIN(LCD_D4PORT) & (1 << LCD_D4))
		result |= (1 << 0);
	if (PIN(LCD_D4PORT) & (1 << LCD_D5))
		result |= (1 << 1);
	if (PIN(LCD_D4PORT) & (1 << LCD_D6))
		result |= (1 << 2);
	if (PIN(LCD_D4PORT) & (1 << LCD_D7))
		result |= (1 << 3);

	return result;
}

uint8_t lcd_read_byte(void) {
	uint8_t result = 0;
	data_dir_in();

	SET_RW;
	SET_E;
	result |= (lcd_read_half() << 4);
	CLR_E;
	SET_E;
	result |= (lcd_read_half());
	CLR_E;

	return result;
}

uint8_t check_BF(void) {
	CLR_RS;

	return lcd_read_byte();
}

#endif

void lcd_write_byte(unsigned char _data) {
	data_dir_out();

#if USE_RW == 1
	CLR_RW;
#endif

	SET_E;
	lcd_send_half(_data >> 4);
	CLR_E;

	SET_E;
	lcd_send_half(_data);
	CLR_E;

#if USE_RW == 1
	while (check_BF() & (1 << 7))
		;
#else
	_delay_us(120);
#endif
}

void lcd_write_cmd(uint8_t cmd) {
	CLR_RS;
	lcd_write_byte(cmd);
}

void lcd_write_data(uint8_t data) {
	SET_RS;
	lcd_write_byte(data);
}

void lcd_str(char *str) {
	register char sign;
	while ((sign = *str++))
		lcd_write_data((sign >= 0x80 && sign <= 0x87) ? (sign & 0x07) : sign);
}

#if USE_LCD_STR_P == 1
void lcd_str_P(char *str) {
	register char sign;
	while ((sign = pgm_read_byte(str++)))
		lcd_write_data((sign >= 0x80 && sign <= 0x87) ? (sign & 0x07) : sign);
}
#endif

#if USE_LCD_STR_E == 1
void lcd_str_E(char *str) {
	register char sign;
	while (1) {
		sign = eeprom_read_byte((uint8_t*) (str++));
		if (!sign || sign == 0xFF)
			break;
		else
			lcd_write_data(
					(sign >= 0x80 && sign <= 0x87) ? (sign & 0x07) : sign);
	}
}
#endif

#if USE_LCD_INT == 1
void lcd_int(int val) {
	char bufor[17];
	lcd_str(itoa(val, bufor, 10));
}

void lcd_int_with_label(char* text, int val) {
	lcd_cls();
	char bufor[17];
	char* part1 = text;
	char* part2 = itoa(val, bufor, 10);
	char *result = malloc(strlen(part1) + strlen(part2) + 1); // +1 for the null-terminator
    strcpy(result, part1);
    strcat(result, part2);

    lcd_str(result);
    free(result);
}
#endif

#if USE_LCD_HEX == 1
void lcd_hex(int val) {
	char bufor[17];
	lcd_str(itoa(val, bufor, 16));
}
#endif

#if USE_LCD_DEFCHAR
void lcd_defchar(uint8_t nr, const uint8_t *def_znak) {
	register uint8_t i, c;
	lcd_write_cmd(64 + ((nr & 0x07) * 8));
	for (i = 0; i < 8; i++) {
		c = *(def_znak++);
		lcd_write_data(c);
	}
}
#endif

#if USE_LCD_DEFCHAR_E
void lcd_defchar_E(uint8_t nr, const uint8_t *def_znak) {
	register uint8_t i, c;
	lcd_write_cmd(64 + ((nr & 0x07) * 8));
	for (i = 0; i < 8; i++) {
		c = eeprom_read_byte(def_znak++);
		lcd_write_data(c);
	}
}
#endif

#if USE_LCD_DEFCHAR_P
void lcd_defchar_P(uint8_t nr, const uint8_t *def_znak) {
	register uint8_t i, c;
	lcd_write_cmd(64 + ((nr & 0x07) * 8));
	for (i = 0; i < 8; i++) {
		c = pgm_read_byte(def_znak++);
		lcd_write_data(c);
	}
}
#endif

void lcd_cls(void) {
	lcd_write_cmd(LCDC_CLEAR);
#if USE_RW == 0
	_delay_ms(4.9);
#endif
}

#if USE_LCD_CURSOR_HOME == 1
void lcd_home(void) {
	lcd_write_cmd(LCDC_CLEAR | LCDC_HOME);
#if USE_RW == 0
		_delay_ms(4.9);
#endif
}
#endif

#if USE_LCD_CURSOR_ON == 1
void lcd_cursor_on(void) {
	lcd_write_cmd(LCDC_ONOFF | LCDC_DISPLAY_ON | LCDC_CURSOR_ON);
}

void lcd_cursor_off(void) {
	lcd_write_cmd(LCDC_ONOFF | LCDC_DISPLAY_ON);
}
#endif

#if USE_LCD_CURSOR_BLINK == 1
void lcd_cursor_blink_on(void) {
	lcd_write_cmd(
	LCDC_ONOFF | LCDC_DISPLAY_ON | LCDC_CURSOR_ON | LCDC_CURSOR_BLINKING_MODE);
}

void lcd_cursor_blink_off(void) {
	lcd_write_cmd(LCDC_ONOFF | LCDC_DISPLAY_ON);
}
#endif
