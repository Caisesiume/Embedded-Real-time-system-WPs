#include <Adafruit_NeoPixel.h>
#define PIN 9
#define N_LEDS 12

int sensePin = A0; //This is the Arduino Pin that will read the sensor output
int sensorInput; //The variable we will use to store the sensor input
double temp; //The variable we will use to store temperature in degrees.

float tempRange[] = { -30.0, -20.0, -10.0, 0.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0 };

Adafruit_NeoPixel neoRing = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
void setup()
{
  neoRing.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
sensorInput = analogRead(A0); //read the analog sensor and store it
temp = (double)sensorInput / 1024; //find percentage of input reading
temp = temp *5;
temp = temp - 0.5;
temp = temp * 100;
Serial.print("Current Temperature: ");
Serial.println(temp);
 
displayTemp();

  
}
void displayTemp() {

    for (int i = 0; i < 12; i++) {

        if (temp > tempRange[i]) {
          

          neoRing.setPixelColor(i, neoRing.Color(255,0,0));
          neoRing.show();	
        }
      
      else {
        neoRing.setPixelColor(i, 0);
        digitalWrite(13, LOW);
        neoRing.show();
      }
      
      if( temp > tempRange[12]) {
        digitalWrite(13, HIGH);
      }
    }
  
}