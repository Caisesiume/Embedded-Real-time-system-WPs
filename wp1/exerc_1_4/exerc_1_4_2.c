
#include <stdlib.h>
#include <stdio.h>

int main(int argc, int* argv[]) {

    int binary_number = argv[1];
    printf("Input Binary value: %s\n",binary_number);
    long int hexadecimal_number;

    // The output from the other program needs to be used as program argument. 
    // something like int binary_value = argv[1];

    // converts binary_value to hex_value
    // The conversion can be done by checking:
    // If the input is not zero, then check how many zeros are followed by the first one.
    // For that I believe the use of modulus 10 is the key. 
    // Each set of 4 number is represented by either a number of a letter A-F.
    
    // %lX used to print the number in hexadecimal format.
    // Should not be 'argv[1]'
    
    printf("The Hexadecimal Value: %lX", hexadecimal_number);
    return 0;
}