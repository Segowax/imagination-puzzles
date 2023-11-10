/*
 * lcd.h
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#define LCD_Y 2
#define LCD_X 16
#define USE_RW 1
#define LCD_D7PORT C
#define LCD_D6PORT C
#define LCD_D5PORT C
#define LCD_D4PORT C
#define LCD_D7 4
#define LCD_D6 3
#define LCD_D5 2
#define LCD_D4 1

#define LCD_RSPORT B
#define LCD_RWPORT B
#define LCD_EPORT B
#define LCD_RS 2
#define LCD_RW 1
#define LCD_E 0

#if ((LCD_Y == 4) && (LCD_X == 20))
#define LCD_LINE1 0x00
#define LCD_LINE2 0x28
#define LCD_LINE3 0x14
#define LCD_LINE4 0x54
#else
#define LCD_LINE1 0x00
#define LCD_LINE2 0x40
#define LCD_LINE3 0x10
#define LCD_LINE4 0x50
#endif

#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)

#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)

#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

void init_lcd();
void data_dir_out();

#endif /* LCD_LCD_H_ */
