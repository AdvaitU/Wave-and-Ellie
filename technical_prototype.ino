#include <SD.h>                     // need to include the SD library
#include <TMRpcm.h>                 //TMRpcm  library for SD card courtesy https://github.com/TMRh20/TMRpcm
#include <SPI.h>                    //For standard protocol SPI communication with SD card reader, supports TCRpcm library
#include "pins_defined.h"

TMRpcm music;   // create an object for use in this sketch
unsigned long time = 0;

/************************************ MAIN SETUP FUNCTION *****************************************************/

void setup() {

  Serial.begin(9600);               //Serial Communication begins at 9600 baud
 
  pinMode(S0, OUTPUT);              //TCS3200 Colour Sensor
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(outPut, INPUT);

  digitalWrite(S0,HIGH);            //Setting TCS3200 defaults
  digitalWrite(S1,LOW);
  
  music.speakerPin = 9;             //speakerPIN replacement

  pinMode(redLed, OUTPUT);          //RGB LED
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT); 

  pinMode(button, INPUT);         //Main pushbutton

  if (!SD.begin(SD_ChipSelectPin)) {             // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;                                      // don't do anything more if not

  }
  else{   
    Serial.println("SD ok");   
  }
  
  //ledFlash(5);                      //Bootup feedback
  //music.play("bootup");              //Make file "bootup"

}

/************************************ MAIN LOOP FUNCTION *****************************************************/

void loop() {

  if(Serial.available()){    
    switch(Serial.read()){
      case '1': mode1(); break;         
      case '2': mode2(); break;
      case '3': mode3(); break;
      case '4': mode4(); break;    
    }
  }
/************************** case: mode 1 ************************************/

  /*if (mode == 4) {
    score = 0;                                          //set score  to  zero
    game_over = 0;                                      //Game is not over
    music.play("ready_ques");
    delay(1000);
    while(1) {
      playMode();            
      if (game_over == 1) {                              //If boolean value is saved as 'game is over'
        music.play(game_over);                           //Play game over sound
        break;
      }
    }
   }*/



/*  colourCode = getColour();
  printColour(colourCode);
  Serial.print("\n");
  printRGBvalues(rVal, gVal, bVal);
  Serial.print("\n");
  flashRGB(colourCode);
  englishNames(colourCode);
  delay(2000); */
}
