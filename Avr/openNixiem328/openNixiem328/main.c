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
#include "button.h"
#include "OpenNixieTime.h"
#include "modes/displayTimeMode.h"
#include "modes/setTimeMode.h"
#include "modes/setDimMode.h"
#include "modes/setLedMode.h"
#include "modes/setCrossfadeMode.h"
#include "main.h"
#include <avr/io.h>
#include <stdbool.h>
#include <time.h> 
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <stdlib.h>

volatile unsigned int sysTick;
volatile unsigned int sysTick50ms;

extern volatile OpenNixieTime openNixieTime;    // singleton time representation
struct button buttonUp;
struct button buttonDown;
struct button buttonIn;
unsigned sysTickLimit = 31250;

enum Mode mode;

void displayDigit(size_t digit);


int main(void)
{
	MCUSR = 0;
	wdt_reset();
	wdt_disable();
		
	displayHALInit();
	TCCR0B |=  1<<CS00;
	TIMSK0 |= 1;
	
	buttonInit(&buttonIn, &PINB, &DDRB, 7);
	buttonInit(&buttonUp, &PIND, &DDRD, 3);
	buttonInit(&buttonDown, &PIND, &DDRD, 2);
	
	i2c_init();

	displayHALTestNixies();

	sei();
	mode = DISPLAY_TIME;
	
    while (1) 
    {
		displayTimeModeOnEnter();
		while (mode == DISPLAY_TIME) {
			displayTimeModeLoop();
		}
		displayTimeModeOnExit();
		
		setTimeModeOnEnter();
		while (mode == SET_TIME || mode == SET_TIME_HACK) {
			setTimeModeLoop();
		}
		setTimeModeOnExit();

		setDimModeOnEnter();
		while (mode == SET_DIM) {
			setDimModeLoop();
		}
		setDimModeOnExit();	
		
		setLedModeOnEnter();
		while (mode == SET_LED) {
			setLedModeLoop();
		}
		setLedModeOnExit();	
		
		setCrossfadeModeOnEnter();
		while (mode == SET_CROSSFADE) {
			setCrossfadeModeLoop();
		}
		setCrossfadeModeOnExit();
    }
}


ISR(TIMER0_OVF_vect)
{
	static unsigned int intCntr = 0;
	static unsigned sysTickCntr = 0;
	static unsigned int sysTick50msCntr = 0;
	static unsigned int buttonCntr;
	
	if (++intCntr == 3)
	{
		displayHAL100usStep();
		intCntr = 0;
	}
	
	++sysTickCntr;
	if (sysTickCntr >= sysTickLimit) {
		sysTickCntr = 0;
		sysTick++;
//		wdt_reset();
		if (mode != SET_TIME_HACK) {
		    openNixieTimeTick();
		}
	}
	
	if (++sysTick50msCntr == 1562) {
		sysTick50msCntr = 0;
		sysTick50ms++;
	}
	
	if (++buttonCntr == 312) {
		buttonCntr = 0;
		button10MsStep(&buttonUp);
		button10MsStep(&buttonDown);
		button10MsStep(&buttonIn);
	}
}
