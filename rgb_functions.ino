/*********************** Flash RGB values function *******************/

int flashRGB (int colourcode) {           //Used as such: flashRGB(colourCode);

  if (colourcode == 1) {
    rgb(0,0,255);
  }
  else if(colourcode == 2) {              //Fix these accurately later
    rgb(255,0,0);
  }
  else if(colourcode == 3) {
    rgb(255,200,0);
  }
  else if(colourcode == 4) {
    rgb(255,75,0);
  }
  else if(colourcode == 5) {
    rgb(0,255,0);
  }
  else if(colourcode == 6) {
    rgb(255,0,255);
  }
  else if(colourcode == 7) {
    rgb(0,0,0);
  }
  else if(colourcode == 8) {
    rgb(255,255,255);
  }
  else if(colourcode == 9) {
    rgb(0,0,0);
  }
  
}

/*********************** RGB Function ***************************/

//Not used in final program

void rgb(int r, int g, int b) {
  
  analogWrite(redLed,r);                //used within function flashRGB
  analogWrite(greenLed,g);              //rgb() only automates final function of switching on three anode coloured LEDs
  analogWrite(blueLed,b); 
  /*  delay(2000);
      analogWrite(redLed,0);
      analogWrite(greenLed,0);
      analogWrite(blueLed,0);   */
}

/*************************************************************************/
