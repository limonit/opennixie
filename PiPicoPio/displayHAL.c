/*
 * displayHAL.c
 *
 * Created: 2020-06-15 23:51:05
 *  Author: Trojan
 */ 

#include "displayHAL.h"
//#include "main.h"

#include "hardware/pio.h"

#include <string.h>

unsigned char displayContent[4] = {10, 10, 10, 10};
unsigned char displayContent2[4] = {10, 10, 10, 10};

extern PIO pio;
extern uint sm;

void inline displayHALputData(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    static const uint8_t lookUpTableLocal[11] = {1, 3, 11, 10, 2, 4, 12, 0, 8, 9, 15};
    uint32_t display_data;

    display_data = ((lookUpTableLocal[a] << 4) + (1 << 0));
    display_data += ((lookUpTableLocal[b]  << 4) + (1 << 1)) << 8;
    display_data += ((lookUpTableLocal[c]  << 4) + (1 << 2)) << 16;
    display_data += ((lookUpTableLocal[d]  << 4) + (1 << 3)) << 24;

    pio_sm_put(pio, sm, display_data);
}
