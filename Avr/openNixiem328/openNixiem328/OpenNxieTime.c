/*
 * OpenNxieTime.c
 *
 * Created: 2020-09-11 21:55:21
 *  Author: Trojan
 */ 
#include "OpenNixieTime.h"
#include "DS3231.h"

volatile OpenNixieTime openNixieTime;

struct OpenNixieTime_t
{
	signed char seconds;
	signed char minutes;
	signed char hours;
};

void openNixieTimeGetHAL()
{
	char time[3];
	ds1307getTime(time);
	
	openNixieTime.seconds = time[0] / 16 * 10 + time[0] % 16;
	openNixieTime.minutes = time[1] / 16 * 10 + time[1] % 16;
	openNixieTime.hours = time[2] / 16 * 10 + time[2] % 16;
}

void openNixieTimeStoreHAL()
{
	char time[3];
	time[0] = 0;
	time[1] = (openNixieTime.minutes / 10) * 16 + openNixieTime.minutes % 10;
	time[2] = (openNixieTime.hours / 10) * 16 + openNixieTime.hours % 10;
	ds1307setTime(time);
}

void openNixieIncrementTime()
{
	openNixieTime.minutes++;
	if (openNixieTime.minutes >= 60) {
		openNixieTime.minutes = 0;
		openNixieTime.hours++;
		if (openNixieTime.hours >= 24) {
			openNixieTime.hours = 0;
		}
	}
	
}

void openNixieTimeTick()
{
	openNixieTime.seconds++;
	if (openNixieTime.seconds >= 60) {
		openNixieTime.seconds = 0;
		openNixieIncrementTime();
	}
}

void openNixieDecrementTime()
{
	openNixieTime.minutes--;
	if (openNixieTime.minutes < 0) {
		openNixieTime.minutes = 59;
		openNixieTime.hours--;
		if (openNixieTime.hours < 0) {
			openNixieTime.hours = 23;
		}
	}
}

void openNixieTimeResetSeconds()
{
	openNixieTime.seconds = 0;
}

char openNixieTimeGetMinutes()
{
	return openNixieTime.minutes;
}

char openNixieTimeGetHours()
{
	return openNixieTime.hours;
}

char openNixieTimeGetSeconds()
{
	return openNixieTime.seconds;
}