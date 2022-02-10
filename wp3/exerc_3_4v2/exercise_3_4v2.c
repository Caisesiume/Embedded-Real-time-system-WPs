//Thursday 32
#include <Keypad.h>

const byte ROWS = 4; //four rows of the keypad
const byte COLS = 4; //four columns of the keypad
// Maxtric depict the keypad
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
// Two byte arrays to fill the pinouts connected to the rows and columns of the keypad
byte rowPins[ROWS] = {11, 10, 9, 8};
byte colPins[COLS] = {7, 6, 5, 4}; 

//Instantiates a Keypad object that uses pins 11, 10, 9, 8 as row pins, and 7, 6, 5, 4  as column pins.
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();
// Condition to check if key is pressed
  if (key != NO_KEY){
    // Function printing the key pressed
    Serial.println(key);
  }
}
