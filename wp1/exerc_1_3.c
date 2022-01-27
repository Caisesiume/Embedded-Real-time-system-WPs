#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int guessGame(int randomNumber,int chosenNumber,int numberOfChances,int answer);
int main ()  
{ 
  int rNum;
  int cNum;
  int chances;
  int playAgain;
 // printf ("The random Number is : %d\n", randomNumber);
  printf("Please guess a number between 1-100:\n");
  scanf("%d", &cNum);
    while(cNum >100 || cNum < 1){
    printf("Please guess a number between 1-100:\n");
    scanf("%d", &cNum);
  }
    guessGame(rNum,cNum,chances,playAgain); 
  return 0;
}

int guessGame(int randomNumber,int chosenNumber,int numberOfChances,int answer) {
  while(1){ 
  srand ( time(NULL) );
  int randomNumber = rand() %( 100 + 1- 1 ) ;
  int chosenNumber;
  int numberOfChances = 0;
  int answer;
  while( numberOfChances <2 && chosenNumber != randomNumber ){     
    if ( chosenNumber > randomNumber){
      numberOfChances ++;
      printf("You guessed too high and have guessed %d times\n ", numberOfChances); 
      printf("Please guess a number between 1-100 again :\n");
      scanf("%d", &chosenNumber);
     }

    else if ( chosenNumber < randomNumber){
      numberOfChances ++;
      printf("You guessed too low and have guessed %d times\n ", numberOfChances);
      printf("Please guess a number between 1-100 again:\n"); 
      scanf("%d", &chosenNumber);
      }
  }

  if ( chosenNumber == randomNumber){
      numberOfChances ++;
      printf("You guessed correctly and have guessed %d times\n ", numberOfChances); 
      return 0;
  }
  
  printf("Do you want to play another round?\n Type 1 for Yes and 2 for No\n");
  scanf("%d", &answer);
  if(answer != 1){
      return 0;
   }
 }
}