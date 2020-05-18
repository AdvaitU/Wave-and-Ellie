//TCS3200 pin wiring to Arduino

/*  TCS3200  -------->   Arduino (preferable Uno)
 *  S0       -------->   D1
 *  S1       -------->   D2
 *  S2       -------->   D6
 *  S3       -------->   D7
 *  OUT      -------->   D8
 *  VCC      -------->   5V
 *  OE       -------->   GND
 *  GND      -------->   GND
 */

//LM386N1 + Speaker pin wiring to Arduino

 /* LM386N1 --------> Arduino/Speaker
  * PIN 3   --------> D9(PWM)
  *         --------> 5V
  *         --------> GND
  *         --------> GND
  * LMPIN 1 --------> 10uF Capacitor --------> LMPIN8        
  * 
  */


//RGB Led connected to Arduino (common cathode) (tentative)

 /* RGB R        ------> D10(PWM)
  * RGB cathode  ------> GND
  * RGB G        ------> D11(PWM)
  * RGB B        ------> D3 (PWM)
  */

//Pushbutton (Pressure Plate) Connected to Arduino 

  /* 
   * Pushbutton +ve -------> 2.2kOhm resistor ------->. Arduino 5V
   * Pushbutton -ve -------> Arduino GND
   * Pushbutton pin -------> Arduino D0
   * 
   */

//Potentiometer connected to Arduino

   /*
    * Pot +ve -------> Arduino +5V
    * Pot -ve -------> Arduino GND 
    * Pot Mid -------> Arduino A0
    * 
    */
  
/********************************* PIN DEFINE ************************************/

#define S0 1                                //TCS3200 - Colour Sensor
#define S1 2
#define S2 6
#define S3 7
#define outPut 8

#define speakerPIN 9                        //LM386N1 + Speaker

#define redLed 10                           //RGB LED        
#define greenLed 5
#define blueLed 3

#define SD_ChipSelectPin 4                  //SD card reader Original library program uses pins 11, 12, 13 and 4 as chip select pin

#define button 0                            //Pushbutton on pin 0



/***************************** GLOBAL VARIABLES **********************************/

unsigned int frequency = 0;                 //TCS3200 - Colour Sensor
int rVal;
int gVal;
int bVal;
int colourNo;
int value;
bool valques;
int colourCode;
int mode;                                  //Variable that stores mode toy is in
int time_count;                            //for play mode
int prevColour = 9;                        //Saves previous colour so as to not repeat. Across all modes. Initialised as no colour.

//Note Names   = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };                  //Speaker output notes
int noteFreq[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 1369, 966 };          //Corresponding frequencies

int sequence[10] = {0,0,0,0,0,0,0,0,0,0};                                     //Sequence of notes
int previousSequence[10] = {0,0,0,0,0,0,0,0,0,0};                             //Previous sequence saved in new variable before recording another to play it on command

//Colour Names   = { Blue, Red, Yellow, Orange, Green, Magenta, Black, White, Cyan, Raspberry, Raspberry, Magenta };                  //Speaker output notes
int colourVal[12][3] = { {0,0,255} , {255,0,0}, {255,255,0}, {200,200,0}, {0,255,0}, {255,255,125}, {0,0,0}, {255,255,255}, {0,255,255}, {80, 0, 80}, {125,125,125}, {255,0,255}};          //Corresponding frequencies

/*RGB_color(255, 0, 0); // Red
  delay(1000);
  RGB_color(0, 255, 0); // Green
  delay(1000);
  RGB_color(0, 0, 255); // Blue
  delay(1000);
  RGB_color(255, 255, 125); // Raspberry
  delay(1000);
  RGB_color(0, 255, 255); // Cyan
  delay(1000);
  RGB_color(255, 0, 255); // Magenta
  delay(1000);
  RGB_color(255, 255, 0); // Yellow
  delay(1000);
  RGB_color(255, 255, 255); // White
  delay(1000);
  setColor(80, 0, 80);  // purple
  delay(1000);
  */

/**************************************************************************/


  
