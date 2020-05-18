/********************************* MODE 4 ***********************************/
/*
 * Toy flashes sequence of 3 colours in a row.
 * Child places it on those three colours on by one.
 * Positive feedback after each correct one.
 * Negative feedback and reset after 30 seconds.
 * 
 */

void mode4 () {
  
  music.play("mode4.wav");
  while(1) {                                       //First tier while loop i.e. Game Mode

    int seq1 = random(0,9);                        //Randomise 3 numbers
    int seq2 = random(0,9);
    int seq3 = random(0,9);

    while(1) {                                     //Loop breaks only if all three colours are different
      if ((seq2 == seq3) || (seq2 == seq1)) {      //make sure they don't repeat
        seq2 = random(0,9);
      }
      if (seq1 == seq3) {
        seq3 = random(0,9);
      }
      else {
        break;
      }
    }

    flashRGB(seq1);           //FLASH CYCLE    
    delay(5000);              //Keep on for 5 seconds
    flashRGB(9);              //OFF

    delay(2000);              //No colour for 2 seconds

    flashRGB(seq2);           
    delay(5000);              //Keep on for 5 seconds
    flashRGB(9);              //OFF

    delay(2000);              //No colour for 2 seconds

    flashRGB(seq3);       
    delay(5000);              //Keep on for 5 seconds
    flashRGB(9);              //OFF

    delay(2000);              //Delay of convenience
    time_count = millis();   //Initial zero


    while(1){                                                                  //Second tier loop - Round of game.

      if (digitalRead(button) == HIGH){                                               //If button is pressed
       time_count = millis();
       if(getColour() == seq1) {                                         //If colour is correct
         music.play("positivefeeback.wav");                                    //Give positive feedback
         flashRGB(seq1);                                                       //Showcolour
         delay(2000);                                                          //Nothing for two seconds
         while(1) {                                                            //Thired tier
             if (digitalRead(button) == HIGH){                                               //If button is pressed
                 time_count = millis();
                 if(getColour() == seq2) {                                         //If colour is correct
                   music.play("positivefeeback.wav");                                    //Give positive feedback
                   flashRGB(seq2);                                                       //Showcolour
                   delay(2000);                                                          //Nothing for two seconds
                   while(1) {                                                            //Fourth tier
                         if (digitalRead(button) == HIGH){                                               //If button is pressed
                           time_count = millis();
                           if(getColour() == seq3) {                                         //If colour is correct
                             music.play("positivefeeback.wav");                                    //Give positive feedback
                             flashRGB(seq3);                                                       //Showcolour
                             delay(2000);                                                          //Nothing for two seconds
                             break;                                                                //Break tier four
                           }
                           else {                                                                   //If colour is wrong
                             music.play("negativefeedback.wav");                                    //Negative feedback
                           }
                          }
                          if ((millis() - time_count) >= 30000) {                                  //If 30 seconds of inaction
                             music.play("letstryagain.wav");                                       //"Let's Try Again!'
                             break;                                                                //Break tier four
                          }
                   }
                   break;                                                                //Break tier three
                 }
                 else {                                                                   //If colour is wrong
                   music.play("negativefeedback.wav");                                    //Negative feedback
                 }
                }
                if ((millis() - time_count) >= 30000) {                                  //If 30 seconds of inaction
                   music.play("letstryagain.wav");                                       //"Let's Try Again!'
                   break;                                                                //Break tier three
                 }
         }
         break;                                                                //Break tier two
       }
       else {                                                                   //If colour is wrong
         music.play("negativefeedback.wav");                                    //Negative feedback
       }
      }
      if ((millis() - time_count) >= 30000) {                                  //If 30 seconds of inaction
         music.play("letstryagain.wav");                                       //"Let's Try Again!'
         break;                                                                //Break tier two
       }
      
    } 
      
 }
}
