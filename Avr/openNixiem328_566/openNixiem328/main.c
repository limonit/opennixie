/*
 * openNixiem328.c
 *
 * Created: 2020-06-10 21:44:40
 * Author : Trojan
 */ 

#include "openNixie.h"
#include "i2c_master.h"
#include "DS3231.h"
#include "displayHAL.h"
#include "RC6.h"
#include "RC6HAL.h"
#include "OpenNixieTime.h"
#include "modes/displayTimeMode.h"
#include "modes/setTimeMode.h"
#include "modes/setDimMode.h"
#include "modes/setCrossfadeMode.h"
#include "main.h"
#include <avr/io.h>
#include <stdbool.h>
#include <time.h> 
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/wdt.h>
#include <stdlib.h>

volatile unsigned sysTick;
volatile unsigned sysTick100ms;
unsigned sysTickLimit;
unsigned char rc6CommandReceived = 0xFF;
enum Mode mode;
RC6Decoder rc6decoder = NULL;

extern OpenNixieTime openNixieTime;    // singleton time representation

void
rc6callback(RC6Decoder self)
{
	rc6CommandReceived = RC6DecoderGetCommand(self);
	if (mode == SET_TIME) {
		setTimeModeOnCommandReceived();
		return;
	}
	
	if (mode == DISPLAY_TIME) {
	    displayTimeModeOnCommandReceived();
		return;
	}
	
	if (mode == SET_DIM) {
		setDimModeOnCommandReceived();
		return;
	}
	
	if (mode == SET_CROSSFADE) {
		setCrossfadeModeOnCommandReceived();
		return;
	}
}

int main(void)
{
	sysTickLimit = 31250;
	MCUSR = 0;
	wdt_reset();
	wdt_disable();
	displayHALInit();
	TCCR0B |=  1<<CS00;
	TIMSK0 |= 1;
	
	i2c_init();

	
	displayHALTestNixies();
	RC6HALInit();
	rc6decoder = RC6DecoderCreate(rc6callback, RCHAL6GetPinState, RC6GetMicrosecondTimer, true);

	sei();
	mode = DISPLAY_TIME;

	while (1)
	{
		if (mode == DISPLAY_TIME) {
			displayTimeModeOnEnter();
			while (mode == DISPLAY_TIME) {
				displayTimeModeLoop();
			}
			displayTimeModeOnExit();
		}
		
		if (mode == SET_TIME) {
			setTimeModeOnEnter();
			while (mode == SET_TIME) {
				setTimeModeLoop();
			}
			setTimeModeOnExit();
		}

		if (mode == SET_DIM) {
			setDimModeOnEnter();
			while (mode == SET_DIM) {
				setDimModeLoop();
			}
			setDimModeOnExit();
		}

		if (mode == SET_CROSSFADE) {
			setCrossfadeModeOnEnter();
			while (mode == SET_CROSSFADE) {
				setCrossfadeModeLoop();
			}
			setCrossfadeModeOnExit();
		}
	}
	free(rc6decoder);
}


ISR(TIMER0_OVF_vect)
{
	static unsigned intCntr = 0;
	static unsigned sysTickCntr = 0;
	static unsigned sysTick100msCntr = 0;
	
	if (++intCntr == 3)
	{
		displayHAL100usStep();
		intCntr = 0;
	}
	
	if (++sysTickCntr == sysTickLimit) {
		sysTickCntr = 0;
		sysTick++;
		openNixieTimeTick();
	}
	
	if (++sysTick100msCntr == 3124) {
		sysTick100msCntr = 0;
		sysTick100ms++;
	}

	RC6HALDecoderStep();
}