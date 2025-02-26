int buttonPinHold = 4;
int ledPinHold = 8;

int buttonPinClick = 2;
int ledPinClick = 10;
int lPCState = LOW;

int ledPinKeyboard = 6;
int lPKState = LOW; // state of led controlling by keyboard
int lBState = LOW; // state of builtin led

void setup()
{
  // set required mods for all buttons and leds to handle it correctly
  pinMode(buttonPinHold, INPUT_PULLUP);
  pinMode(ledPinHold, OUTPUT);
  pinMode(buttonPinHold, INPUT_PULLUP);
  pinMode(ledPinHold, OUTPUT);
  pinMode(ledPinKeyboard, OUTPUT);

  Serial.begin(9600); // open port with default speed

  // show user quick guide how to use it
  Serial.println("Command list:");
  Serial.println("Q - to change builtin led mode");
  Serial.println("W - to change chosen led mode");
  Serial.println("e - to change both modes: for builtin and chosen\n\n\n");
}

void loop()
{
  // glows while button is pressed
  digitalWrite(ledPinHold, digitalRead(buttonPinHold));
  
  // if button was pressed
  if (digitalRead(buttonPinClick) == HIGH) {
    // wait till button will be unpressed
    while (digitalRead(buttonPinClick) == HIGH);
    lPCState = !lPCState; // change state of led
    digitalWrite(ledPinClick, lPCState); // set updated state
  }

  // if any data was recieved
  if  (Serial.available()) {
    // read by byte (commands are chars so any other type is excess)
    char command = Serial.read();

    // show received command
    Serial.print("Command recieved: ");
    Serial.println(command);

    // handle recieved command in any letter case
    if (command == 'q' || command == 'Q') {
      lBState = !lBState;
      digitalWrite(LED_BUILTIN, lBState);
      delay(500);
    }
    else if (command == 'w' || command == 'W') {
      lPKState = !lPKState;
      digitalWrite(ledPinKeyboard, lPKState);
      delay(500);
    }
    else if (command == 'e' || command == 'E') {
      lBState = !lBState;
      lPKState = !lPKState;
      digitalWrite(LED_BUILTIN, lBState);
      digitalWrite(ledPinKeyboard, lPKState);
      delay(500);
    } else {
      // notify user that command is invalid
      Serial.println("There is no such a command. \
      You can use only Q, W, E commands.");
    }
  }
}