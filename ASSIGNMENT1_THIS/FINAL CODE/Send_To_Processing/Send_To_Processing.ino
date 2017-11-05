/*
 Laura Hirsh
 
 To read multiple sensor values as a string in processing. 
 
 This is an altered example code from the public domain.
 This program sends an ASCII A (byte of value 65) on startup
 and repeats that until it gets some data in.
 Then it waits for a byte in the serial port, and
 sends three sensor values whenever it gets a byte in.

 The values must be mapped to the average detected pressure
 (usually between 700 and 1000) to values between 1 and 25 to 
 be read in processing. 
 
 http://www.arduino.cc/en/Tutorial/SerialCallResponse
 */
int firstSensor = 0; // first analog sensor
int secondSensor = 0; // second analog sensor
int thirdSensor = 0; // digital sensor
int inByte = 0;   // incoming serial byte
void setup()
{
 // start serial port at 9600 bps:
 Serial.begin(9600);
 pinMode(2, INPUT); // digital sensor is on digital pin 2
 establishContact(); // send a byte to establish contact until receiver
      // responds
}
void loop()
{
 // if we get a valid byte, read analog ins:
 if (Serial.available() > 0) {
 // get incoming byte:
 inByte = Serial.read();
 
 
 // read first analog input, map to make the range 1-25:
 firstSensor = analogRead(A0); //First sensor is A0
 if (firstSensor >= 1008) { //This value is the average value being read 
   firstSensor = map(firstSensor, 1008, 1023, 1, 25);
}
  else if (firstSensor < 1008) { //to set any value lower to a pixel size of one
       firstSensor = map(firstSensor, 0, 1008, 1, 1);  
  } 
  
 // delay 10ms to let the ADC recover:
 delay(10);
 // read second analog input, map to make the range 0-50:
 secondSensor = analogRead(A1); //second sensor is A1
 
  if (secondSensor >= 838) { //This value is the average value being read 
   secondSensor = map(secondSensor, 838, 1023, 1, 50);
}
  else if (secondSensor < 838) { //to set any value lower to a pixel size of one
       secondSensor = map(secondSensor, 0, 838, 1, 1);  
  } 
  
 // read sensor, map it to 0 or 1
 thirdSensor = analogRead(A2); //second sensor is A1
 if (thirdSensor >= 0 && thirdSensor <= 480 )
  {
    thirdSensor = 0;
  }
  else if (thirdSensor > 480) 
  {
    thirdSensor = 1;
  }
 
 // send sensor values:
 Serial.write(firstSensor);
 Serial.write(secondSensor);
 Serial.write(thirdSensor);
 }
}
void establishContact() {
 while (Serial.available() <= 0) {
 Serial.print('A'); // send a capital A
 delay(300);
 }
}
