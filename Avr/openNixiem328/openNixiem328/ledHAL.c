/*
 * ledHAL.c
 *
 * Created: 2020-09-14 20:42:58
 *  Author: Trojan
 */ 

#include "ledHAL.h"

void
ledHALinit()
{
	LEDDDR |= 1<<LEDPIN;
    LEDPORT &= ~(1<<LEDPIN);
}

inline void ledHALon()
{
	LEDPORT |= 1<<LEDPIN;
}

inline void ledHALoff()
{
	LEDPORT &= ~(1<<LEDPIN);	
}

void
ledHALswitch (bool state)
{
	if (state) {
		ledHALon();
	} else {
		ledHALoff();
	}
}

void
ledHALToggle()
{
	if (LEDPORT & (1<<LEDPIN)) {
		ledHALoff();
	} else {
		ledHALon();
	}
}