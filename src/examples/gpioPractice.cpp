/* A Simple GPIO application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

#include <iostream>
#include <unistd.h> //for usleep
#include "gpio/GPIO.h"
using namespace exploringBB;
using namespace std;

int main(){
   GPIO outGPIO(45), inGPIO(115);

   // Basic Output - Flash the LED 10 times, once per second
   outGPIO.setDirection(GPIO::OUTPUT);
   for (int i=0; i<10; i++){
      outGPIO.setValue(GPIO::HIGH);
      usleep(500000); //micro-second sleep 0.5 seconds
      outGPIO.setValue(GPIO::LOW);
      usleep(500000);
   }
   // Basic Input example
   inGPIO.setDirection(GPIO::INPUT);
   cout << "The value of the input is: "<< inGPIO.getValue() << endl;

   // Fast write to GPIO 1 million times
   outGPIO.streamOpen();
   for (int i=0; i<1000000; i++){
      outGPIO.streamWrite(GPIO::HIGH);
      outGPIO.streamWrite(GPIO::LOW);
   }
   outGPIO.streamClose();

   return 0;
}
