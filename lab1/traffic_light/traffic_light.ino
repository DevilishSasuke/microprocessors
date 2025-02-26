// pins for each color led
int pinGreen = 2;
int pinYellow = 3;
int pinRed = 4;

// different durations
int mainGlowDuration = 3000;
int switchGlowDuration = 1000;
int blinkDuration = 500;

void setup()
{
  // set all pins as output mode
  pinMode(pinGreen, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinRed, OUTPUT);
}

void loop()
{
  // turn on green led at first
  digitalWrite(pinGreen, HIGH);
  delay(mainGlowDuration);
  
  // blink green led 3 times
  for (int i = 0; i < 3; i++) {
   	digitalWrite(pinGreen, LOW);
    delay(blinkDuration);
    digitalWrite(pinGreen, HIGH);
    delay(blinkDuration);
  }
  digitalWrite(pinGreen, LOW);
  
  // turn on and then turn off yellow led
  digitalWrite(pinYellow, HIGH);
  delay(switchGlowDuration);
  digitalWrite(pinYellow, LOW);
  
  // turn on red
  digitalWrite(pinRed, HIGH);
  delay(mainGlowDuration / 2);
  
  // add yellow led while red still glows
  digitalWrite(pinYellow, HIGH);
  delay(mainGlowDuration / 2);

  // turn off any
  digitalWrite(pinRed, LOW);
  digitalWrite(pinYellow, LOW);

  // repeat all again
}