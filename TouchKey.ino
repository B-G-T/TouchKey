#include "DigiKeyboard.h"
#include <CapacitiveSensor.h>

#define SECRET "this is a secret\n"

#define BuildInLED 1    							// internal LED at PB1

CapacitiveSensor   cs = CapacitiveSensor(2,0);      // PB2 is output pin, PB0 is sensor pin

void setup()                    
{
  pinMode(BuildInLED, OUTPUT);
  digitalWrite(BuildInLED, LOW);
}

void loop()                    
{
    long input =  cs.capacitiveSensor(30);

	if (input > 200) {
		digitalWrite(BuildInLED, HIGH);	
		DigiKeyboard.print(SECRET);
		DigiKeyboard.delay(1000);
		
		while (cs.capacitiveSensor(30) > 100) {
		}

		digitalWrite(BuildInLED, LOW);	
	}
    
    DigiKeyboard.delay(100);
}
