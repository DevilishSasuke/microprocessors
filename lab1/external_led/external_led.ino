int ledPin = 8; // Set any pin you want to connect

void setup()
{
  pinMode(ledPin, OUTPUT); 
}

void loop()
{
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}