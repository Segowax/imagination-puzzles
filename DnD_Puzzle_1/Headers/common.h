/*
 * common.h
 *
 *  Created on: Nov 8, 2023
 *      Author: KosmicznyBandyta
 */
#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

#ifndef HEADERS_COMMON_H_
#define HEADERS_COMMON_H_

#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)

#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)

#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

#define P(x, y) MY_P(x, y)
#define MY_P(x, y) (P##x##y)

#endif /* HEADERS_COMMON_H_ */
