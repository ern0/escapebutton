#include "DigiKeyboard.h"


#define SESSION_DURATION_SECS (2 * 60 * 60)
#define LED_PIN 1

static unsigned long int keypress_round = 0;
static unsigned long int random_kindof;
static unsigned char led_state = 0;

    void setup() {

        keypress_round = SESSION_DURATION_SECS;
        random_kindof = 7;

	pinMode(LED_PIN, OUTPUT);

    } // setup()


    void loop() {

        DigiKeyboard.delay(1000);

        if (keypress_round == 0) {
		digitalWrite(LED_PIN, 0);
		return;
	}

        --keypress_round;

        random_kindof = random_kindof * 9;
        unsigned actual = (random_kindof / 100) % 10;

        char buffer[20];
        snprintf(buffer, 2, "%d", actual);
        DigiKeyboard.print(buffer);

	digitalWrite(LED_PIN, led_state);
	led_state = 1 - led_state;

    } // loop()

