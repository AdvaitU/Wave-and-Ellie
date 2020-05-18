/************************************* MODE 3 *******************************************/

//ACTUALLY MODE 3!

/*
 * Toy turns one colour, then says a number. 
 * Child finds three objects of that colour and scans them.
 * Positive feedback.
 * Next.
 * 
 */

void mode3 () {

  while(1) {                                        //Can only be escaped using arduino reset button.
    music.play("mode3_start");
    int randomNum = random(0,4);                    //Randomised number between 0-4
    colourCode = random(0,9);                       //colour said 
    if (colourCode == prevColour) {
      colourCode = random(0,9);                     //Randomise again if colour repeated
    }
    prevColour = colourCode;                        //Save new colour as old colour
    flashRGB(colourCode);                           //colour flashed
    sayNumber(randomNum);                           //random number said - function written later
    int cnt = 0;                                    //count set to zero
    int inactive = 0;                               //Count of being inactive
    time_count = millis();                          //Save zero time

    while(1) {                                      //Second tier loop i.e. This round
      if (digitalRead(button) == HIGH){             //If button is pressed

        inactive = 0;                                //Pressing button shows toy is not inactive
        time_count = millis();                      //Resets timer  to zero
        
        
        if (getColour() == colourCode) {            //If colour is correct
          cnt = cnt + 1;                            //Count increased by 1.
          sayNumber(cnt);                           //Say number of count
        }
        else {
          music.play("tryagain.wav");               //"Let's Try Again!"
          delay(500);
        }  
      }

      if (cnt == randomNum) {                       //If count reaches random number said out by toy
        music.play("welldone.wav");                 //"Well done!"
        break;                                      //Break away from second tier loop. Game round over.
      }

      if ((millis() - time_count) == 30000){       //If 30 seconds pass
        inactive = inactive + 1;                   //Increase Inactive Count by 1, when it hits 6, bye bye.
        music.play("letstryanother.wav");          //"Let's Try Another!"
        break;                                     //Break away from second tier loop. Game round over.
      }
    }

    if (inactive == 6) {                           //If 5 minutes have passed
      music.play("byebye.wav");                    //"Bye Bye!"
      //Function for Switch off Here
    }

    delay(4000);                                    //delay of convenience
  }
 }

/****************************** SAY NUMBER FUNCTION *********************************/

void sayNumber (int randNum) {

  if (randNum == 1) {
    music.play("one.wav");
  }
  else if (randNum == 2) {
    music.play("two.wav");
  }
    else if (randNum == 3) {
    music.play("three.wav");
  }
    else if (randNum == 4) {
    music.play("four.wav");
  }
}

/***************************************************************************************/
