#include <stdio.h>
#include <stdbool.h>
int main()
{
    
    // Variable declaration
    int chosenNumber;
    bool exit = false;
    
    //Continous loop until the user inputs anything but 1-5
    while (!exit) {
    printf("Please chose a number between 1-5:\n");
    scanf("%d", &chosenNumber);
    if(chosenNumber >0 && chosenNumber < 6){
        printf("This is sentence number %d \n",chosenNumber );
    }
    else {
        //closes the loop
        exit = true;
    }
    }
    return 0;
}