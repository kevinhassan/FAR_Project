/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with the Wiring / Arduino program that follows below.
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
String myString = null;
int lf = 10;    // Linefeed in ASCII

import processing.net.*;
Client c;
String data = null;
String request = null;

void setup() 
{
  size(200, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 115200);
  myPort.clear();
  myString = myPort.readStringUntil(lf);
  myString = null;
  }

void draw() {
  while (myPort.available() > 0) {
    myString = myPort.readStringUntil(lf);
    c = new Client(this, "127.0.0.1", 8050); // Connect to server on port 80
    if (myString != null) {
      println(myString);
      request="GET / HTTP/1.1 ";
      request += myString;
      request += "\r\n\r\n";
      c.write(request);
    }
  }
}