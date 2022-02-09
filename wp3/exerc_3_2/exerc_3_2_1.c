
#define PIN13 13

#define PIN8 8

#define PINTEMP A0

#define PINLIGHT A1

int tempSensorC;
int lightIntensity;
int pollrate = 5;

// runs only on startup
void setup()
{
  pinMode(PIN13, OUTPUT);
  Serial.begin(9600);
}

// Executed as a loop, over and over.
void loop()
{
  tempSensorC = getTemp();
  lightIntensity = getLightIntensity();
  Serial.print("Temp:");
  Serial.println(tempSensorC);
  Serial.print("Light:");
  Serial.println(lightIntensity);
  delay(pollrate*1000);
}

int getTemp() {
  int valueInC;
  //analogRead reads the analog value of the input at the arg.
  int sensorOutput = analogRead(PINTEMP);
  
  // Gets the interval between 2nd & 3rd arg, outputs a value by the same ratio
  // within the interval provided at arg 4 and 5.
  valueInC = map(sensorOutput, 40, 358, -40, 125);
  
  // Mathematical solution to the conversion.
  
  // sensorOutC = (double) sensorOutput / 1023; 
  // 	The analog value we read is always between 0 and 1023. 0 being 0V and 1023 being 5V
  // 	TMP36s output is between 0V - 1.75V depending on the temp.
  // 	And the range of temperatures are -50C to 125C which is a range of 175 degrees.
  // 	That means one degree is 0.01V and 50C = 1.00V
  // sensorOutC = sensorOutC*5;
  // 	Our value will now be between 0C - 175C. We want it to be -50C - 125C, so we need
  // 	to subtract the offset (-50C / -0.5 mathematically) before converting it to Celcius.
  // sensorOutC = sensorOutC - 0.5;
  // 	Now we only have the Voltage value between -0.5 and 1.25V
  // 	We want to convert this to Celcius so we need to multiply this 
  // 	by 100 to get the correct scale.
  // sensorOutC = sensorOutC * 100;
  return valueInC;
}

int getLightIntensity() {
  int lightPercentage;
  
  //analogRead reads the analog value of the input at the arg.
  int inputLight = analogRead(PINLIGHT);
  
  lightPercentage = map(inputLight, 54, 974, 0, 100);
  
  return lightPercentage;
}