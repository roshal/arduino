const unsigned int constant_period_half = 512;
const unsigned int constant_period = constant_period_half << 1;
unsigned int variable_period = 0;
unsigned int variable_period_timer = 1 + 1 / constant_period;
const unsigned int constant_pin_color_r = 11;
const unsigned int constant_pin_color_g = 10;
const unsigned int constant_pin_color_b = 9;
unsigned int variable_rgb[3];
void setup()
{
  Serial.begin(9600);
  pinMode(constant_pin_color_r, OUTPUT);
  pinMode(constant_pin_color_g, OUTPUT);
  pinMode(constant_pin_color_b, OUTPUT);
}
void loop()
{
  for (unsigned int decrease = 0; decrease < 3; decrease += 1) {
    unsigned int increase = decrease == 2 ? 0 : decrease + 1;
    for (unsigned int i = 0; i < 255; i += 1) {
      variable_rgb[decrease] -= 1;
      variable_rgb[increase] += 1;
      function__void__rgb(variable_rgb[0], variable_rgb[1], variable_rgb[2]);
      delay(variable_period_timer);
    }
  }
}
void function__void__rgb(unsigned int r, unsigned int g, unsigned int b) {
  analogWrite(constant_pin_color_r, r);
  analogWrite(constant_pin_color_g, g);
  analogWrite(constant_pin_color_b, b);
}
