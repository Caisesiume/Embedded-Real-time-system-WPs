// Converts the decimal number into a binary
// Could probably be done in a recursive way where you divide by 2 if the input is more than 1
// and call the same function again.
// If input is not > 1, print the fouth number in the binary number, then the 3rd, 2nd and 1st (if only 4 bits).
// calculate_binary(number_short);

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Imports all max values of different data types
#include <limits.h>


// Recursive function that prints one digit at a time.
// Works like following. Takes the input number and divides by 2,
// call the same function again with the result from the division.
void calculate_binary(unsigned input_value)
{
    // If the input value is not 1 or 0
    if (input_value > 1)
    {
        // Calls this function again (recusive call) until the number is either a 1 or a 0.
        // If the number is NOT 1 or 0, this code will be run.
        calculate_binary(input_value / 2);
    }

    int number = input_value % 2;
    printf("%d", number);
}

int main(int argc, char *argv[])
{
    // Fail safe to check that one argument is given. 
    // argc will always be one, with the one being the running file.
    if (argc > 1) 
    {
        long full_number;
        char *arg1 = argv[1];
        char *help = "-h";
        short number_short;
        int number_int;
        long number_long;

        // strncmp used to compare if the first argument matches the second one.
        // The last argument (3) indicates how many of the first chars from the previous two args to compare.
        // They the two arguments match, the function will return 0. 
        // Which means the argument provided was "-h".
        // Otherwise, the binary conversion will happen.
        int result = strncmp(arg1, help,3);
        if (result == 0)
        {
            printf("Help - How to use:\n Run the file in the terminal and provide one number as an argument\n file.exe <value>");
        }
        else
        {
            // Converts the given arguement to a number.
            // Needs to be converted in order for the conditional statement comparisions to work
            // and the casting to be done correctly.
            full_number = atoi(arg1);

            // Conditional statements checking what data type suits the best for the argument.
            // If possible, cast the arg to a data type of lower size.
            // Use that variable as argument for the calculate_binary function.
            if (full_number < SHRT_MAX)
            { //included from limits.h | SHRT_MAX = 32 767
                number_short = (short)(full_number);
                calculate_binary(number_short);
            }
            else if (full_number < INT_MAX)
            { //included from limits.h | INT_MAX = 2 147 483 647
                number_int = (int)(full_number);
                calculate_binary(number_int);
            }
            else //If the number is big in size and can't be stored in an int.
            {
                number_long = (long)(full_number);
                calculate_binary(number_short);
            }
        }
    }
    else
    {   
        printf("No arguments provided");
        return 2;
    }
    
    return 0;
}