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

#define TUBE4DDR  DDRD
#define TUBE4PORT PORTD
#define TUBE4PIN  PORTD1

#define TUBE3DDR  DDRD
#define TUBE3PORT PORTD
#define TUBE3PIN  PORTD0

#define TUBE2DDR  DDRC
#define TUBE2PORT PORTC
#define TUBE2PIN  PORTC3

#define TUBE1DDR  DDRC
#define TUBE1PORT PORTC
#define TUBE1PIN  PORTC2

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