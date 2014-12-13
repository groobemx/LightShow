LightShow
=========

Control LED lights over Bluetooth LE and an Arduino controller.  Meant to be used with the Light Show iOS app.

Send the RGB color to the Arduino controller over Blutetooth LE.  The UART connection accepts 3 bytes at a time.  The first byte is the R color, the second byte is the G color, and the third byte is the B color.
