int ledPin1 = 9;
int ledPin2 = 10;
int buttonPin1 = 3;

bool isYellow = true;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT);

  analogWrite(ledPin1, 0);
  analogWrite(ledPin2, 0);
}

void loop() {
  buttonClicked();

  if (isYellow) {
    analogWrite(ledPin2, 0);
    smoothGlow(ledPin1);
  }
  else {
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 100);
  }
}

void smoothGlow(int pinPos) {
  for (int i = 0; i < 100; ++i) {
    analogWrite(pinPos, i);
    if (buttonClicked()) return;
  }
  for (int i = 100; i >= 0; --i) {
    analogWrite(pinPos, i);
    if (buttonClicked()) return;
  }
}

bool buttonClicked() {
  if (digitalRead(buttonPin1) == HIGH) {
    while (digitalRead(buttonPin1) == HIGH);
    changeMode();
    return true;
  }

  return false;
}

void changeMode() {
  isYellow = !isYellow;
}