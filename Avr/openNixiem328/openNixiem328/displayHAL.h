/*
 * displayHAL.h
 *
 * Created: 2020-06-15 23:51:23
 *  Author: Trojan
 */ 

#include <avr/io.h>
#include <stdbool.h>

#ifndef DISPLAYHAL_H_
#define DISPLAYHAL_H_

#define REFRESH_100US_INTERVAL_NUMBER 17
#define CROSSFADE_DURATION_MS 1000UL
#define CROSSFADE_100US_INTERVAL_NUMBER (CROSSFADE_DURATION_MS*10/REFRESH_100US_INTERVAL_NUMBER)

#define TUBE1DDR  DDRD
#define TUBE1PORT PORTD
#define TUBE1PIN  PORTD1

#define TUBE2DDR  DDRD
#define TUBE2PORT PORTD
#define TUBE2PIN  PORTD0

#define TUBE3DDR  DDRC
#define TUBE3PORT PORTC
#define TUBE3PIN  PORTC3

#define TUBE4DDR  DDRC
#define TUBE4PORT PORTC
#define TUBE4PIN  PORTC2

#define INPUTADDR  DDRB
#define INPUTAPORT PORTB
#define INPUTAPIN  PORTB0

#define INPUTBDDR  DDRB
#define INPUTBPORT PORTB
#define INPUTBPIN  PORTB2

#define INPUTCDDR  DDRB
#define INPUTCPORT PORTB
#define INPUTCPIN  PORTB3

#define INPUTDDDR  DDRB
#define INPUTDPORT PORTB
#define INPUTDPIN  PORTB1

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

void
displayHALTestNixies();

#endif /* DISPLAYHAL_H_ */