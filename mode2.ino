/********************** MODE 2 *********************************/

//ACTUALLY MODE 5

/*  Toy says name of an object i.e sky, apple, banana, fire, leaf, violet, crow, snow, etc. 
 *  Child places object on toy
 *  positive feedback
 *  toy turns that colour for 5 seconds
 *  names next colour
 */

void mode2() {
    
    music.play("mode2.wav");                              //"Let's Play - What Colour Is It?!"
    delay(1000);
    time_count = 0;                                       //time_count variable refreshed.
    int failcount = 0;                                    //If count reaches 6, toy switches off completely.
    
    while(1) {                                             //First Tier while(0 loop i.e. Mode 1
      colourCode = random(0,9);                            //Randomises Colour - Colour code saved in variable
      sayObject(colourCode);                               //Says random object of THAT colour
      delay(500);                                          //delay of convenience
      time_count = millis();                               //Save time song started at as point zero
      music.play("mode2_jingle.wav");                      //Start playing song
      
      while(1) {                                           //Second tier while() loop i.e. current game
        if (digitalRead(button) == HIGH) {                 //If button is pressed

          failcount = 0;                                   //Variable refreshed because of action
          
          if (getColour() == colourCode) {                  //If correct colour
            music.stopPlayback();                           //Stop jingle altogether
            delay(500);                                     //Delay of convenience
            flashRGB(colourCode);                           //Toy turns that colour
            music.play("thatscorrect.wav");                 //"That's Correct!"
            delay(5000);                                    //Toy stays colour for 5 seconds
            flashRGB(9);                                    //No colour
            break;                                          //breaks second tier while() loop i.e. current game
          }

          else {
            int pauseTime = (millis() - time_count);       //Save time paused at as current time - time when jingle started. Hence pure number of seconds will be saved.
            music.pause();                                 //Pause music at point
            delay(500);                                    //Delay of convenience
            music.play("tryagain.wav");                    //"Let's Try Again!"                
            delay(1000);                                   //Time to register wrong
            music.play("mode2_jingle.wav",pauseTime);      //Play jingle starting at saved pause time
          }
          
         }
         
        else if ((millis() - time_count) >= 30000) {       //Else if 30 seconds have passed since song started
          music.stopPlayback();                            //Stop jingle
          music.play("letstryanotherobject.wav");          //"Let's Try Another Object!"
          failcount = failcount + 1;                      //Increases count of failure by 1
          break;                                           //breaks second tier while() loop i.e. current game
          }
        }
      
      music.stopPlayback();                                //Instruction to stop jingle just in case.Jinngle is  expected to stop before this point  one way or another.
      if (failcount == 6) {                                //If inaction 30 second thing happens 6 times, switch off the toy
        music.play("byebye.wav");                          //"Bye Bye!"
        //Function for Switch off Here
      }
      //from here, it goes back to start of game
      }
}


/****************************** sayObject Function **************************************/

void sayObject (int ObjectCode) {

  if (ObjectCode == 1) {
    music.play("sky.wav");                                   //Add 3-5 different objects and statement for randomisation her, so that it doesn't mess with main programme.    
  }
  else if (ObjectCode == 2) {
    music.play("apple.wav");
  }
    else if (ObjectCode == 3) {
    music.play("banana.wav");
  }
    else if (ObjectCode == 4) {
    music.play("fire.wav");
  }
    else if (ObjectCode == 5) {
    music.play("leaf.wav");
  }
    else if (ObjectCode == 6) {
    music.play("violet.wav");
  }
    else if (ObjectCode == 7) {
    music.play("crow.wav");
  }
    else if (ObjectCode == 8) {
    music.play("snow.wav");
  }
}

/***********************************************************************************/
