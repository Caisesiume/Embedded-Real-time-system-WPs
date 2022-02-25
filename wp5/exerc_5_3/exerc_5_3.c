// Thursday 1

#define PINTEMP A0 // Analog 0

#define PINLIGHT A1 // Analog 1

#define LED_BLUE 8 // PIN 8

#define LED_GREEN 7 // PIN 7

#define LED_RED 4 // PIN 4

#define LOWER -1 //dependency indicator

#define NORMAL 0 //dependency indicator

#define HIGHER 1 //dependency indicator

int tempSensorC;
int lightIntensity;
const int pollrate = 2; // pollrate * 1000 gives the delay we are looking for in ms.

// runs only on startup
void setup()
{
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.begin(9600);
}

// Executed as a loop, over and over.
void loop()
{
  tempSensorC = getTemp();
  lightIntensity = getLightIntensity();
  int dependency = checkDependency(tempSensorC, lightIntensity);
  
  // Turns off all LEDs but red
  // Turns on red LED
  if(dependency == HIGHER)
  {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_RED, HIGH);
  }
  else if(dependency == NORMAL)
  {
    // Turns off all LEDs but green
  	// Turns on green LED
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, HIGH);
  }
  if(dependency == LOWER)
  {
    // Turns off all LEDs but blue
  	// Turns on blue LED
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_RED, LOW);
  }
  
  
  Serial.print("Temp:");
  Serial.println(tempSensorC);
  Serial.print("Light:");
  Serial.println(lightIntensity);

  //Loops every pollrate second
  delay(pollrate*1000);
}


// Function checks wether the temp is normal or higher/lower than normal depending on the light intensity.
// Returns -1 for lower deviation from normal levels.
// Returns 0 for normal
// Returns 1 for higher deviation from normal levels.
int checkDependency(int temp, int light) {
    // --- LIGHT INTENSITY 0% ---
    if (light == 0)
    {
        // The deviations can only be to the higher.
        // Follows dependency| temp  | light|
        // normal dependency | < -12 |  0%  |
        // higher deviation  | >= -12|  0%  |
        if (temp < -12)
        {
            // If the temperature is lower than -12C
            // it is withing the normal dependency.
          	return NORMAL;
        }
        else
        {
            // otherwise, the only possible state is for the temp to
            // be higher or equal to -12C
            
          	return HIGHER;
        }
    }
    // --- LIGHT INTENSITY RANGE 1% TO 20% ---
    else if (light > 0 && light < 21)
    {
        // Follows dependency|  temp   |   light  |
        // lower deviation   |  < -12  | 1% - 20% |
        // normal dependency | -12 - 0 | 1% - 20% |
        // higher deviation  |  >=  0  | 1% - 20% |

        if (temp < -12)
        {
            // All temperatures below -12 are lower deviations.
            // Blue LED = lower deviationn
        	return LOWER;
        }
        else if (temp >= -12 && temp < 0)
        {
            // temp ranges between -12 and -0 indicates normal dependency
            // Green = normal
        	return NORMAL;
        }
        else if (temp >= 0)
        {
            // All temperatures above +0 are higher deviations.
            // Red = higher deviation
        	return HIGHER;
        }
    }
    // --- LIGHT INTENSITY RANGE 21% TO 60% ---
    else if (light >= 21 && light <= 60)
    {
        // Follows dependency|  temp   |   light   |
        // lower deviation   |   < 0   | 21% - 60% |
        // normal dependency |  0 - 20 | 21% - 60% |
        // higher deviation  |  > 20   | 21% - 60% |

        if (temp < 0)
        {
            // All temperatures below 0 are lower deviations.
            // Blue = lower deviationn
          	return LOWER;
        }
        else if (temp >= 0 && temp <= 20)
        {
            // temp ranges between 0 and 20 indicates normal dependency
            // Green = normal
          	return NORMAL;
        }
        else if (temp > 20)
        {
            // All temperatures above 20 C are higher deviations.
            // Red = higher deviation
          	return HIGHER;
        }
    }
    // --- LIGHT INTENSITY RANGE 61% AND HIGHER ---
    else if (light >= 61)
    {
        // Temps can only be lower than the normal dependency
        // since there is no upper limit for it.
        // Follows dependency|  temp   |  light  |
        // lower deviation   |   < 21  |  >= 61% |
        // normal dependency |  >= 21  |  >= 61% |

        if (temp < 21)
        {
            // All temperatures below 21 C are lower deviations.
            // Blue = lower deviationn
          	return LOWER;
        }
        else if (temp >= 21)
        {
            // temp greater or equal indicates normal dependency
            // Green = normal
          	return NORMAL;
        }
    }
}


// Returns the temperature of the sensor in degrees celcius.
int getTemp() {
  //analogRead reads the analog value of the input at the arg.
  int sensorOutput = analogRead(PINTEMP);
  
  // --- Mathematical solution to the conversion. ---
  double sensorOutC = (double) sensorOutput / 1023; 
  // 	The analog value we read is always between 0 and 1023. 0 being 0V and 1023 being 5V
  // 	TMP36s output is between 0V - 1.75V depending on the temp.
  // 	And the range of temperatures are -50C to 125C which is a range of 175 degrees.
  // 	That means one degree is 0.01V and 50C = 1.00V
  sensorOutC = sensorOutC*5;
  // 	Our value will now be between 0C - 175C. We want it to be -50C - 125C, so we need
  // 	to subtract the offset (-50C / -0.5 mathematically) before converting it to Celcius.
  sensorOutC = sensorOutC - 0.5;
  // 	Now we only have the Voltage value between -0.5 and 1.25V
  // 	We want to convert this to Celcius so we need to multiply this 
  // 	by 100 to get the correct scale.
  sensorOutC = sensorOutC * 100;
  return sensorOutC;
}

int getLightIntensity() {
  // In order to establish a light intensity percentage we need a linear scale to compare
  // our analog read with.
  // What we are reading from pin A1(PINLIGHT) is not linear.
  // Therefore we need to convert the analog read to a scale that is linear, like Lux.
  int lightPercentage;
  
  //analogRead reads the analog value of the input at the arg.
  int inputLight = analogRead(PINLIGHT);
  
  // Calculating Lux from Resistance explained by James Carlson:
  
  double Vout = inputLight*0.0048828125;
  int lux=500/(10*((5-Vout)/Vout));
  
  // Gets the interval between 2nd & 3rd arg, outputs a value by the same ratio
  // within the interval provided at arg 4 and 5.
  
  // We can then use map to change the scale to the scale we wish to use. But only if the original
  // scale is linear.
  // inputLight is not linear, which is why we convert the value to lux which is a linear scale.
  // we then use the lux value to calculate the percentage of the light.
  lightPercentage = map(lux, 0, 98, 0, 100);
  
  return lightPercentage;
}