const int	SWING_POSITION_PIN =	A0;
const int	RESET_BUTTON_PIN =		2;

int	val = 0;
int	resetValue = -1;

void setup() {
	bool didReset = false;
	int	resetButtonValue = 0;
	
	pinMode(SWING_POSITION_PIN,	INPUT);
	pinMode(RESET_BUTTON_PIN,	INPUT);

	Serial.begin(57600);

	while (resetButtonValue == 0) {
		resetButtonValue = digitalRead(RESET_BUTTON_PIN);
	}

	while (resetButtonValue == 1) {
		resetButtonValue = digitalRead(RESET_BUTTON_PIN);
		resetValue = analogRead(SWING_POSITION_PIN);
	}

	Serial.println("reset value: " + String(resetValue));
}

void loop() {
	val = analogRead(SWING_POSITION_PIN);
	Serial.println("swing position: " + String(resetValue - val));
}
