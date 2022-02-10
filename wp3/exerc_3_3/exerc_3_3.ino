//Thursday 32

#define PINTEMP A0 // Analog 0

int tempSensorC;
int lightIntensity;
const int pollrate = 500; // in ms  = 0.5 seconds. 

// runs only on startup
void setup()
{
  Serial.begin(9600);
}

// Executed as a loop, over and over.
void loop()
{
  // Calls a function that calculates and returns the temperature in celcius
  tempSensorC = getTemp();
  
  Serial.print("Temp:");
  Serial.println(tempSensorC);

  // Loops every time the amount of milliseconds pollrate contains has passed.
  // Right now, 500ms 
  delay(pollrate);
}


// Returns the temperature of the sensor in degrees celcius.
int getTemp() {
  int valueInC;
  //analogRead reads the analog value of the input at the arg.
  int sensorOutput = analogRead(PINTEMP);
  
  // Gets the interval between 2nd & 3rd arg, outputs a value by the same ratio
  // within the interval provided at arg 4 and 5.
  // We know the min value from sensorOutput is 40 and max 358.
  // We can then use map to change the scale to the scale we wish to use if the original
  // scale is linear.
  valueInC = map(sensorOutput, 20, 358, -40, 125);
  
  // Alternative solution
  // --- Mathematical solution to the conversion. ---
 
  // tempSensorC = sensorOutput / 1024.0;
  // 	The analog value we read is always between 0 and 1024. 0 being 0V and 1024 being 5V.
  // 	TMP36s output is between 0V - 1.75V depending on the temp.
  // 	And the range of temperatures are -50C to 125C which is a range of 175 degrees.
  // 	That means one degree is 0.01V and 50C = 1.00V
  // tempSensorC = tempSensorC*5;
  // 	Our value will now be between 0C - 175C. We want it to be -50C - 125C, so we need
  // 	to subtract the offset we currently have (-50C / -0.5 mathematically) before converting 
  //  it to Celcius.
  // tempSensorC = tempSensorC - 0.5;
  // 	Now we only have the Voltage value between -0.5 and 1.25V
  // 	We want to convert this to Celcius so we need to multiply this 
  // 	by 100 to get the correct scale.
  // tempSensorC = tempSensorC * 100;

  return valueInC;
}