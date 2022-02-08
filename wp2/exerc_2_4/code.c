//Submission code 53Tuesday
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// ##### Function declarations   #####

int code(int engine_on, int gear_pos, int key_pos, int brake1, int brake2);

//###### Main program #######

int main(int argc, char *argv[])
{
  // Condition to make sure user inputs no more or less than 5 arguments
  if (argc == 6)
  {
    // Retrieving the first input inputted by the user
    char *engine_input= argv[1];
    // Retrieving the second input inputted by the user
    char *gear_input= argv[2];
    // Retrieving the third input inputted by the user
    char *key_input= argv[3];
    // Retrieving the fourth input inputted by the user
    char *brake1_input= argv[4];
    // Retrieving the fifth input inputted by the user
    char *brake2_input= argv[5];
   
    // Converting retrieved values into integers using the atoi function
    // Intializing our variables for each of our 5 inputs
    // Setting each variable to its respective input from the user
    int engine_on = atoi(engine_input);
    int gear_pos = atoi(gear_input);
    int key_pos =  atoi(key_input);
    int brake1 = atoi(brake1_input);
    int brake2 = atoi(brake2_input);
    
    // Function called to code the user input
    code(engine_on, gear_pos, key_pos, brake1, brake2);
  }
  // Condition for if user did not input sufficient arguments
  else{

    // Error message for the user
    printf("Not enough arguments inputted\n");
  }

  return 0;
}

// ====     End of main   ======================================


// ##### Function definitions   #####

int code(int engine_on, int gear_pos, int key_pos, int brake1, int brake2)
{
  // Initializing the variable byte to pack the bits into as 0
  unsigned char byte = 0;
  // Setting byte as equal to brake2 first
  byte = brake2;
  // Setting brake1 bit to its position one shift to the left
  brake1 = brake1 << 1;
  // Using bit operand OR to combine byte and brake1 
  // placing  brake1's position in byte as second position 
  byte = byte | brake1;
  // Shifting key_pos to the left to its position in the byte
  key_pos = key_pos << 2;
  // Using bit operand OR to combine byte and key_pos
  byte = byte | key_pos;
  // Shifting gear_pos to the left 4 four times to its position in the byte
  gear_pos = gear_pos << 4;
  // Using bit operand OR to combine byte and gear_pos 
  byte = byte | gear_pos;
  // Shifting gear_pos to the left 7 times to its position in the byte
  engine_on = engine_on << 7;
  // Using bit operand OR to combine byte and gear_pos 
  byte = byte | engine_on;

  // Priniting the value of the byte in hexadecimal value 
  printf("Number of byte is : %X\n", byte);
  // Printing the size of byte to make sure its one.
  printf("Size of byte is %lu\n", sizeof(byte));

  return 0;
}
