#include <Servo.h>

Servo myservo;// instantiate the servo object

int angle = 0;// variable for angle of servo
volatile unsigned int count;// timer variable

void setup()
{
  Serial.begin(9600);
  myservo.attach(13);//attach the motor to the pin its connected to
  myservo.write(0);// set rotation angle of the motor to 

  // Lines 16 to 31 copied from source:
  // https://www.instructables.com/Arduino-Timer-Interrupts/
  cli();
//set timer0 interrupt at 2kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 50hz increments
  OCR2A = 252;// = (16*10^6) / (50*1024) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS01 and CS00 bits for 64 prescaler
  TCCR2B |= (1 << CS22) | (1 << CS20);    
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
  sei();
}
ISR(TIMER2_COMPA_vect){//timer0 interrupt 2kHz toggles pin 8
//generates pulse wave of frequency 2kHz/2 = 1kHz (takes two cycles for full wave- toggle high then toggle low)
    count ++;
    count= millis();
    count = count/1000;
    moveServo();
}


void loop()
{	
  // function called to move the motor servo
}

void moveServo(){  
  // when the angle of servo is equal to 0 it should start rotating
  // till it reaches a max of 180
   for(angle=0; angle<=180;angle++){
   myservo.write(angle);// write angle to servo
   Serial.println(count);// print out time in sec
  }
   // when the angle of servo is equal to 180 it should start rotating
  // backward it reaches a min of 0
    for(angle=180; angle>0;angle--){ 
    myservo.write(angle);// write angle to servo 
    Serial.println(count);// print out time in sec
  }    
}

// Code here :)