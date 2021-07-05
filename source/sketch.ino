
const unsigned int constant_period_half = 1 << 9;

const unsigned int constant_period = constant_period_half << 1;

unsigned int variable_period = 0;
unsigned int variable_period_timer = 1 + 1 / constant_period;

const unsigned int constant_pin_button = 2;
const unsigned int constant_pin_led = 13;

unsigned int variable_button = 0;
unsigned int variable_signal = 0;

void setup() {
	Serial.begin(9600);
	pinMode(constant_pin_led, OUTPUT);
	pinMode(constant_pin_button, INPUT);
}

void loop() {
	analogRead(variable_button);
	Serial.println(variable_button);
	variable_signal = function__int__mapping(variable_period);
	analogWrite(constant_pin_led, variable_signal);
	variable_period = (variable_period + 1) % constant_period;
	delay(variable_period_timer);
}

unsigned int function__int__mapping(unsigned int variable) {
	const unsigned int constant_module = abs(variable % constant_period_half);
	if (variable < constant_period_half) {
		return constant_module;
	}
	return constant_period_half - constant_module - 1;
}

void function__void__digital() {
	const unsigned int constant_button = digitalRead(constant_pin_button);
	if (variable_button == LOW) {
		digitalWrite(constant_pin_led, LOW);
		Serial.println(LOW);
	} else {
		digitalWrite(constant_pin_led, HIGH);
		Serial.println(HIGH);
	}
}
