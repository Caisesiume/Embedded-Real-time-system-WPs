#include <stdio.h>
#include <stdlib.h>

#define MAX 100


// Checks if the letter is upper or lowercase,
// 90 is the last upper case letter in the ASCII table 
// Returns the mid point in the alphabet of either lower case or upper case characters



// shifts the char with either +13 or -13 points in the ascii table depending on its position in the alphabet
// caseCheck determines the value to use depending on the case of the character
char shiftLetter(char c, int shiftValue) {


  if (c <= 90 && c >= 65 ) {


  if (c + shiftValue > 90) {
    return 64 + (c + shiftValue - 90);
  }

  else {

    return c + shiftValue;
  }
  }

  else if (c <= 122 && c >= 97) {

  if (c + shiftValue > 122) {
    
   return 96 + (c + shiftValue - 122);



  }
  

  else {
    return c + shiftValue;
  }

  }

  else {
    
    return c;

  }
  
}

int main(int argc, char *argv[]) {
  
  //Infinite loop until user decides to end program
  int argument = atoi(argv[1]); 
  
  while(1) {

    // Converts the program argument to an int and then puts that value as the maximum
    // amount of characters that will be taken from the user and shifted.
    char userInput[MAX];
    printf("Type the word you want encrypted\n");
    scanf("%s", userInput);

    // Calls the function to shift the letters
    for (int i = 0; i < MAX; i++) {
      userInput[i] = shiftLetter(userInput[i], argument);
    }
    // Prints the result + limits the amount of characters to be printed in accordance with the program argument.
    printf("Result of encryption:\n");
    printf("%s\n", userInput);

  }
  
  return 0;
}

