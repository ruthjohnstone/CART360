/*** Ruth Johnstone ***/

/***************************************************************************************** 
 *  We are able to make varying audible sounds through one pin using a resistor ladder. 
 *  The resistor ladder consists of several resistors connected in series. 
 *  When resistors are connected in series their values are additive (Rtotal = R1 + R2 + …). 
 *  For example, consider we have 5 buttons connected though a series of 100Ohm resistors. 
 *  When the first button is pressed, the current will flow through the button and straight 
 *  into the pin, providing negligible resistance. However, when the last button is pressed, 
 *  the current flows through 4 resistors and would provide 400Ohms. 
 *  As the resistance varies depending on what button is pressed, the voltage also changes 
 *  according to Ohm’s Law: V=IR. We then assign the voltage read from the analog input pin 
 *  at A0 to the frequency of the tone using the tone(x,y,z) function.
 *  
 * The mode is selected by counting how many times the dedicated mode button at pin 2 has been pressed. 
 * I have used an if statement to increase the mode number by 1 each time the button is pressed, 
 * and used another if statement to make sure this only occurs when mode is less than 4, 
 * otherwise the mode will be set back to 0 to allow the users to reset the recorded array and start again.  
 * 
 *****************************************************************************************/

/**** CONSTANTS ********************************************************/

#define BUTTON_MODE_PIN 2 // Button to change the mode
int val = 0; // to store current button state
int valStateChange = 0; // to store prev button state

// constants for RGB LED
#define LED_PIN_R 9 // R PIN
#define LED_PIN_G 6 // G PIN
#define LED_PIN_B 5 // B PIN

// constant for note in (button-resistor ladder on breadboard)
# define NOTE_IN_PIN A0

// to store the previous value of the analog input in order to detect a state change
int prevAnalog = 0; 
 
//constant for max number of notes in array
#define MAX_NOTES 16

// a constant for duration
const int duration =200;

// constant for pin to output for buzzer 
#define BUZZER_PIN 3 // PWM

/******** VARIABLES *****************************************************/
// counter for how many notes we have
int countNotes = 0;
// array to hold the notes played (for record/play mode)
int notes [MAX_NOTES]; 
int mode = 0; // start at off

/*************************************************************************/

/**********************SETUP() DO NOT CHANGE*******************************/
// Declare pin mode for the single digital input
void setup()
{
  pinMode(BUTTON_MODE_PIN, INPUT);
}

/**********************LOOP() DO NOT CHANGE *****************************/
void loop()
{
  chooseMode();
  setRGB();
  selectMode();
}

/******************CHOOSEMODE(): IMPLEMENT ******************************/

void chooseMode(){
  
  val = digitalRead(BUTTON_MODE_PIN); // take the value for the mode button

  if (val != valStateChange) {       // this only runs the code if the button has been purposefully pressed
    
    if (val == HIGH) {
      if (mode < 4){
        mode = mode + 1;    // mode increases by one if the button is pressed
        }
      else{
          mode = 0;   // mode goes back to zero after user presses out of the loopMode
      }
    }
    
    // Delay a little bit to avoid bouncing
    delay(50);
  }

/* assigns the value of the current state to the valStateChange so that it can be determined if 
 *  different state from the previous in the next loop */
valStateChange = val;   
  
}

/******************SETRGB(): IMPLEMENT ********************************/
void setRGB()
{
  //IMPLEMENT
  pinMode(LED_PIN_R, OUTPUT);   // assigns all RGB pins as outputs
  pinMode(LED_PIN_G, OUTPUT);
  pinMode(LED_PIN_B, OUTPUT);
  
  switch (mode) {
    case 0:
      analogWrite(LED_PIN_R, 0);
      analogWrite(LED_PIN_G, 0);
      analogWrite(LED_PIN_B, 0);
    break;
    case 1:
      analogWrite(LED_PIN_R, 0);
      analogWrite(LED_PIN_G, 0);
      analogWrite(LED_PIN_B, 255);    // set blue pin to maximum
    break;
    case 2:
      analogWrite(LED_PIN_R, 255);    // red pin as maximum
      analogWrite(LED_PIN_G, 0);
      analogWrite(LED_PIN_B, 0);
    break;
    case 3:
      analogWrite(LED_PIN_R, 0);
      analogWrite(LED_PIN_G, 255);    // green pin as maximum
      analogWrite(LED_PIN_B, 0);
    break;
    case 4:
      analogWrite(LED_PIN_R, 150);    // red pin as slightly less than max to get right shade of purple
      analogWrite(LED_PIN_G, 0);
      analogWrite(LED_PIN_B, 255);    // blue pin as max
    break;
  }
  
}

/**********************SELECTMODE() DO NOT CHANGE ******************************/
void selectMode()
{
  if(mode ==0) { 
    reset();
  }
  else if(mode ==1) {
    live();
  }
  else if(mode ==2) {
    record();
  }
  
  else if(mode ==3) {
    play();
  }
   
  else if(mode ==4) {
    loopMode();
  }
}

/******************RESET(): IMPLEMENT ************************************/
void reset()
{
  // IMPLEMENT
  for (int i = 0; i < MAX_NOTES; i++){      // set all array elements (up to MAX_NOTES) to 0.
    notes[i] = 0;
  }
  countNotes = 0;   // set countNotes to zero to start counting again on the next record function.
  
}

/******************LIVE(): IMPLEMENT *************************************/
void live()
{
    //IMPLEMENT

    if(analogRead(NOTE_IN_PIN) > 30){   // set 30 as the threshold for recognising input
      tone(BUZZER_PIN, analogRead(NOTE_IN_PIN), duration);    // assign incoming values from "note in pin" to the frequency of the tone
    } 
    else{
      noTone(BUZZER_PIN);
   } 
}

/******************RECORD(): IMPLEMENT *********************************/
void record()
{
  // IMPLEMENT
  //Serial.println(countNotes);
  if (countNotes < MAX_NOTES) {   // only run up to 16 notes.
    if(analogRead(NOTE_IN_PIN) > 30){
      if(prevAnalog < 50){    // only run if the button was just pressed
      tone(BUZZER_PIN,analogRead(NOTE_IN_PIN), duration);    
         
      notes[countNotes] = analogRead(NOTE_IN_PIN);    // store analog input for each element in the array  

      countNotes++;   // increase countNotes (number of element in array) by one each time this is run
      
      }
/*    assigns the current analog value to prevAnalog so that it can be determined in the next loop if 
 *  a new button press has been performed*/
      prevAnalog = analogRead(NOTE_IN_PIN);   
      
    } 
    
    else{
      noTone(BUZZER_PIN);
    }
  }
}

/******************PLAY(): IMPLEMENT ***********************************/
void play()
{
  // cycle through the stored array and play stored notes
  for (int i = 0; i < countNotes; i++){   
    if (digitalRead(BUTTON_MODE_PIN) != HIGH){    // check if the mode button is being pressed before playing the next note. 
      tone(BUZZER_PIN, notes[i], duration);
      delay(duration);
    }
  }
}

/******************LOOPMODE(): IMPLEMENT ********************************/
void loopMode()
{
  //IMPLEMENT
    if (digitalRead(BUTTON_MODE_PIN) != HIGH){
      tone(BUZZER_PIN, notes[random(1,15)], random(100,300));   // randomise the order of the stored notes and randomise the duration between 100 and 300ms 
      delay(random(10,100));    // randomise the delay between notes between 10 and 100.
    }
}

/**************************************************************************/
