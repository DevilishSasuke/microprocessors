int ledPin1 = 9;
int ledPin2 = 10;
int ledPin3 = 11;
int buttonPin1 = 3;
int buttonPin2 = 3;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  analogWrite(ledPin1, 0);
  analogWrite(ledPin2, 0);
}

void loop() {
  blockButtons();
  startGame();
  unblockButtons();
}

void startGame() {
  for (int i = 0; i < 5; ++i) smoothGlow(ledPin3);
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
    return true;
  }

  return false;
}