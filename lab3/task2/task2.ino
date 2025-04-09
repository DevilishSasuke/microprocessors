int ledPin1 = 9;
int ledPin2 = 10;
int ledPin3 = 11;
int buttonPin1 = 3;
int buttonPin2 = 5;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

  analogWrite(ledPin1, 0);
  analogWrite(ledPin2, 0);
  analogWrite(ledPin3, 0);
  
  Serial.begin(9600);
}

void loop() {
  startGame();
  Serial.println("End of start game");
  Serial.println("Start of button handling");
  handleEveryButton();
  delay(2000);
}

void startGame() {
  Serial.println("GAME STARTED.");
  int iteration_num = random(3, 7);
  for (int i = 0; i < 5; ++i) 
  {
    int brightness = random(90, 256);
    int delay_time = random(2, 10);
    smoothGlow(ledPin3, brightness, delay_time);
    Serial.println(i);
  }
}

void smoothGlow(int pinPos, int brightness, int delay_time) {
  for (int i = 0; i < brightness; ++i) {
    analogWrite(pinPos, i);
    delay(delay_time);
  }
  for (int i = brightness; i >= 0; --i) {
    analogWrite(pinPos, i);
  	delay(delay_time);
  }
}

void showWin(int pin) {
  analogWrite(pin, 250);
  delay(3000);
  analogWrite(pin, 0);
}

void handleEveryButton() {
	bool btnReady1 = false;
	bool btnReady2 = false;
  Serial.println("Start of button check");
	while (true){
		if (digitalRead(buttonPin1) == LOW) btnReady1 = true;
		if (digitalRead(buttonPin2) == LOW) btnReady2 = true;
    Serial.print(btnReady1 ? "READY" : "NOT_READY");
    Serial.print(" ");
    Serial.println(btnReady2 ? "READY" : "NOT_READY");
    Serial.print(digitalRead(buttonPin1));
    Serial.print(" ");
    Serial.println(digitalRead(buttonPin2));
		if (digitalRead(buttonPin1) == HIGH && btnReady1) {
      showWin(ledPin1);
      Serial.println("Player 1 win");
      break;
    }
		if (digitalRead(buttonPin2) == HIGH && btnReady2) {
      showWin(ledPin2);
      Serial.println("Player 2 win");
      break;
    }
	}

  Serial.println("GAME ENDED.");
}

