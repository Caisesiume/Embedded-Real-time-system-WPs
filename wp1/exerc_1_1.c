//Tuesday1

#include <stdio.h>
#include <stdbool.h>
int main()
{
    // Variable declaration for both the inputted value 
    // and boolean to continue the game or not
    int chosenNumber;
    bool exit = false;

    // Continous loop until the user inputs anything but 1-5
    while (!exit)
    {
        // Message instructing user to enter a number between 1-5
        printf("Please chose a number between 1-5:\n");
        // Scan to read users input
        scanf("%d", &chosenNumber);

        // Condition if the user inputs the number 1
        // Prints out the sentence intended
        if (chosenNumber == 1)
        {
            printf("The mother read a story to her son.\n");
        }
        // Condition if the user inputs the number 2
        // Prints out the sentence intended
        else if (chosenNumber == 2)
        {
            printf("Tom made a big donation to the hospital.\n");
        }
        // Condition if the user inputs the number 3
        // Prints out the sentence intended
        else if (chosenNumber == 3)
        {
            printf("Diamonds are forever.\n");
        }
        // Condition if the user inputs the number 4
        // Prints out the sentence intended
        else if (chosenNumber == 4)
        {
            printf("She had a dice with over twenty sides.\n");
        }
        // Condition if the user inputs the number 5
        // Prints out the sentence intended
        else if (chosenNumber == 5)
        {
            printf("The horse raced past the barn and fell.\n");
        }
        // If the user inputs any number outside of numbers between 1-5 
        // the program will end
        else
        {
            //closes the loop
            exit = true;
        }
    }
    return 0;
}