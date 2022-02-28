// Defintions for the different pins

#define ECHOPIN 12
#define TRIGPIN 11
#define BUZZER 10
#define LED1 2
#define LED2 4
#define LED3 7
#define LED4 8

// Tresh hold for the distance when the lights will start blinking
int blinkThreshHold = 25;

// The variable that the functions will use as a parameter
int distance;
// Distance in centimeters to indicate change in tone and lights lit
int threshHold[] = {200, 120, 80, 30};
// Intervals for sound
int soundVoltage[] = {100, 300, 600, 1000};

// array for deciding how many LEDS to should lit up in the lightLED function
int pinDecider[] = {LED1, LED2, LED3, LED4};

void setup() {

// Initialising all the pins
pinMode(ECHOPIN, INPUT); 
pinMode(TRIGPIN, OUTPUT); 
pinMode(BUZZER, OUTPUT);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);

// Sets the serial
Serial.begin(9600);

}

void loop() {

  // Gets the distance  
  distance = getDistance();
  // Starts the buzzer
  buzzAlert(distance);

  // Makes all the lights blink if it is below the blinkThreshhold
  if (distance < blinkThreshHold){
    blink();
  }
  // If not lighLED will decide how many will be lit up depending on distance
  else {
    lightLED(distance);
  }

}


int getDistance() {
// CODE TAKEN FROM https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
// to measure the distance with the ultrasonic sensor
int cm;
int duration;
// Clears the trigPin
digitalWrite(TRIGPIN, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(TRIGPIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGPIN, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(ECHOPIN, HIGH);
// Calculating the distance
cm = duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance from the object = ");
Serial.print(cm);
Serial.println(" cm");
delay(500);

return cm;

}

// Function to determine how intense the sound will be depending on distance to the object
void buzzAlert(int distance) {

    // Goes from lower distance to higher with each if/else if
    if( distance < threshHold[3]&& distance >= 0 ) {
        tone(BUZZER, soundVoltage[3]);
    }

    else if (distance < threshHold[2]) {
        tone(BUZZER, soundVoltage[2]);
    }

    else if (distance < threshHold[1]) {
        tone(BUZZER, soundVoltage[1]);

    }

    else if (distance < threshHold[0]) {
        tone(BUZZER, soundVoltage[0]);

    }

    // Turns it off if it goes higher than the highest threshold 
    else {
        noTone(BUZZER);

    }

}
// Lights up the amount of LEDs depending on the distance to the object
void lightLED(int distance) {

    // Checks through all the lights and lights them accordingly
    // loops 4 times since there are 4 LEDs
    for (int i = 0; i < 4; i++) {

        // If distance is lower than the corresponding threshhold it will light the LED
        if(distance < threshHold[i]) {
            digitalWrite(pinDecider[i], HIGH);

        }
        // if not it will turn it off
        else {
            digitalWrite(pinDecider[i], LOW);

            }
        }
    }

// Turns on all the lights and then turns them off after a small delay   
void blink() {

    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    delay(250);

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    delay(100);

}



