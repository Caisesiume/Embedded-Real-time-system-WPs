#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
  //while loop to continue the game until exited by the user
  while (1)
  {
    //make sure random number changes in a new round
    // chosen number , number selected by user
    // answer , response given by user to continue or leave the game
   
    srand(time(NULL));
    int randomNumber = rand() % (100 + 1 - 1);
    int chosenNumber;
    int numberOfChances = 0;
    int answer;
    int charinput;
    //printf ("The random Number is : %d\n", randomNumber);
    // asking user to input value
    printf("Please enter a number between 1-100:\n");
    //check if user inputted a char
    while (scanf("%d", &chosenNumber) != 1)
    {
      while (!isspace(charinput = getchar()));
      ungetc(charinput, stdin);
      printf("You must enter a valid number. Try again.\n");
      continue;
    }
    // make sure user only inputs numbers betwee 1-100
    while ((chosenNumber > 100 || chosenNumber < 1))
    {
      printf("Try again with a number between 1-100:\n");
      scanf("%d", &chosenNumber);
    }

    // continue loop aslong as user inputs wrong number and still has chances
    while (numberOfChances <= 2 && chosenNumber != randomNumber)
    {
      numberOfChances++;
      if (chosenNumber > randomNumber)
      {
        printf("You guessed too high\n");
      }

      if (chosenNumber < randomNumber)
      {
        printf("You guessed too low \n");
      }
      if (numberOfChances != 0 && numberOfChances <= 2)
      {
        printf("Try Again:");
        scanf("%d", &chosenNumber);
      }
      while ((chosenNumber > 100 || chosenNumber < 1))
      {
        printf("Try again with a number between 1-100:\n");
        scanf("%d", &chosenNumber);
      }
    }
   
    // if user input right answer finish the game 
    // and tell the how many time they had to guess
      if (chosenNumber == randomNumber)
      {
        numberOfChances++;
        printf("You guessed correctly and have guessed %d times\n ", numberOfChances);
      }
    
    // tell the user game is over and ask if they want to play again  
    printf("Game Over\n");
    printf("Do you want to play another round?\n Type 1 for Yes and 2 for No\n");
    scanf("%d", &answer);
    
    // user doesnot want to play again end game
    if (answer == 2)
    {
      return 0;
    }
  }
  return 0;
}