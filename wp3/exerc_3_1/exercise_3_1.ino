//Thursday 32
// Variable for interval between blinks of light
int lightSpeed = 0;
// Variable for button clicked
int buttonClick = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  // button should be read from the pin its connected to pin 2
  buttonClick = digitalRead(2);
  // Condition to check if button is clicked
  if (buttonClick == HIGH) {
    // LED should light up
    digitalWrite(11, HIGH);
  } else {
    // LED should not light up
    digitalWrite(11, LOW);
  }
  // the time between blinks for light set to half a second
  lightSpeed = 500;
  // Call LED to light up
  digitalWrite(13, HIGH);
  // Wait for the time interval given
  delay(lightSpeed); 
  // Call LED to turn light off
  digitalWrite(13, LOW);
  // Wait for time interval given
  delay(lightSpeed); 
}
