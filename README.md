LightShow
=========

Control LED lights over Bluetooth LE and an Arduino controller.  Meant to be used with the Light Show iOS app.

Send the RGB color to the Arduino controller over Bluetooth LE.  The UART connection accepts 3 bytes at a time.  The first byte is the R component, the second byte is the G component, and the third byte is the B component.
