/************************ MODE 1 *******************************/

//ACTUALLY MODE 2

/*  Toy turns a randomised colour. music begins to play.
 *  Kid places toy on that colour before music stops.
 *  Toy gives positive feedback and says name of that colour.
 *  small delay.
 *  toy turns a different colour.
 *  
 *  OR
 *  
 *  Kid fails to place toy on colour before music stops.
 *  Negative feedback.
 *  Score announced and Game Over played out.
 */

void mode1(){                                              //Used as such: mode1();

    music.play("mode1.wav");                              //"Let's Play Go Find!"
    delay(1000);
    time_count = 0;                                       //time_count variable refreshed.
    int failcount = 0;                                    //If count reaches 6, toy switches off completely.
    
    while(1) {                                             //First Tier while(0 loop i.e. Mode 1
      colourCode = random(0,9);                            //Randomises Colour - Colour code saved in variable
      if (colourCode == prevColour) {                       //If randomised colour is same as the previous colour
        colourCode = random(0,9);                          //Randomise again
      }
      prevColour = colourCode;                             //Save newly randomised colour as previous colour for next round.
      flashRGB(colourCode);                                //toy turns randomised colour 
      delay(500);                                          //delay of convenience
      time_count = millis();                               //Save time song started at as point zero
      music.play("mode1_jingle.wav");                      //Start playing song
      
      while(1) {                                           //Second tier while() loop i.e. current game
        if (digitalRead(button) == HIGH) {                 //If button is pressed

          failcount = 0;                                   //Variable refreshed because of action
          
          if (getColour() == colourCode) {                 //If correct colour
           music.stopPlayback();                           //Stop jingle altogether
           delay(500);                                     //Delay of convenience
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
            music.play("mode1_jingle.wav",pauseTime);      //Play jingle starting at saved pause time
          }
          
         }
         
        else if ((millis() - time_count) >= 30000) {       //Else if 30 seconds have passed since song started
          music.stopPlayback();                            //Stop jingle
          music.play("letstryanothercolour.wav");          //"Let's Try Another Colour!"
          failcount = failcount + 1;                       //Increases count of failure by 1
          break;                                           //breaks second tier while() loop i.e. current game
          }
        }
      
      music.stopPlayback();                                //Instruction to stop jingle just in case.Jinngle is  expected to stop before this point  one way or another.
      delay(2000);                                         //delay of convenience.
      if (failcount == 6) {                                //If inaction 30 second thing happens 6 times, switch off the toy
        music.play("byebye.wav");                          //"Bye Bye!"
        //Function for Switch off Here
      }
      //from here, it goes back to start of game
      }
  }
