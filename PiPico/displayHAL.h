/*
 * displayHAL.h
 *
 * Created: 2020-06-15 23:51:23
 *  Author: Trojan
 */ 

#include <stdbool.h>

#ifndef DISPLAYHAL_H_
#define DISPLAYHAL_H_

#define REFRESH_100US_INTERVAL_NUMBER 17
#define CROSSFADE_DURATION_MS 1000UL
#define CROSSFADE_100US_INTERVAL_NUMBER (CROSSFADE_DURATION_MS*10/REFRESH_100US_INTERVAL_NUMBER)

#define PIN_TUBE_1 2
#define PIN_TUBE_2 3 
#define PIN_TUBE_3 4
#define PIN_TUBE_4 5

#define PIN_A 9
#define PIN_B 7
#define PIN_C 6
#define PIN_D 8

void
displayHALInit();

void
displayHAL100usStep();

void
displayHALSetDim(bool _dim);

void
displayHALToggleDim();

void
displayHALSetCrossfade(unsigned char a, unsigned char b, unsigned char c, unsigned char d);

void
displayHALSetImmediatly(unsigned char a, unsigned char b, unsigned char c, unsigned char d);

#endif /* DISPLAYHAL_H_ */
