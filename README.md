LightShow
=========

This Arduino sketch can be used to control LEDs over Bluetooth LE.  It is designed to be used with the [LightShow](https://itunes.apple.com/us/app/light-show-control-your-arduinos/id955092313?mt=8) iOS app.


Common Cathode RGB LED and nRF8001 BLE
-----------
Follow these [instructions](http://www.instructables.com/id/Control-LED-light-color-via-an-Arduino-and-an-iPho/) to connect a single RGB LED and a Bluetooth low energy board to an Arduino Uno.


Analog RGB LED strips
-----------
Follow these [instructions](http://www.instructables.com/id/Control-a-LED-light-strips-color-via-an-Arduino-an/) to connect an analog RGB LED strip and a Bluetooth low energy board to an Arduino controller.


LightShow iOS App
-----------
Place the Adafruit_BLE_UART folder from this repository inside your Arduino libraries folder and restart the Arduino IDE.

Upload the LightShowArduino.ino sketch to your Arduino.

Install the [LightShow](https://itunes.apple.com/us/app/light-show-control-your-arduinos/id955092313?mt=8) app onto your iOS device.
