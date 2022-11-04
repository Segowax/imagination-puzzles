/*
 * leds.h
 *
 *  Created on: 30 pa� 2022
 *      Author: KosmicznyBandyta
 */

#ifndef LEDS_H_
#define LEDS_H_

#define LEDS_DDR DDRD
#define LEDS_PORT PORTD
#define LED1_PIN (1 << PD0)
#define LED2_PIN (1 << PD1)
#define LED3_PIN (1 << PD2)
#define LED4_PIN (1 << PD3)
#define LED5_PIN (1 << PD4)
#define LED6_PIN (1 << PD5)
#define LED7_PIN (1 << PD6)
#define LED8_PIN (1 << PD7)
#define TOGGLE_LED1_PIN LEDS_PORT ^= LED1_PIN
#define TOGGLE_LED2_PIN LEDS_PORT ^= LED2_PIN
#define TOGGLE_LED3_PIN LEDS_PORT ^= LED3_PIN
#define TOGGLE_LED4_PIN LEDS_PORT ^= LED4_PIN
#define TOGGLE_LED5_PIN LEDS_PORT ^= LED5_PIN
#define TOGGLE_LED6_PIN LEDS_PORT ^= LED6_PIN
#define TOGGLE_LED7_PIN LEDS_PORT ^= LED7_PIN
#define TOGGLE_LED8_PIN LEDS_PORT ^= LED8_PIN
#define OFF_LED1_PIN LEDS_PORT &= ~LED1_PIN
#define OFF_LED2_PIN LEDS_PORT &= ~LED2_PIN
#define OFF_LED3_PIN LEDS_PORT &= ~LED3_PIN
#define OFF_LED4_PIN LEDS_PORT &= ~LED4_PIN
#define OFF_LED5_PIN LEDS_PORT &= ~LED5_PIN
#define OFF_LED6_PIN LEDS_PORT &= ~LED6_PIN
#define OFF_LED7_PIN LEDS_PORT &= ~LED7_PIN
#define OFF_LED8_PIN LEDS_PORT &= ~LED8_PIN
#define ON_LED1_PIN LEDS_PORT |= LED1_PIN
#define ON_LED2_PIN LEDS_PORT |= LED2_PIN
#define ON_LED3_PIN LEDS_PORT |= LED3_PIN
#define ON_LED4_PIN LEDS_PORT |= LED4_PIN
#define ON_LED5_PIN LEDS_PORT |= LED5_PIN
#define ON_LED6_PIN LEDS_PORT |= LED6_PIN
#define ON_LED7_PIN LEDS_PORT |= LED7_PIN
#define ON_LED8_PIN LEDS_PORT |= LED8_PIN

void init_leds();

#endif /* LEDS_H_ */
