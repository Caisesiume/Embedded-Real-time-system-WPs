#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NUMBER 2 // Defining the number of chances a user has

// ------ Function declarations   ----------

// This function used to start playing the game
int guessGame();

// ------ Function definitions   ---------- 


// Calling the function for the game to start
int guessGame()
{
  // Makes sure the random number selected in each round changes
  srand(time(NULL));
  // Declaring random number and stating the minimum and max numbers to randomize between
  // Formula is rand() % (max_number + 1 - minimum_number) + minimum_number
  int randomNumber = rand() % (100 + 1 - 1) + 1;
  // Initializing variable to take in the number chosen by the user
  int chosenNumber;
  // Number of tries the user makes
  int i;
  // Variable used to inspect whether user inputted a character
  int charinput;
  // Message printed to user introducing the game and how many tries the user has
  printf("Welcome to the guess game! A number has been chosen between 1-100.");
  printf("You have %d chances!\n", MAX_NUMBER);

  // Loop starting the game and i is initialized at 0 to number of tries user has - 1
  for (i = 0; i < MAX_NUMBER; i++)
  {
    // Once the round starts the user should see the message to enter a number between 1-100
    printf("Please enter your guess between 1-100:\n");

    // This loop checks for if the user has inputted a character
    // if the scan results in a 0 or false this loop will be entered until
    // the scanner finds an integer or results in 1 or true
    while (scanf("%d", &chosenNumber) != 1)
    {
      // If the input entered has no spaces the loop should be entered
      // getchar() should retrieve the input and convert it to integers
      while (!isspace(charinput = getchar()))
        ;
      // This function should but the integer created back into the input stream
      ungetc(charinput, stdin);
      // Message letting the user know to enter a valid number
      printf("You must enter a valid number. Try again:\n");
      // Forcing the next loop to start after this one
      continue;
    }
    // If the user input was a number over 100 or less than 1
    // it should not count as a round and should instead let user to try guessing
    // with a valid number between 1-100
    if (chosenNumber > 100 || chosenNumber < 1)
    {
      i--;
      printf("Invalid Number, try again with a number between 1-100:\n");
    }
    // If the user guessed the right number the should a message
    // telling them they chose the right number and how many tries it took
    else if (chosenNumber == randomNumber)
    {
      printf("You guessed correctly and have guessed %d times\n ", MAX_NUMBER);
      break;
    }
    // If the user inputted a number greater than the random number
    // the user should see a message telling the number was too high
    else if (chosenNumber > randomNumber)
    {
      printf("You guessed too high\n");
    }
    // If the user inputted a number lesser than the random number
    // the user should see a message telling the number was too low
    else if (chosenNumber < randomNumber)
    {
      printf("You guessed too low \n");
    }
  }
  // If the tries are all used up the user should a message saying game is over
  if (i == MAX_NUMBER)
  {
    printf("Game Over\n");
  }
  // The the game should end at this point
  return 0;
}


// ------ Main   -------------------------- 

int main()
{
  // Variable to store users answer to play again
  int answer;
  // Continous loop to play the game until user inputs the number 2
  while (1)
  {
    // Calling the function to start the game
    guessGame();
    // Printing the question to play again once game is over or player wins the game
    printf("Do you want to play another round? Type 1 for Yes and 2 for No\n");
    // Scanning the inputs answer to play again
    scanf("%d", &answer);
    // Condition for if the users answer is 2 to end the game
    if (answer == 2)
    {
      return 0;
    }
  }
  return 0;
}

