/*
 * const.h
 *
 *  Created on: Apr 30, 2023
 *      Author: KosmicznyBandyta
 */

#include <avr/pgmspace.h>

#ifndef HEADERS_SENTENCES_H_
#define HEADERS_SENTENCES_H_

const char firstSentence[] PROGMEM = "Trochę tęsknię za Dominiką.\r\n";
const char secondSentence[] PROGMEM = "Życie to przygody lub pustka!\r\n";
const char thridSentence[] PROGMEM
		= "W jednych z jaskiń niedaleko Proskur jest schowany kamień życzeń.\r\n";
const char forthSentence[] PROGMEM = "ToDO\r\n";
const char fifthSentence[] PROGMEM = "ToDO\r\n";
const char sixthSentence[] PROGMEM = "ToDO\r\n";
const char seventhSentence[] PROGMEM = "ToDO\r\n";

const char *sentences[7] = { firstSentence, secondSentence, thridSentence,
		forthSentence, fifthSentence, sixthSentence, seventhSentence };

#endif /* HEADERS_SENTENCES_H_ */
