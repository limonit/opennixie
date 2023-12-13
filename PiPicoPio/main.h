#ifndef MAIN_H_
#define MAIN_H_

#include "hardware/pio.h"

char ssid[] = "";
char pass[] = "";

enum Mode {DISPLAY_TIME, SET_TIMEZONE};

int8_t timezone = 1;
PIO pio = pio0;
uint sm;

#endif
