/*
 * lcd.c
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#include "../lcd_hd44780/lcd.h"

// private zone
static inline void lcd_send_half(uint8_t data);

void init_lcd(void) {
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
	while (*str)
		lcd_write_data(*str++);
}

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
