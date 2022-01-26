
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    printf("The number is %d\n", argv[1]);
    // Allocates enough memory for the imput value
    // What should happen:
    // If a user inputs 12 the program should allocate 8 bits. 
    // If the user inputs 1200, then the output should be 16 bits. 
    int input_number = (int*)malloc(sizeof(argv[1]));
    // Not sure if this is correct?


    // Just to check if the input is read correct
    printf("The number is %s\n", input_number);
    
    // Converts the decimal number into a binary
    // Could probably be done in a recursive way where you divide by 2 if the input is more than 1
    // and call the same function again. 
    // If input is not > 1, print the fouth number in the binary number, then the 3rd, 2nd and 1st (if only 4 bits).


    return 0;
}