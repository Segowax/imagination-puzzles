/*
 * leds.h
 *
 *  Created on: 30 pa? 2022
 *      Author: KosmicznyBandyta
 */

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

#define OUTPUTS_DDR DDRD
#define OUTPUTS_PORT PORTD
#define OUTPUT1_PIN (1 << PD0)
#define OUTPUT2_PIN (1 << PD1)
#define OUTPUT3_PIN (1 << PD2)
#define OUTPUT4_PIN (1 << PD3)
#define OUTPUT5_PIN (1 << PD4)
#define OUTPUT6_PIN (1 << PD5)
#define OUTPUT7_PIN (1 << PD6)
#define OUTPUT8_PIN (1 << PD7)
#define TOGGLE_OUTPUT1_PIN OUTPUTS_PORT ^= OUTPUT1_PIN
#define TOGGLE_OUTPUT2_PIN OUTPUTS_PORT ^= OUTPUT2_PIN
#define TOGGLE_OUTPUT3_PIN OUTPUTS_PORT ^= OUTPUT3_PIN
#define TOGGLE_OUTPUT4_PIN OUTPUTS_PORT ^= OUTPUT4_PIN
#define TOGGLE_OUTPUT5_PIN OUTPUTS_PORT ^= OUTPUT5_PIN
#define TOGGLE_OUTPUT6_PIN OUTPUTS_PORT ^= OUTPUT6_PIN
#define TOGGLE_OUTPUT7_PIN OUTPUTS_PORT ^= OUTPUT7_PIN
#define TOGGLE_OUTPUT8_PIN OUTPUTS_PORT ^= OUTPUT8_PIN
#define ON_OUTPUT1_PIN OUTPUTS_PORT &= ~OUTPUT1_PIN
#define ON_OUTPUT2_PIN OUTPUTS_PORT &= ~OUTPUT2_PIN
#define ON_OUTPUT3_PIN OUTPUTS_PORT &= ~OUTPUT3_PIN
#define ON_OUTPUT4_PIN OUTPUTS_PORT &= ~OUTPUT4_PIN
#define ON_OUTPUT5_PIN OUTPUTS_PORT &= ~OUTPUT5_PIN
#define ON_OUTPUT6_PIN OUTPUTS_PORT &= ~OUTPUT6_PIN
#define ON_OUTPUT7_PIN OUTPUTS_PORT &= ~OUTPUT7_PIN
#define ON_OUTPUT8_PIN OUTPUTS_PORT &= ~OUTPUT8_PIN
#define OFF_OUTPUT1_PIN OUTPUTS_PORT |= OUTPUT1_PIN
#define OFF_OUTPUT2_PIN OUTPUTS_PORT |= OUTPUT2_PIN
#define OFF_OUTPUT3_PIN OUTPUTS_PORT |= OUTPUT3_PIN
#define OFF_OUTPUT4_PIN OUTPUTS_PORT |= OUTPUT4_PIN
#define OFF_OUTPUT5_PIN OUTPUTS_PORT |= OUTPUT5_PIN
#define OFF_OUTPUT6_PIN OUTPUTS_PORT |= OUTPUT6_PIN
#define OFF_OUTPUT7_PIN OUTPUTS_PORT |= OUTPUT7_PIN
#define OFF_OUTPUT8_PIN OUTPUTS_PORT |= OUTPUT8_PIN

void init_leds();

#endif /* OUTPUTS_H_ */
