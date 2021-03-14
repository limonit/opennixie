/*
 * displayHAL.c
 *
 * Created: 2020-06-15 23:51:05
 *  Author: Trojan
 */ 

#include "displayHAL.h"
#include <util/delay.h>
#include <string.h>


//unsigned char lookUpTable[11] = {4, 6, 7, 3, 2, 8, 9, 0, 1, 5, 12};
unsigned char lookUpTable[11] = {5, 4, 6, 7, 3, 2, 8, 9, 0, 1, 12};
unsigned char displayContent[4] = {10, 10, 10, 10};
unsigned char displayContent2[4] = {10, 10, 10, 10};
bool dim = false;
unsigned char stage = REFRESH_100US_INTERVAL_NUMBER;
	
void
displayHALTurnOff()
{
	TUBE1PORT &= ~(1<<TUBE1PIN);
	TUBE2PORT &= ~(1<<TUBE2PIN);
	TUBE3PORT &= ~(1<<TUBE3PIN);
	TUBE4PORT &= ~(1<<TUBE4PIN);
	
	INPUTAPORT |= 1<<INPUTAPIN;
	INPUTBPORT |= 1<<INPUTBPIN;
	INPUTCPORT |= 1<<INPUTCPIN;
	INPUTDPORT |= 1<<INPUTDPIN;
}

void inline
displayHALInit()
{
	TUBE1DDR |= 1<<TUBE1PIN;
	TUBE2DDR |= 1<<TUBE2PIN;
	TUBE3DDR |= 1<<TUBE3PIN;
	TUBE4DDR |= 1<<TUBE4PIN;
	
	INPUTADDR |= 1<<INPUTAPIN;
	INPUTBDDR |= 1<<INPUTBPIN;
	INPUTCDDR |= 1<<INPUTCPIN;
	INPUTDDDR |= 1<<INPUTDPIN;
	
	displayHALTurnOff();
}

void
displayHAL100usStep()
{
	static unsigned char multiplexCounter = 0;
	static unsigned char currentTube = 0;
	static int stageCounter = 0;
	
	if (++multiplexCounter == REFRESH_100US_INTERVAL_NUMBER)
	{
		multiplexCounter = 0;
		displayHALTurnOff();
		
		static unsigned char cntr = 0;
		if (!dim || (++cntr & 1)) {
			if(++currentTube > 3) currentTube=0;

			if (currentTube == 0) {
				TUBE1PORT |= 1<<TUBE1PIN;
			}
			if (currentTube == 1) {
				TUBE2PORT |= 1<<TUBE2PIN;
			}
			if (currentTube == 2) {
				TUBE3PORT |= 1<<TUBE3PIN;
			}
			if (currentTube == 3) {
				TUBE4PORT |= 1<<TUBE4PIN;
			}
		}
	}

	if (++stageCounter > CROSSFADE_100US_INTERVAL_NUMBER)
	{
		if (stage <= REFRESH_100US_INTERVAL_NUMBER) {
			stage++;
		}
		stageCounter=0;
	}
	
	unsigned char outputDigit;
	
	if (multiplexCounter >= stage)
	{
		outputDigit = lookUpTable[displayContent[currentTube]];
	} else {
		outputDigit = lookUpTable[displayContent2[currentTube]];
	}
		
	if (!(outputDigit & 0x1)) {
		INPUTAPORT &= ~(1<<INPUTAPIN);
		} else {
		INPUTAPORT |= 1<<INPUTAPIN;
	}
	if (!(outputDigit & 0x2)) {
		INPUTBPORT &= ~(1<<INPUTBPIN);
		} else {
		INPUTBPORT |= 1<<INPUTBPIN;
	}
	if (!(outputDigit & 0x4)) {
		INPUTCPORT &= ~(1<<INPUTCPIN);
		} else {
		INPUTCPORT |= 1<<INPUTCPIN;
	}
	if (!(outputDigit & 0x8)) {
		INPUTDPORT &= ~(1<<INPUTDPIN);
		} else {
		INPUTDPORT |= 1<<INPUTDPIN;
	}
}

void
displayHALSetDim(bool _dim)
{
	dim = _dim;
}

void
displayHALToggleDim()
{
	if (dim) {
		dim = false;
	} else {
		dim = true;
	}
}

void
displayHALSetCrossfade(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
	memcpy(displayContent, displayContent2, sizeof(displayContent));
	displayContent2[0] = a;
	displayContent2[1] = b;
	displayContent2[2] = c;
	displayContent2[3] = d;
	//if (!memcmp(displayContent2, displayContent, sizeof(displayContent))) {
	    stage = 0;
	//}
}

void
displayHALSetImmediatly(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
	stage = REFRESH_100US_INTERVAL_NUMBER;
	displayContent2[0] = a;
	displayContent2[1] = b;
	displayContent2[2] = c;
	displayContent2[3] = d;
}

void
displayHALTestNixies()
{
	displayHALTurnOff();
	TUBE1PORT |= 1<<TUBE1PIN;
	unsigned char i;
	for (unsigned char j=0; j<10; j++) {
		i = lookUpTable[j];
		if (!(i & 0x1)) {
			INPUTAPORT &= ~(1<<INPUTAPIN);
			} else {
			INPUTAPORT |= 1<<INPUTAPIN;
		}
		if (!(i & 0x2)) {
			INPUTBPORT &= ~(1<<INPUTBPIN);
			} else {
			INPUTBPORT |= 1<<INPUTBPIN;
		}
		if (!(i & 0x4)) {
			INPUTCPORT &= ~(1<<INPUTCPIN);
			} else {
			INPUTCPORT |= 1<<INPUTCPIN;
		}
		if (!(i & 0x8)) {
			INPUTDPORT &= ~(1<<INPUTDPIN);
			} else {
			INPUTDPORT |= 1<<INPUTDPIN;
		}
		_delay_ms(150);
	}
	
	displayHALTurnOff();
	TUBE2PORT |= 1<<TUBE2PIN;
	for (unsigned char j=0; j<10; j++) {
		i = lookUpTable[j];
		if (!(i & 0x1)) {
			INPUTAPORT &= ~(1<<INPUTAPIN);
			} else {
			INPUTAPORT |= 1<<INPUTAPIN;
		}
		if (!(i & 0x2)) {
			INPUTBPORT &= ~(1<<INPUTBPIN);
			} else {
			INPUTBPORT |= 1<<INPUTBPIN;
		}
		if (!(i & 0x4)) {
			INPUTCPORT &= ~(1<<INPUTCPIN);
			} else {
			INPUTCPORT |= 1<<INPUTCPIN;
		}
		if (!(i & 0x8)) {
			INPUTDPORT &= ~(1<<INPUTDPIN);
			} else {
			INPUTDPORT |= 1<<INPUTDPIN;
		}
		_delay_ms(150);
	}
	
	displayHALTurnOff();
	TUBE3PORT |= 1<<TUBE3PIN;
	for (unsigned char j=0; j<10; j++) {
		i = lookUpTable[j];
		if (!(i & 0x1)) {
			INPUTAPORT &= ~(1<<INPUTAPIN);
			} else {
			INPUTAPORT |= 1<<INPUTAPIN;
		}
		if (!(i & 0x2)) {
			INPUTBPORT &= ~(1<<INPUTBPIN);
			} else {
			INPUTBPORT |= 1<<INPUTBPIN;
		}
		if (!(i & 0x4)) {
			INPUTCPORT &= ~(1<<INPUTCPIN);
			} else {
			INPUTCPORT |= 1<<INPUTCPIN;
		}
		if (!(i & 0x8)) {
			INPUTDPORT &= ~(1<<INPUTDPIN);
			} else {
			INPUTDPORT |= 1<<INPUTDPIN;
		}
		_delay_ms(150);
	}
	
	displayHALTurnOff();
	TUBE4PORT |= 1<<TUBE4PIN;
	for (unsigned char j=0; j<10; j++) {
		i = lookUpTable[j];
		if (!(i & 0x1)) {
			INPUTAPORT &= ~(1<<INPUTAPIN);
			} else {
			INPUTAPORT |= 1<<INPUTAPIN;
		}
		if (!(i & 0x2)) {
			INPUTBPORT &= ~(1<<INPUTBPIN);
			} else {
			INPUTBPORT |= 1<<INPUTBPIN;
		}
		if (!(i & 0x4)) {
			INPUTCPORT &= ~(1<<INPUTCPIN);
			} else {
			INPUTCPORT |= 1<<INPUTCPIN;
		}
		if (!(i & 0x8)) {
			INPUTDPORT &= ~(1<<INPUTDPIN);
			} else {
			INPUTDPORT |= 1<<INPUTDPIN;
		}
		_delay_ms(150);
	}
	
	displayHALTurnOff();
}