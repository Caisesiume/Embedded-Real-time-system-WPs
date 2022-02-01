//Tuesday1

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Calculates what the new letter will be
char shiftLetter(int shiftValue, int startOfAlphabet, int endOfAlphabet) {

  // If the new value goes beyond the scope of the alphabet e.g. Z + 4
  // Will be 4 positions outside of the alphabet and Y + 4 will be
  // 3 positions outside.
  // It will then add that difference to the start of the alphabet
  // Z + 4 -> A + 4 = D, Y + 4 -> A + 3 = D
  if (shiftValue > endOfAlphabet) {

    return startOfAlphabet + (shiftValue - endOfAlphabet);
  }

  // If if stays inside the scope of the alphabet it will return the new value
  // as it is
  else {

    return shiftValue;
  }
}
// Function to encrypt the input from the user with x amount of letters
// forward decided by the program argument. 
// Will first check if the character is upper or lowercase and then 
// pass it to a function that will shift them accordingly 
char encrypt(char c, int argument) {
 
  // The value of the userinput character + the amount of characters 
  // that it will be shifted forward
  char shiftValue = c + argument;
  
  // Checks if the character is upper case using ASCII table values
  if (c <= 90 && c > 64 ) {

  // Provides the function with the user input + the start and end of the 
  // alphabet values
  return shiftLetter(shiftValue, 64, 90);

  }

  // Checks if the character is lower case using ASCII table values
  else if (c <= 122 && c > 96) {
  
  // Provides the function with the user input + the start and end of the 
  // alphabet values
  return shiftLetter(shiftValue, 96, 122);

  }

  //If it's not part of the alphabet it will return the original input
  else {
    
    return c;

  }
  
}

int main(int argc, char *argv[]) {
  
  // Turns the program argument in to an int
  int argument = atoi(argv[1]); 
  
  //Infinite loop until user decides to end program
  while(1) {

    // Takes in the users message they want encrypted
    printf("Type the word you want encrypted\n");
    char userInput[MAX];
    scanf("%s", userInput);

    // Replaces the original message with the new encrypted one
    // 1 character at a time.
    // Uses the MAX value to end the loop to make sure it never loops
    // more than the maximum amount of characters allowed in the array
    for (int i = 0; i < MAX; i++) {
      userInput[i] = encrypt(userInput[i], argument);
    }
    // Prints out the new message
    printf("Result of encryption:\n");
    printf("%s\n", userInput);

  }
  
  return 0;
}

