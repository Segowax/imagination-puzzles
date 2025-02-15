/*
 * configuration.h
 *
 *  Created on: Nov 16, 2023
 *      Author: KosmicznyBandyta
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

/* Adjust these configurations */
/* LCD Config */
#define LCD_Y 2
#define LCD_X 16
#define USE_RW 1
#define USE_LCD_CURSOR_HOME 0
#define USE_LCD_CURSOR_ON 0
#define USE_LCD_CURSOR_BLINK 0
#define USE_LCD_STR_P 1
#define USE_LCD_STR_E 1
#define USE_LCD_INT 1
#define USE_LCD_HEX 1
#define USE_LCD_DEFCHAR 1
#define USE_LCD_DEFCHAR_E 1
#define USE_LCD_DEFCHAR_P 1
#define USE_LCD_LED 1
/* LCD Pins*/
#define LCD_D7PORT C
#define LCD_D6PORT C
#define LCD_D5PORT C
#define LCD_D4PORT C
#define LCD_D7 0
#define LCD_D6 1
#define LCD_D5 2
#define LCD_D4 3
#define LCD_RSPORT B
#define LCD_RWPORT B
#define LCD_EPORT B
#define LCD_RS 2
#define LCD_RW 1
#define LCD_E 0
#define LCD_LEDPORT B
#define LCD_LED 3
/*******************************/
/* BUTTONS AND DIODES */
#define BUTTON_PORT D
#define BUTTON 6
#define DIODE_PORT D
#define DIODE 7
/*******************************/

#endif /* CONFIGURATION_H_ */
