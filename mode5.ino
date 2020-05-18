/**************************** MODE 5 *******************************/
/*
 * Toy says name of colour.
 * Kid puts it on colour.
 * Positive feedback.
 * 
 */

 //REDUNDANT - DONT USE IN FINAL TOY

void mode5() {
  
  while(1) {
    
    music.play("mode5_start.wav"); 
    colourCode = random(0,9);                         //randomise colour
    sayColour(colourCode);                            //say that colour's name, function written below
    delay(1000);                                      //delay of convenience

    while(1) {
      if (getColour() == colourCode) {                 //if colour is matched
        music.play("positive_feedback.wav");          //audio feedback
        flashRGB(colourCode);                         //light up
        delay(1000);                                  //delay of convenience
        break;                                        //break
      }
    }
  }
}
