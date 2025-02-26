int buttonPin = 4;
int ledPin = 8;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  digitalWrite(ledPin, digitalRead(buttonPin));
}