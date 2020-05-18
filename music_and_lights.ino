/*************************** LED function ******************************/

void ledFlash (int count) {
  
  for(int i=0; i <= count; i++) {
    digitalWrite(ledArray, HIGH);
    delay(200);
    digitalWrite(ledArray, LOW);
    delay(200);
  }
}

/*************************** English Names Function ****************************/

void englishNames(int colourcode) {         //Used as such: englishNames(colourCode);

  if (colourcode == 1) {
    music.play("en_bl");
  }
  else if (colourcode == 2) {
    music.play("en_rd");
  }
  else if (colourcode == 3) {
    music.play("en_yl");
  }
  else if (colourcode == 4) {
    music.play("en_or");
  }
  else if (colourcode == 5) {
    music.play("en_gr");
  }
  else if (colourcode == 6) {
    music.play("en_vl");
  }
  else if (colourcode == 7) {
    music.play("en_bk");
  }
  else if (colourcode == 8) {
    music.play("en_wh");
  }
  else {
    
  }
    
}

/*************************** French Names Function ****************************/

void frenchNames(int colourcode) {         //Used as such: frenchNames(colourCode);

  if (colourcode == 1) {
    music.play("fr_bl");
  }
  else if (colourcode == 2) {
    music.play("fr_rd");
  }
  else if (colourcode == 3) {
    music.play("fr_yl");
  }
  else if (colourcode == 4) {
    music.play("fr_or");
  }
  else if (colourcode == 5) {
    music.play("fr_gr");
  }
  else if (colourcode == 6) {
    music.play("fr_vl");
  }
  else if (colourcode == 7) {
    music.play("fr_bk");
  }
  else if (colourcode == 8) {
    music.play("fr_wh");
  }
  else {
    
  }
    
}

/*************************** German Names Function ****************************/

void germanNames(int colourcode) {         //Used as such: germanNames(colourCode);

  if (colourcode == 1) {
    music.play("gr_bl");
  }
  else if (colourcode == 2) {
    music.play("gr_rd");
  }
  else if (colourcode == 3) {
    music.play("gr_yl");
  }
  else if (colourcode == 4) {
    music.play("gr_or");
  }
  else if (colourcode == 5) {
    music.play("gr_gr");
  }
  else if (colourcode == 6) {
    music.play("gr_vl");
  }
  else if (colourcode == 7) {
    music.play("gr_bk");
  }
  else if (colourcode == 8) {
    music.play("gr_wh");
  }
  else {
    
  }
    
}
