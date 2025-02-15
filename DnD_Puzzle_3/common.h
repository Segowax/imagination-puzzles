/*
 * common.h
 *
 *  Created on: 12 sie 2024
 *      Author: KosmicznyBandyta
 */

#ifndef COMMON_H_
#define COMMON_H_

#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)

#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)

#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

#endif /* COMMON_H_ */
