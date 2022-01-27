
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    unsigned int hexadecimal_number = 0;
    unsigned int binary_number = 0;
    // scanf("%d", binary_number); // Leaving this scanf uncommented gives segmentation fault.
    // Print should print both Binary and Hexa
    printf("Input Binary value: %d\n",binary_number);
    int remainder;
    int i = 1;

    // Loops until the remaining number is 0. 
    // That way, the translation of the binary number is done correctly.
    // The algorithm of translating binary into hexadecimals was inspired by
    // Link: ()
    while (binary_number != 0)
    {
        remainder = binary_number % 10; 
        hexadecimal_number = hexadecimal_number + remainder * i;
        i = i*2;
        binary_number = binary_number / 10;
    }

    // Use capital X to get capital letters in Hex code
    printf("Hexa format: %X", hexadecimal_number);
    
    // The output from the other program needs to be used as program argument. 
    // something like int binary_value = argv[1];

    // --- CONCEPT ---
    // converts binary_value to hex_value
    // The conversion can be done by checking:
    // If the input is not zero, then check how many zeros are followed by the first one.
    // For that I believe the use of modulus 10 is the key. 
    // Each set of 4 number is represented by either a number of a letter A-F.
    
    // %lX used to print the number in hexadecimal format.
    // Should not be 'argv[1]'
    
    // 1010 0111 = A7 = 167
    //  A   4+2+1
    return 0;
}