/* 
Laura Hirsh

Simple sensor value testing sketch. 
 
 */
 
int sensorPin = 2;     // the pin the sensor is connected to
int sensorReading;     // the reading from the sensor
 
void setup(void) {
  // Sending information via the Serial monitor
  Serial.begin(9600);   
}
 
void loop(void) {
  sensorReading = analogRead(sensorPin); //sensor reading will be an analog read of set sensor pin
 /*if (sensorReading >= 0 && sensorReading <= 435 )
  {
    sensorReading = 0;
  }
  else if (sensorReading > 435) 
  {
    sensorReading = 1;
  }*/
 
  Serial.print("Value reading = "); 
  Serial.println(sensorReading);     // the raw reading
 
  delay(500); //display every second
} 
