#define ECHOPIN 12
#define TRIGPIN 11
#define BUZZER 10
#define LED1 2
#define LED2 4
#define LED3 7
#define LED4 8

int blinkThreshHold = 25;
int distance;
int threshHold[] = {200, 120, 80, 30};
int soundVoltage[] = {100, 300, 600, 1000};
int pinDecider[] = {LED1, LED2, LED3, LED4};

void setup() {
pinMode(TRIGPIN, OUTPUT); // Sets the trigPin as an Output
pinMode(ECHOPIN, INPUT); // Sets the echoPin as an Input
pinMode(BUZZER, OUTPUT);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
Serial.begin(9600); // Starts the serial communication

}

void loop() {

  distance = getDistance();
  buzzAlert(distance);
  if (distance < blinkThreshHold){
    blink();
  }
  else {
    lightLED(distance);
  }

}

int getDistance() {
    // Clears the trigPin
int cm;
int duration;
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
Serial.print(distance);
Serial.println(" cm");
delay(500);

return cm;

}

void buzzAlert(int distance) {

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

    else {
        noTone(BUZZER);

    }

}

void lightLED(int distance) {

    for (int i = 0; i < 4; i++) {

        if(distance < threshHold[i]) {
            digitalWrite(pinDecider[i], HIGH);

        }

        else {
            digitalWrite(pinDecider[i], LOW);

            }
        }
    }
void blink() {

    light();
    delay(250);
    darken();
    delay(100);

}

void light() {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
}

void darken() {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);

}


