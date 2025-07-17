/******************************************************************
File:             voicePlayback.ino
Description:      Audio source Playback
Note:             
******************************************************************/
#include "BMV31M304A.h"

BMV31M304A myBMV31(22,&Wire1);

#define DEFAULT_VOLUME 11
void setup() {
  delay(1000); 
  myBMV31.begin();//Initialize 
  
  myBMV31.setVolume(DEFAULT_VOLUME);//Initialize the default volume
   
  myBMV31.playVoice(0);   
}

void loop() {

}
