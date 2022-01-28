#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char shiftLetter(int shiftValue, int startOfAlphabet, int endOfAlphabet) {

  if (shiftValue > endOfAlphabet) {

    return startOfAlphabet + (shiftValue - endOfAlphabet);
  }

  else {

    return shiftValue;
  }
}
// Function to encrypt the input from the user
char encrypt(char c, int argument) {
 
  char shiftValue = c + argument;
  // Checks if the character is upper case using ASCII table values
  if (c <= 90 && c > 64 ) {

  return shiftLetter(shiftValue, 64, 90);

  }

  else if (c <= 122 && c > 96) {
  
  return shiftLetter(shiftValue, 96, 122);

  }

  else {
    
    return c;

  }
  
}

int main(int argc, char *argv[]) {
  
  int argument = atoi(argv[1]); 
  
  //Infinite loop until user decides to end program
  while(1) {

    
    printf("Type the word you want encrypted\n");
    char userInput[MAX];
    scanf("%s", userInput);

    for (int i = 0; i < MAX; i++) {
      userInput[i] = encrypt(userInput[i], argument);
    }
    printf("Result of encryption:\n");
    printf("%s\n", userInput);

  }
  
  return 0;
}

