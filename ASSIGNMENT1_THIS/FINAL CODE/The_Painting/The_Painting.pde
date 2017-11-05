/*
Laura Hirsh

This sketch uses arduino serial port input from three sensors to control the 
pixelation size of designated areas on a photo. 
*/

import processing.serial.*; //importing the mapped sensor values from the arduino

PImage img; //the image 
int w = 80; //a scale for constrains (don't touch)

PImage igtext; //the overlay image
boolean text = false; //a boolean to declare when overlay is present


Serial myPort;  // Create object from Serial class
int[] serialInArray = new int[3]; // Where we'll put what we receive
int serialCount = 0;     // A count of how many bytes we receive
boolean firstContact = false;  // Whether we've heard from the microcontroller 

int detailA; //sensor one pixel size
int detailB; //sensor two pixel size
int detailC; //sensor three



void setup() {
  size(566, 800); //size of image
  frameRate(30); //frame rate
  img = loadImage("nude.jpg"); //load the image
  igtext = loadImage("text.jpg"); //load the overlay

    //println(Serial.list());
  String portName = Serial.list()[3]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600); 
  
}

void draw() {
  
  // Only going to process portions of the image
  // So set the whole image as the background first
  image(img,0,0);
  // Set up the small rectangles to process
  
  //TIDDIES
  //Titties 1
  int axstart = constrain(240-w/2,0,img.width);
  int aystart = constrain(330-w/2,0,img.height);
  int axend = constrain(250+w/2,0,img.width);
  int ayend = constrain(310+w/2,0,img.height);
  
  //Titties 2
  int a2xstart = constrain(410-w/2,0,img.width);
  int a2ystart = constrain(520-w/2,0,img.height);
  int a2xend = constrain(400+w/2,0,img.width);
  int a2yend = constrain(500+w/2,0,img.height);
    
  //ASSES & GENITALS
  
  //Butts 1
  int bxstart = constrain(255-w/2,0,img.width);
  int bystart = constrain(435-w/2,0,img.height);
  int bxend = constrain(260+w/2,0,img.width);
  int byend = constrain(420+w/2,0,img.height);
  
  //Butts 2  
  int b2xstart = constrain(50-w/2,0,img.width);
  int b2ystart = constrain(560-w/2,0,img.height);
  int b2xend = constrain(140+w/2,0,img.width);
  int b2yend = constrain(560+w/2,0,img.height);
    
  //Butts 3
  int b3xstart = constrain(300-w/2,0,img.width);
  int b3ystart = constrain(130-w/2,0,img.height);
  int b3xend = constrain(260+w/2,0,img.width);
  int b3yend = constrain(80+w/2,0,img.height);  

  //Butts 4
  int b4xstart = constrain(460-w/2,0,img.width);
  int b4ystart = constrain(290-w/2,0,img.height);
  int b4xend = constrain(450+w/2,0,img.width);
  int b4yend = constrain(240+w/2,0,img.height);  

  //Butts 5
  int b5xstart = constrain(310-w/2,0,img.width);
  int b5ystart = constrain(730-w/2,0,img.height);
  int b5xend = constrain(270+w/2,0,img.width);
  int b5yend = constrain(680+w/2,0,img.height); 
  
  // Begin our loop for every pixel in first titties
  for (int x = axstart; x < axend; x+=detailA) {
    for (int y = aystart; y < ayend; y+=detailA) {
            
      if (detailA == 2) //to control slight fluctiation caused by mapping 
      {
        detailA = 1; //values of two sent from the arduino serial will be changed to 1
      }      

      // Each pixel location (x,y) gets passed into  
     color c= img.get(x,y); //a function to find the color of the pixel
     noStroke(); //no outline
     fill(c); //fill the newly sized pixel with the found color
     rect(x, y, detailA, detailA); //draw the newly sized pixel with size related to the serial value
   }
 }
 
  // Begin our loop for every pixel in second titties
  for (int x = a2xstart; x < a2xend; x+=detailA) {
    for (int y = a2ystart; y < a2yend; y+=detailA) {
         
      if (detailA == 2) //to control slight fluctiation caused by mapping 
      {
        detailA = 1; //values of two sent from the arduino serial will be changed to 1
      }

      // Each pixel location (x,y) gets passed into  
     color c= img.get(x,y); //a function to find the color of the pixel
     noStroke(); //no outline
     fill(c); //fill the newly sized pixel with the found color
     rect(x, y, detailA, detailA); //draw the newly sized pixel with size related to the serial value
   }
 }
 
  // Begin our loop for every pixel in first butts
  for (int x = bxstart; x < bxend; x+=detailB) {
        for (int y = bystart; y < byend; y+=detailB) {

       if (detailB == 2) //to control slight fluctiation caused by mapping 
      {
        detailB = 1; //values of two sent from the arduino serial will be changed to 1
      }         
     // Each pixel location (x,y) gets passed into  
     color c= img.get(x,y); //a function to find the color of the pixel
     noStroke(); //no outline
     fill(c); //fill the newly sized pixel with the found color
     rect(x, y, detailB, detailB); //draw the newly sized pixel with size related to the serial value
   }
 }
 
  // Begin our loop for every pixel in second butts
  for (int x = b2xstart; x < b2xend; x+=detailB) {
        for (int y = b2ystart; y < b2yend; y+=detailB) {

       if (detailB == 2) //to control slight fluctiation caused by mapping 
      {
        detailB = 1; //values of two sent from the arduino serial will be changed to 1
      }           
      // Each pixel location (x,y) gets passed into  
     color c= img.get(x,y); //a function to find the color of the pixel
     noStroke(); //no outline
     fill(c); //fill the newly sized pixel with the found color
     rect(x, y, detailB, detailB); //draw the newly sized pixel with size related to the serial value
   }
 }
 
 // Begin our loop for every pixel in third butts
  for (int x = b3xstart; x < b3xend; x+=detailB) {
        for (int y = b3ystart; y < b3yend; y+=detailB) {

       if (detailB == 2) //to control slight fluctiation caused by mapping 
      {
        detailB = 1; //values of two sent from the arduino serial will be changed to 1
      }           
      // Each pixel location (x,y) gets passed into  
     color c= img.get(x,y); //a function to find the color of the pixel
     noStroke(); //no outline
     fill(c); //fill the newly sized pixel with the found color
     rect(x, y, detailB, detailB); //draw the newly sized pixel with size related to the serial value
   }
 }
 
  // Begin our loop for every pixel in fourth butts
  for (int x = b4xstart; x < b4xend; x+=detailB) {
        for (int y = b4ystart; y < b4yend; y+=detailB) {

       if (detailB == 2) //to control slight fluctiation caused by mapping 
      {
        detailB = 1; //values of two sent from the arduino serial will be changed to 1
      }           
      // Each pixel location (x,y) gets passed into  
     color c= img.get(x,y); //a function to find the color of the pixel
     noStroke(); //no outline
     fill(c); //fill the newly sized pixel with the found color
     rect(x, y, detailB, detailB); //draw the newly sized pixel with size related to the serial value
   }
 }
 
   // Begin our loop for every pixel in fifth butts
  for (int x = b5xstart; x < b5xend; x+=detailB) {
        for (int y = b5ystart; y < b5yend; y+=detailB) {

       if (detailB == 2) //to control slight fluctiation caused by mapping 
      {
        detailB = 1; //values of two sent from the arduino serial will be changed to 1
      }           
      // Each pixel location (x,y) gets passed into  
     color c= img.get(x,y); //a function to find the color of the pixel
     noStroke(); //no outline
     fill(c); //fill the newly sized pixel with the found color
     rect(x, y, detailB, detailB); //draw the newly sized pixel with size related to the serial value
   }
 }

   if (detailC == 1) {  //if detail C is one
    text = true;        //turn on overlay
  } else {              //otherwise
    text = false;       //turn overlay off
  }
  
  if (text == true) {    //if overlay is on (1)
    image(igtext, 0, 0); //draw the overlay
  }
}

void serialEvent(Serial myPort) {
 // read a byte from the serial port:
 int inByte = myPort.read();
 // if this is the first byte received, and it's an A,
 // clear the serial buffer and note that you've
 // had first contact from the microcontroller.
 // Otherwise, add the incoming byte to the array:
 if (firstContact == false) {
 if (inByte == 'A') {
  myPort.clear();   // clear the serial port buffer
  firstContact = true;  // you've had first contact from the microcontroller
  myPort.write('A');  // ask for more
 }
 }
 else {
 // Add the latest byte from the serial port to array:
 serialInArray[serialCount] = inByte;
 serialCount++;
 // If we have 3 bytes:
 if (serialCount > 2 ) {
  detailA = serialInArray[0];
  detailB = serialInArray[1];
  detailC = serialInArray[2];
  // print the values:
  println(detailA + "t" + detailB + "t" + detailC);
  // Send a capital A to request new sensor readings:
  myPort.write('A');
  // Reset serialCount:
  serialCount = 0;
 }
 }
}