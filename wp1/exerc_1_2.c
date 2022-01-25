#include <stdio.h>
#include <stdlib.h>


// Checks if the letter is upper or lowercase,
// 90 is the last upper case letter in the ASCII table 
// Returns the mid point in the alphabet of either lower case or upper case characters
int caseCheck(char c) {

  int upperCaseMidPoint = 78;
  int lowerCaseMidPoint = 110;
   
    if (c < 91) {
      return upperCaseMidPoint;
    }
      return lowerCaseMidPoint;
}

// shifts the char with either +13 or -13 points in the ascii table depending on its position in the alphabet
// caseCheck determines the value to use depending on the case of the character
// maxSize is determined by the command line argument
char shiftLetter(char c, int maxSize) {

    for (int i = 0; i < maxSize; i++) {
      if (c < caseCheck(c)) {
        return c + 13;
      }
      else if (c >= 78)
        return c - 13;
      }
  }

int main(int argc, char *argv[]) {

// Converts the command line argument to an int and then puts that value as the maximum
// amount of characters that will be taken from the user and shifted.
int argument = atoi(argv[1]); 
char userInput[argument];
scanf ("%s", userInput);

// Calls the function to shift the letters with the input from the user
for (int i = 0; i < argument; i++) {
  userInput[i] = shiftLetter(userInput[i], argument);
}
// Prints the result + limits the amount of characters to be printed in accordance with the command line argument.
printf("%.*s\n", argument, userInput);

  return 0;
}

