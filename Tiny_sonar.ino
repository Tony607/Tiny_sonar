///*
//This sketch runs on an ATtiny85/45
//This sketch gets distance data from an US-020 sonar sensor and transmits it to the I2C master when requested
//For details on this sketch and instructions on making this low cost I2C PING sensor, see the link below.
//----IMPORTANT----\/
//TinyWireS use https://github.com/Tony607/TinyWire
//other versions of library will crash since we are sending 2 bytes in one request, standard library only can send one
//
//*/
#include <TinyWireS.h>              // Requires fork by Rambo with onRequest support https://github.com/Tony607/TinyWire
#include <TinyNewPing.h>            // NewPing library modified for ATtiny, https://github.com/Tony607/TinyNewPing
const byte SensorOnePin = 3;        // Sensor 1 is connected to PB3
const byte I2CSlaveAddress = 0x70;      // I2C Address Maxbotic.
byte Distance;                              // Where the Distance is stored (8 bit unsigned)
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters).
NewPing SensorOne (SensorOnePin, SensorOnePin, MAX_DISTANCE);       // Define the Sensor
void setup()
{
   tws_delay(100);//use this to replace the delay() function
   TinyWireS.begin(I2CSlaveAddress);      // Begin I2C Communication
   TinyWireS.onRequest(transmit);         // When requested, call function transmit()
}
void loop()
{
   Distance = SensorOne.ping_cm();        // Get distance in cm. Could be changed to
   //Distance = SensorOne.ping_median(5)/US_ROUNDTRIP_CM;       // Take the median of 5 readings
   tws_delay(30);                             // Delay to avoid interference from last ping
}  //end loop()

void transmit()
{

   byte sendhi;
   byte sendli;
   uint16_t tempreading_cm;
   tempreading_cm=Distance;
   sendhi=tempreading_cm>>8;
   sendli=tempreading_cm&0xff;
   TinyWireS.send(sendhi);
   TinyWireS.send(sendli);
}