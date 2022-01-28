// Program works in combination with exerc_1_4.c
// This program looks for stdin of a binary number to convert to hexadecimal format.
// Program should be executed in a pipeline:
// ./exerc_1_4.exe <decimal_number> | ./exerc_1_4_2.exe 

// --- CONCEPTUAL IMPLEMENTATION ---
// Converts binary_number to hexadecimal_number
// The conversion is done by checking:
// Use binary_number, get the remainder of the modulus calculation and 
// multiply that remainder with i. i will be incremnted by * 2 each increment of the loop.
// As the loop only takes one digit into consideration at a time, we need to change binary_number
// after each increment so it's correctly structured for the upcoming increment. This is done by dividing by 10.
// These steps are repeated until everything everything in binary_number has been removed. Until binary_number == 10

// When the loop is done the number stored in the hexadecimal_number variable will be a decimal number.
// It is simply printed as a hexadecimal number by using
// %lX to print the number in hexadecimal format.
    
// ---- EXPLAINATION OF CONVERSION ----
// 1010 0111 = 167 = A7
//  A   4+2+1

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    unsigned int hexadecimal_number = 0; // If there is no input, this value will stay 0.
    unsigned int binary_number = 0; //If there is no input, this value will stay 0.
    unsigned int n;
    // Print should print both Binary and Hexa
    // scanf takes care of the input (stdin), which under the right conditions is
    // the output (stdout) from the previous program, exerc_1_4
    // This scanf only accepts numbers, char will be treated as 0, the initial value of the variable.
    scanf("%d", &binary_number);
    // Prints the binary number before converting to hexadecimal.
    if (binary_number > 0)
    {
        printf("%d\n", binary_number);
        int remainder;
        int i = 1;

        // Loops until the remaining binary number is 0. 
        // That way, the translation of the binary number is done correctly.
        // The algorithm of translating binary into hexadecimals was inspired by
        // Link: (https://www.sitesbay.com/program/c-program-convert-binary-to-hexadecimal)
        //
        // A in detail explaination of the loop is made at the top of this file.
        while (binary_number != 0)
        {
            remainder = binary_number % 10; 
            hexadecimal_number = hexadecimal_number + remainder * i;
            i = i*2;
            binary_number = binary_number / 10;
        }
    }

    // If there is no number to convert, we simply don't convert anything.
    // Just print an explaination about there not being a convertable number.
    if (hexadecimal_number == 0)
    {
        // Prints help. hexadecimal_number = 0 means the conversion from binary_number did not take place.
        // From that we can assume the argument was not formed in a correct way.
        // Therefore we provide both help on how to run the two programs and the provide reason for the program exit.
        printf("Help with how to use:\n Run the file in the terminal and provide one number as an argument. $ file.exe <value> | file2.exe\n");
        printf("A valid binary number was not found. Program exiting.\n");
        return 2; // Program exits with code=2 when the conversion was unsuccessful.
    }
    else
    {
        // Use capital X to get capital letters in Hex code
        // hexadecimal_number can also be printed as a decimal number.
        // Using %X we print the number in hexadecimal format instead, letting us
        // have not only the digits '0' - '9', but also 'A' - 'F'.
        printf("%X", hexadecimal_number);
        return 0;
    }
}