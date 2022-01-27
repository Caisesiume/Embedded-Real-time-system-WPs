#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define CHANCES 2 // NUMBER OF CHANCES USER HAS

int guessGame();

int main()
{

  int answer;
  while (1)
  {
    guessGame();
    printf("Do you want to play another round? \n Type 1 for Yes and 2 for No\n");
    scanf("%d", &answer);
    if (answer == 2)
    {
      return 0;
    }
  }
  return 0;
}

int guessGame()
{
  srand(time(NULL));
  int randomNumber = rand() % (100 + 1 - 1);
  int chosenNumber;
  int i; //number of tries
  int charinput;
  printf("Welcome to the guess game! A number has been guessed between.");
  printf("You have %d chances!\n", CHANCES);

  for (i = 0; i < CHANCES; i++)
  {
    printf("Please enter you guess between 1-100:");

    while (scanf("%d", &chosenNumber) != 1)
    {
      while (!isspace(charinput = getchar()))
        ;
      ungetc(charinput, stdin);
      printf("You must enter a valid number. Try again.\n");
      continue;
    }
    if ((chosenNumber > 100 || chosenNumber < 1 || isalpha(chosenNumber) != 0))
    {
      i--;
      printf("Invalid Number, try again:\n");
    }
    else if (chosenNumber == randomNumber)
    {
      printf("You guessed correctly and have guessed %d times\n ", CHANCES);
      break;
    }
    else if (chosenNumber > randomNumber && i != CHANCES - 1)
    {
      printf("You guessed too high\n");
    }
    else if (chosenNumber < randomNumber && i != CHANCES - 1)
    {
      printf("You guessed too low \n");
    }
  }
  if (i == CHANCES)
  {
    printf("Game Over\n");
  }
  return 0;
}