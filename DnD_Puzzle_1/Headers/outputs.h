/*
 * outputs.h
 *
 *  Created on: Nov 10, 2023
 *      Author: KosmicznyBandyta
 */

#include "../configuration.h"
#include "common.h"

#ifndef HEADERS_OUTPUTS_H_
#define HEADERS_OUTPUTS_H_

#define SPEAKER_TURN_ON PORT(SPEAKER_PORT) |= (1 << SPEAKER_PIN)
#define SPEAKER_TURN_OFF PORT(SPEAKER_PORT) &= ~(1 << SPEAKER_PIN)

void init_outputs();

#endif /* HEADERS_OUTPUTS_H_ */
