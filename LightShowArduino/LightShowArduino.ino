/*********************************************************************

This arduino sketch was modified by Kitefaster, LLC for use with the Light Show iOS app.

Download Light Show at https://itunes.apple.com/us/app/light-show-control-your-arduinos/id955092313?mt=8

/*********************************************************************
This is an example for our nRF8001 Bluetooth Low Energy Breakout

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/1697

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Kevin Townsend/KTOWN  for Adafruit Industries.
MIT license, check LICENSE for more information
All text above, and the splash screen below must be included in any redistribution
*********************************************************************/

// This version uses call-backs on the event and RX so there's no data handling in the main loop!

#include <SPI.h>
#include "Adafruit_BLE_UART.h"

//Bluetooth
#define ADAFRUITBLE_REQ 10
#define ADAFRUITBLE_RDY 2
#define ADAFRUITBLE_RST 9

//LED Strip
#define RED      3
#define GREEN    5
#define BLUE     6

int rgb[3];

Adafruit_BLE_UART uart = Adafruit_BLE_UART(ADAFRUITBLE_REQ, ADAFRUITBLE_RDY, ADAFRUITBLE_RST);

/**************************************************************************/
/*!
    This function is called whenever select ACI events happen
*/
/**************************************************************************/
void aciCallback(aci_evt_opcode_t event)
{
  switch(event)
  {
    case ACI_EVT_DEVICE_STARTED:
      Serial.println(F("Advertising started"));
      break;
    case ACI_EVT_CONNECTED:
      Serial.println(F("Connected!"));
      break;
    case ACI_EVT_DISCONNECTED:
      Serial.println(F("Disconnected or advertising timed out"));
      break;
    default:
      break;
  }
}

/**************************************************************************/
/*!
    This function is called whenever data arrives on the RX channel
*/
/**************************************************************************/
void rxCallback(uint8_t *buffer, uint8_t len)
{
  Serial.print(F("Received "));
  Serial.print(len);
  Serial.println(F(" bytes: "));
  
  if(len == 3) {
    byte r = buffer[0];
    byte g = buffer[1];
    byte b = buffer[2]; 
    
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
    Serial.print("R: ");
    Serial.println(r);
    Serial.print("G: ");
    Serial.println(g);
    Serial.print("B: ");
    Serial.println(b);
  } else {
    for(int i=0; i<len; i++) {
      Serial.print((char)buffer[i]);
    }
    Serial.print(F(" ["));
  
    for(int i=0; i<len; i++) {
      Serial.print(" 0x"); Serial.print((char)buffer[i], HEX); 
    }
    Serial.println(F(" ]"));
  }

  /* Echo the same data back! */
  //uart.write(buffer, len);
}

/**************************************************************************/
/*!
    Configure the Arduino and start advertising with the radio
*/
/**************************************************************************/
void setup(void)
{ 
  Serial.begin(9600);
  while(!Serial); // Leonardo/Micro should wait for serial init
  Serial.println(F("Adafruit Bluefruit Low Energy nRF8001 Callback Echo demo"));

  uart.setRXcallback(rxCallback);
  uart.setACIcallback(aciCallback);
  uart.setDeviceName("HSlight"); /* 7 characters max! */
  uart.begin();
  
  rgb[0] = 255;
  rgb[1] = 255;
  rgb[2] = 255;
}

/**************************************************************************/
/*!
    Constantly checks for new events on the nRF8001
*/
/**************************************************************************/
void loop()
{
  uart.pollACI();
  writeColor();
}

void writeColor() {
  analogWrite(RED, rgb[0]);            // red value in index 0 of rgb_colors array
  analogWrite(GREEN, rgb[1]);          // green value in index 1 of rgb_colors array
  analogWrite(BLUE, rgb[2]);           // blue value in index 2 of rgb_colors array
}
