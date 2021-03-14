/**
 * @file RC6.h
 * @author Lukasz Trojanowski
 *
 * @brief RC6 remote type receiver library
 * @date 2018
 * 
 * Library provides hardware independent decoding procedure for RC6 remote signal.
 * Application has to provide HAL for library, including:
 * - free running timer with frequency 1MHz and at least 16-bit resolution
 * - state of pin that hardware receiver is connected. Signal on pin must have carrier signal filtered.
 * - signal when input pin has changed state.
 */ 

#ifndef RC6_H_
#define RC6_H_
#include <stdbool.h>

typedef struct RC6Decoder_* RC6Decoder; 

/** @fn RC6Decoder RC6DecoderCreate(void (*RC6Callback)(RC6Decoder self), bool (*RC6GetPinState)(void), unsigned int(*RC6GetMicrosecondTimer)(void), bool locksBuffer);
*   @brief Function creates RC6Decoder object.
*
*   The function allocates and returns object of decoder. Object should be freed when it is not longer needed.
*
*   @param[in] void (*RC6Callback)(RC6Decoder self) - reference to function that decoder object calls on succesful receiving of RC6 frame.
*   @param[in] bool (*RC6GetPinState)(void) - reference to function that decoder calls to check level on input in. True for high level, false for low level.
*   @param[in] unsigned int(*RC6GetMicrosecondTimer)(void) - reference to function that returns value of free running timer with frequency of 1kHz. Timer resolution must be not lower than 16 bits.
*   @param[in] bool locksBuffer - true value configures decoder for locking buffer when frame is received. Locking guarantees no write is performed before calling RC6DecoderUnlock function.
*                                 Any frame sent when buffer is locked will be ignored.
*   @returns - reference to created decoder object
*/ 
RC6Decoder RC6DecoderCreate(void (*RC6Callback)(RC6Decoder self), bool (*RC6GetPinState)(void), unsigned int(*RC6GetMicrosecondTimer)(void), bool locksBuffer);

/** @fn void RC6DecoderOnPinChange(RC6Decoder self);
*   @brief Function that is called when state on input pin changed.
*          Function calls callback on successful receiving of frame. Can be called in interrupt subroutine
           if callback function is interrupt subroutine safe.
*   @param[in] RC6Decoder self - reference to decoder
*/
void RC6DecoderOnPinChange(RC6Decoder self);

/** @fn unsigned char RC6DecoderGetControl(RC6Decoder self);
*   @brief Function returns value of control field in last received frame.
*
*   @param[in] RC6Decoder self - reference to decoder
*   @returns - value of control field in last received frame.
*/
unsigned char RC6DecoderGetControl (RC6Decoder self);

/** @fn unsigned char RC6DecoderGetCommand(RC6Decoder self);
*   @brief Function returns value of command field in last received frame.
*
*   @param[in] RC6Decoder self - reference to decoder
*   @returns - value of command field in last received frame.
*/
unsigned char RC6DecoderGetCommand (RC6Decoder self);

/** @fn bool RC6DecoderIsRepeated(RC6Decoder self);
*   @brief Function returns true if frame was sent by continuously pressed key.
*          False when key was released and pressed again. 
*
*   @param[in] RC6Decoder self - reference to decoder
*   @returns - Function returns true if frame was sent by continuously pressed key.
*/
unsigned char RC6DecoderIsRepeated (RC6Decoder self);

/** @fn void RC6DecoderUnlock(RC6Decoder self);
*   @brief Function unlocks buffer of decoder. When locksBuffer was set false upon
*          creating decoder calling this function has no effect.
*
*   @param[in] RC6Decoder self - reference to decoder
*/
void RC6DecoderUnlock(RC6Decoder self);

#endif /* RC6_H_ */