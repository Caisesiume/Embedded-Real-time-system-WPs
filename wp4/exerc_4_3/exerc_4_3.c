#include <Adafruit_NeoPixel.h>
#define PIN 9
#define N_LEDS 12

int sensePin = A0; //This is the Arduino Pin that will read the sensor output
int sensorInput; //The variable we will use to store the sensor input
double temp; //The variable we will use to store temperature in degrees.

// the threshholds for amounts of lights to be lit 
float tempRange[] = { -30.0, -20.0, -10.0, 0.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0 };

// Initializes the neoring
Adafruit_NeoPixel neoRing = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
void setup()
{

  // starts the neoring
  neoRing.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
sensorInput = analogRead(A0); //read the analog sensor and store it
temp = (double)sensorInput / 1024; //find percentage of input reading

// Converts the temperature from volts to celcius
temp = temp *5;
temp = temp - 0.5;
temp = temp * 100;

// Prints it out to the serial
Serial.print("Current Temperature: ");
Serial.println(temp);
 
// calls the function that displays the temperature 
displayTemp();

  
}
 // Function to display the temperature on the neoring
void displayTemp() {

    // Loops through the amount of lights on the ring to check which ones to light
    for (int i = 0; i < 12; i++) {


        // will light the amount of lights dependent on if the read temperature is above a specific threshhold of temperatures
        // thresholds decided in the tempRange array
        if (temp > tempRange[i]) {
          
          // Sets the color of the light and then displays it
          neoRing.setPixelColor(i, neoRing.Color(255,0,0));
          neoRing.show();	
        }
      
      else {
        // turns of the lights on the wheel if temperature would drop
        neoRing.setPixelColor(i, 0);

        // turns off the led (will never go here if temp is above threshhold)
        digitalWrite(13, LOW);
        neoRing.show();
      }
      
      // if temperature is higher than the given threshhold in the array the led will light up
      if( temp > tempRange[12]) {
        digitalWrite(13, HIGH);
      }
    }
  
}