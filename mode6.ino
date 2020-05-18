/************************* MODE 6 Simplest Mode *****************************/

//ACTUALLY MODE 1

/*
 * Object is placed on something.
 * Toy says name of colour detected.
 * Toy turns that colour.
 * 
 */

void mode6() {

  music.play("mode6.wav");               //"Let's Learn Colours!"
  delay(2000);
  music.play("imready.wav");             //"I'm Ready!"
  
  while(1) {
   
   if (digitalRead(button) == HIGH) {
    colourCode = getColour();
    flashRGB(colourCode);                //Flash that Colour
    sayColour(colourCode);               //Says name of Colour
    delay(3000);                         //delay of convenience
    flashRGB(9);                         //Switch off colour
   }

  if (millis() - time_count == 300000)  {                  //If 5 minutes pass
        music.play("byebye.wav");                          //"Bye Bye!"
        //Function for Switch off Here    
  }
    
  } 
}

/******************************************************************************/

/*********************************** sayColour Function *************************************/

void sayColour (int colourcode) {

  if (colourcode == 1) {
    music.play("en_bl.wav");
  }
  else if (colourcode == 2) {
    music.play("en_rd.wav");
  }
  else if (colourcode == 3) {
    music.play("en_yl.wav");
  }
  else if (colourcode == 4) {
    music.play("en_or.wav");
  }
  else if (colourcode == 5) {
    music.play("en_gr.wav");
  }
  else if (colourcode == 6) {
    music.play("en_vl.wav");
  }
  else if (colourcode == 7) {
    music.play("en_bk.wav");
  }
  else if (colourcode == 8) {
    music.play("en_wh.wav");
  }
  else {
  }       
}

/**************************************************************************************/
