/*************************************************************************
File:         BMV31M304A.h
Author:       BEST MODULES CORP.
Description:  Define classes and required variables
History：  V1.0.1   -- 2025-03-28
**************************************************************************/
#ifndef _BMV31M304A_H
#define _BMV31M304A_H


#include <Arduino.h>
#include <Wire.h>
/*************************playback control command***************************************************************************************
 * Play voice                                00H~7FH ——> when the 0xfa command is used,00H:is voice 0； from 0 to 127;
                                                         when the 0xfa cammand is used ,00H:is voice 128;from 128 to 255.
 * Play sentence                             80H~DFH ——> 80H:is sentence 0；from 0 to 95, there are 96 sentences.
 * Volume selection                          E1H~ECH ——> E1H:is the minimum volume（mute）；There are 12 levels of volume adjustment.
 * Pause voice/sentence                      F1H     ——> Pause playing the current voice and sentence.
 * Play after pause                          F2H      ——> Continue playing the paused voice and sentence.
 * Loop playback the current voice/sentence  F4H      ——> Loop playback for the current voice and sentence.
 * Stop playing the current voice/sentence   F8H      ——> Stop playing the current voice and sentence.
**************************************************************************************************************************************/

#define BMV31M304_BUSY	 	 	    1
#define BMV31M304_NOBUSY     	  0

#define BMV31M304_VOLUME_MAX    11
#define BMV31M304_VOLUME_MIN	  0



#define I2C_SLAVE_ADDRESS 0x28


class BMV31M304A
{
public:
	BMV31M304A(uint8_t busyPin,TwoWire *theWire);
	void begin(void);
	void setVolume(uint8_t volume = 8);
	void playVoice(uint8_t num, bool loop=false);
	void playSentence(uint8_t num, bool loop=false);
	void playStop(void);
	void playPause(void);
	void playContinue(void);
	void playRepeat(void);
	bool isPlaying(void);
private:
  void I2C_writeByte(uint8_t data1,uint8_t data2);
  void I2C_writeByte(uint8_t data);
  uint8_t _busyPin;
  TwoWire *_theWire;
};
#endif
