/*
 * ledHAL.h
 *
 * Created: 2020-09-14 20:43:15
 *  Author: Trojan
 */ 
#ifndef LEDHAL_H_
#define LEDHAL_H_

#include <avr/io.h>
#include <stdbool.h>

#define LEDDDR  DDRD
#define LEDPORT PORTD
#define LEDPIN  PORTD5



void
ledHALinit();

void
ledHALon();

void
ledHALoff();

void
ledHALswitch (bool state);

void
ledHALToggle();

#endif /* LEDHAL_H_ */