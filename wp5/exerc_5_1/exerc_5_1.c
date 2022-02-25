//Thursday1

#define BUTTONPIN 4
#define BLINKPIN 7
#define BUTTON 8

// Variable for interval between blinks of light
int lightSpeed = 0;
// Variable for button clicked
int buttonClick = 0;

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(BUTTONPIN, OUTPUT);
  pinMode(BLINKPIN, OUTPUT);
}

void loop()
{
  // button should be read from the pin its connected to pin 2
  buttonClick = digitalRead(BUTTON);
  // Condition to check if button is clicked
  if (buttonClick == HIGH) {
    // LED should light up
    digitalWrite(BUTTONPIN, HIGH);
  } else {
    // LED should not light up
    digitalWrite(BUTTONPIN, LOW);
  }
  // the time between blinks for light set to half a second
  lightSpeed = 500;
  // Call LED to light up
  digitalWrite(BLINKPIN, HIGH);
  // Wait for the time interval given
  delay(lightSpeed); 
  // Call LED to turn light off
  digitalWrite(BLINKPIN, LOW);
  // Wait for time interval given
  delay(lightSpeed); 
}