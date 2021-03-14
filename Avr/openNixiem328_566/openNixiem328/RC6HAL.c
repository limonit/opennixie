/*
 * RC6HAL.c
 *
 * Created: 2020-10-14 23:18:06
 *  Author: Trojan
 */ 
#include "RC6HAL.h"
#include "RC6.h"
#include <avr/io.h>

extern RC6Decoder rc6decoder;

void
RC6HALInit()
{
    IRDDR &= ~(1<<IRPIN);	
	TCCR1B |= 1<<CS11;
}

bool
RCHAL6GetPinState()
{
	return IRPORT &= (1<<IRPIN);
}

void
RC6HALDecoderStep()
{
	static bool pinState = true;
	if (RCHAL6GetPinState() != pinState) {
		RC6DecoderOnPinChange(rc6decoder);
		pinState = RCHAL6GetPinState();
	}
}

unsigned int
RC6GetMicrosecondTimer()
{
	return TCNT1;
}


