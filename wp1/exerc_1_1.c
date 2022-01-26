#include <stdio.h>
#include <stdbool.h>
int main()
{
    int chosenNumber;
    bool exit = false;
    while (!exit) {
    printf("Please chose a number between 1-5:\n");
    scanf("%d", &chosenNumber);
    if(chosenNumber >0 && chosenNumber < 6){
        printf("This is sentence number %d \n",chosenNumber );
    }
    else {
        exit = true;
    }
    }
    return 0;
}