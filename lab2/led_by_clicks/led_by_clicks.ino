int buttonPinHold = 4;
int ledPinHold = 8;

int buttonPinClick = 4;
int ledPinClick = 8;
int ledPinClickState = LOW;

void setup()
{
  pinMode(buttonPinClick, INPUT_PULLUP);
  pinMode(ledPinClick, OUTPUT);
}

void loop()
{  
  if (digitalRead(buttonPinClick) == HIGH) {
    while (digitalRead(buttonPinClick) == HIGH);
    ledPinClickState = !ledPinClickState;
    digitalWrite(ledPinClick, ledPinClickState);
  }
}