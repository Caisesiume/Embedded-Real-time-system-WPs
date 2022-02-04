#include<stdio.h>
#include<stdbool.h>

#define MAX 20

// Provides the menu for the program and asks the user which functions
// They want to use and directs them there
void menu();

void menu() {
    
    bool exit = false;
    int choice;

    while(!exit) {
        
        printf("Please Select one of the following options!\n");
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file. \n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");
    
        scanf("%d", &choice);

        if(choice == 5) {

            printf("Bye Bye\n");
            exit = true;
        }

    }
}

int main() {

    menu();
    return 0;
}