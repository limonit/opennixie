/*
 * OpenNixieTime.h
 *
 * Created: 2020-09-11 21:56:08
 *  Author: Trojan
 */ 


#ifndef OPENNIXIETIME_H_
#define OPENNIXIETIME_H_

typedef struct OpenNixieTime_t OpenNixieTime;

void openNixieTimeGetHAL();

void openNixieTimeStoreHAL();

void openNixieIncrementTime();

void openNixieTimeTick();

void openNixieDecrementTime();

void openNixieTimeResetSeconds();

char openNixieTimeGetMinutes();

char openNixieTimeGetHours();

char openNixieTimeGetSeconds();


#endif /* OPENNIXIETIME_H_ */