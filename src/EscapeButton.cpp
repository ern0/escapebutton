#include "DigiKeyboard.h"


#define PIN_BUTTON 1


	void setup() {

	  DigiKeyboard.update();
	  pinMode(PIN_BUTTON,INPUT);

	} // setup()


	void loop() {

		while ( digitalRead(PIN_BUTTON) == 0 );

	  DigiKeyboard.print("\e");
	  DigiKeyboard.update();

		while ( digitalRead(PIN_BUTTON) == 1 );

		delay(500);

	} // loop()

