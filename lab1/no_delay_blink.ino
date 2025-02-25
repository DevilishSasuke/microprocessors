unsigned long previousMillis = 0; // start of time period
const long interval = 1000; // delay in ms
boolean state = HIGH; // current state of builtin led

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // set pin mode
}

void loop()
{
  // nubmer milliseconds since program started
  unsigned long currentMillis = millis();

  // if enough time has passed
  if (currentMillis - previousMillis >= interval) {
    // change led statement
    previousMillis = currentMillis;
    digitalWrite(LED_BUILTIN, state);
    state = !state;
  }
  
}