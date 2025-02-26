void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // set pin mode
}

void loop()
{
  
  digitalWrite(LED_BUILTIN, HIGH); // turn on led
  delay(1000); // wait for some time
  digitalWrite(LED_BUILTIN, LOW); // turn off led
  delay(1000); // wait again
}