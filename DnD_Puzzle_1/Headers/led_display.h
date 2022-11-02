/*
 * ledDisplay.h
 *
 *  Created on: 30 paü 2022
 *      Author: KosmicznyBandyta
 */

#ifndef HEADERS_LED_DISPLAY_H_
#define HEADERS_LED_DISPLAY_H_

#define ANODE_DDR DDRA
#define ANODE_PORT PORTA
#define ANODE1 (1 << PA0)
#define ANODE2 (1 << PA1)
#define ANODE3 (1 << PA2)
#define ANODE4 (1 << PA3)
#define SEGMENTS_DDR DDRC
#define SEGMENTS_PORT PORTC
#define SEGMENT_A (1 << PC0)
#define SEGMENT_B (1 << PC1)
#define SEGMENT_C (1 << PC2)
#define SEGMENT_D (1 << PC3)
#define SEGMENT_E (1 << PC4)
#define SEGMENT_F (1 << PC5)
#define SEGMENT_G (1 << PC6)
#define SEGMENT_H (1 << PC7)
#define SHOW_ZERO SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F
#define SHOW_ONE SEGMENT_B | SEGMENT_C
#define SHOW_TWO SEGMENT_A | SEGMENT_B | SEGMENT_D | SEGMENT_E | SEGMENT_G
#define SHOW_THREE SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_G
#define SHOW_FOUR SEGMENT_B | SEGMENT_C | SEGMENT_F | SEGMENT_G
#define SHOW_FIVE SEGMENT_A | SEGMENT_F | SEGMENT_G | SEGMENT_C | SEGMENT_D
#define SHOW_SIX SEGMENT_A | SEGMENT_F | SEGMENT_E | SEGMENT_D | SEGMENT_C | SEGMENT_G
#define SHOW_SEVEN SEGMENT_A | SEGMENT_B | SEGMENT_C
#define SHOW_EIGHT SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G
#define SHOW_NINE SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_F | SEGMENT_G

volatile uint8_t digit1;
volatile uint8_t digit2;
volatile uint8_t digit3;
volatile uint8_t digit4;

void initLedDisplay();
void disposeLedDisplay();
void countToZeroFrom(uint32_t number, uint16_t seconds);

#endif /* HEADERS_LED_DISPLAY_H_ */
