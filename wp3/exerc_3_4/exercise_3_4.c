// Arrays for the pinouts the columns and rows the keypads are connected to
const int pinCols[4]={7,6,5,4};
const int pinRows[4]={11,10,9,8};

// Matrix depicting the keypad and every key's position 
char keys[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  // loop the function called to read the key pressed
  readKey();
}

void readKey(){
  // loop to go through each row of keypad
  for (int r=0; r<4; r++) {
    //set each row to output mode
    pinMode(pinRows[r], OUTPUT);
    // loop to go through each column of keypad
    for(int c=0; c<4; c++){
      // Condition to check if a key on the column c has been pressed
      if (digitalRead(pinCols[c]) == LOW) {
        // Print out the key pressed with its right symbol
        Serial.println(keys[r][c]); 
        // delay by a second
        delay(1000);
      }
    }
    // Switch rows back to input mode
    pinMode(pinRows[r], INPUT);
  }
}