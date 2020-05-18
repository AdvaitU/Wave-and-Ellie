/***************************** FINAL COLOUR FUNCTION *********************************/

int getColour() {

  int colourcode;                                 //use statement colourCode = getColour();
  detectColour();
  colourcode = defineColour(rVal,gVal,bVal);
  return colourcode;
  
}


/****************************** read RGB components **********************************/

void detectColour() 
{
  rVal = 0;                           //flush previous values of R, G, B
  gVal = 0;
  bVal = 0;
  int n = 10;
  for (int i = 0; i < n; ++i)
  {
    //read red component
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    rVal = rVal + pulseIn(outPut, LOW);
  
   //read green component
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    gVal = gVal + pulseIn(outPut, LOW);
    
   //read blue component
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    bVal = bVal + pulseIn(outPut, LOW);
  }
  rVal = rVal/n;
  gVal = gVal/n;
  bVal = bVal/n;
}



/********************** Assign Colour name codes based on values ****************************/


int defineColour (int rVal, int gVal, int bVal) {
  
  if ( range(56,70,36,50,16,30) || range(80,100,70,105,40,65) || proportions(rVal,gVal,bVal) ) {   //r>g>b
    value = 1;
  }

  else if(range(13,20,40,50,30,40) || range(25,40,70,100,50,75) || proportions(gVal,bVal,rVal) ) {  //g>b>r
    value = 2;
  }

    else if ( range(9,15,11,16,20,30) && proportions(bVal,gVal,rVal) ) { //b>g>r
    value = 3;
  }

    else if ((range(7,16,25,39,25,35) || range(35,50, 65, 75, 50, 60)) && proportions(bVal,gVal,rVal) ) {  //b>g>r
    value = 4;
  }

    else if (range(37,45,26,35,30,40) || proportions(rVal,bVal,gVal) ) { //r>b>g
    value = 5;
  }

    else if (range(46,55,30,40,16,21)  ) {        
    value = 6;
  }

    else if (range(69,80,70,85,55,66) && proportions(gVal,rVal,bVal) ) {  //g>r>b  
    value = 7;
  }

    else if (range(8,15,8,15,6,11) && proportions (gVal,rVal,bVal)) {  //g>r>b
    value = 8;
  }
  else {
    value = 9;
  }

  return value;

}

/*********************************** RANGE FUNCTION *****************************************************/

bool range (int a, int b, int c, int d, int e, int f){
  
  if ( ((rVal >= a) && (rVal <= b)) && ((gVal >= c) && (gVal <= d)) && ((bVal >= e) && (bVal <= f)) ){
    valques = true;
  }
  else {
    valques = false;
  }

  return valques;
}

/********************************************************************************************************/

/****************************** Print Colour Name based on assigned colour Code ***************************/

void printColour(int colourNo) {

  if (colourNo == 1) {
    Serial.print("BLUE");
  }

  else if (colourNo == 2) {
    Serial.print("RED");
  }

  else if (colourNo == 3) {
    Serial.print("YELLOW");
  }

  else if (colourNo == 4) {
    Serial.print("ORANGE");
  }

  else if (colourNo == 5) {
    Serial.print("GREEN");
  }

  else if (colourNo == 6) {
    Serial.print("VIOLET");
  }

  else if (colourNo == 7) {
    Serial.print("BLACK");
  }

  else if (colourNo == 8) {
    Serial.print("WHITE");
  }
  
  else {
    Serial.print("CAN'T READ");
  }

}

/***************************     PRINT RGB VALUES (OPTIONAL FUNCTION)    *********************************/

void printRGBvalues(int rVal, int gVal, int bVal) {
  
  Serial.print(" (R = ");
  Serial.print(rVal);
  Serial.print(" ");

  Serial.print(" G = ");     
  Serial.print(gVal);
  Serial.print(" ");

  Serial.print(" B = ");
  Serial.print(bVal);
  Serial.print("  )");  

}

/***********************************************************************************************************/

bool proportions(int a, int b, int c) {
  if ((a>b) && (b>c)) {
    return true;
  }
  else {
    return false;
  }
}

/***********************************************************************************************************/
