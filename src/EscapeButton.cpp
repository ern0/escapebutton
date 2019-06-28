#include "DigiKeyboard.h"


#define PIN_BUTTON 1
#define KEY_ESC 41


	void setup() {

	} // setup()


	void loop() {

		while ( digitalRead(PIN_BUTTON) == 0 ) {
			DigiKeyboard.delay(10);
		}

		DigiKeyboard.update();
		DigiKeyboard.sendKeyPress(KEY_ESC,0);
		DigiKeyboard.delay(200);			
		DigiKeyboard.sendKeyPress(0,0);   


		while ( digitalRead(PIN_BUTTON) == 1 ) {
			DigiKeyboard.delay(10);			
		}
	  
		DigiKeyboard.delay(100);

	} // loop()

