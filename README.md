"# Tiny_sonar" 
DIY a I2C Maxbotic sonar sensor with Tiny 85 and US-020 sonar sensor
 
Trig & Echo ->PB3(Pin 3 on Digispark board, 2nd pin on IC)
SCL ->PB2 (Pin 2 on Digispark board, 7th pin on IC)
SDA ->PB0 (Pin 0 on Digispark board, 5th pin on IC)
I2C port on Pixhawk, left to right
VCC, SCL, SDA, GND

First, flash the 8MHz bootloader to tiny 85,
Then upload this sketch using a programmer
