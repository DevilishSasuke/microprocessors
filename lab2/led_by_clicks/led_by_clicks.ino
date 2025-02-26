int buttonPinHold = 4;
int ledPinHold = 8;

int buttonPinClick = 2;
int ledPinClick = 10;
int ledPinClickState = LOW;

void setup()
{
  pinMode(buttonPinHold, INPUT_PULLUP);
  pinMode(ledPinHold, OUTPUT);
  pinMode(buttonPinHold, INPUT_PULLUP);
  pinMode(ledPinHold, OUTPUT);
}

void loop()
{
  digitalWrite(ledPinHold, digitalRead(buttonPinHold));
  
  if (digitalRead(buttonPinClick) == HIGH) {
    while (digitalRead(buttonPinClick) == HIGH);
    ledPinClickState = !ledPinClickState;
    digitalWrite(ledPinClick, ledPinClickState);
  }
}