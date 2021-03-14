/*
 * RC6HAL.h
 *
 * Created: 2020-10-14 23:21:27
 *  Author: Trojan
 */ 


#ifndef RC6HAL_H_
#define RC6HAL_H_

#include <stdbool.h>

#define IRDDR  DDRD
#define IRPORT PIND
#define IRPIN  PORTD3

void
RC6HALInit();

void
RC6HALDecoderStep();

unsigned int
RC6GetMicrosecondTimer();

bool
RCHAL6GetPinState();


#endif /* RC6HAL_H_ */