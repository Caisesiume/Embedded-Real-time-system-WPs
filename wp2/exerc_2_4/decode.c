//Submission code 53Tuesday
#include <stdio.h>
#include <stdlib.h>


// ##### Function declarations   #####

int decode(unsigned char hex); // function to be used to decode the users input

//###### Main program #######

int main(int argc, char *argv[])
{
    // Condition for making sure the user inputs no less or more than 2 arguments
    if (argc == 2)
    {
        // Retriving the hexadecimal value inputed by the user
        char *hexavalue_input = argv[1];
        // Converting data type of the input to long
        // and setting it as equal to the hexavalue variable
        int hexavalue = strtol(hexavalue_input, NULL, 16);
        // Calling the fuction to decode the hexadecimal as integers
        decode(hexavalue);
    }
    // Condition for if user inputs to many or to few arguments
    else
    {
        // Printing an error message for the user
        printf("Arguments Input Incorrect or absent\n");
    }
    return 0;
}
// ====     End of main   ======================================

// ##### Function definitions   #####

int decode(unsigned char hexavalue)
{
    // Intializing all our variables
    int engine_on = 0;
    int gear_pos = 0;
    int key_pos = 0;
    int brake1 = 0;
    int brake2 = 0;

    // Starting the decoding of the hexadecimal with input for the first position
    // which is engine_on by shifting hexavalue right 7 times to retrieve it
    engine_on = hexavalue >> 7;
    // Shifting hexavalue to the left once to remove engine_on
    hexavalue = hexavalue << 1;
    
    // Next retrieving the value of the input for gear_pos by shifting the
    // hexavalue left 5 times then setting value of gear_pos to it
    gear_pos = hexavalue >> 5;
    // Shifting hexavalue to the left three times to remove gear_pos
    hexavalue = hexavalue << 3;
    
    // Then retrieving the value of input given to key position by shifting the
    // hexavalue left 6 times then setting value of key_pos to it
    key_pos = hexavalue >> 6;
    // Shifting hexavalue to the left twice to remove key_pos
    hexavalue = hexavalue << 2;
    
    // Then retrieving the value of input given to brake 1 by shifting the
    // hexavalue left 7 times then setting value of brake1 to it
    brake1 = hexavalue >> 7;
    // Shifting hexavalue to the left once to remove brake1
    hexavalue = hexavalue << 1;
    
    // Lastly retrieving the value of input given to brake2 by shifting the
    // hexavalue left 7 times again then setting value of brake2 to it
    brake2 = hexavalue >> 7;

    // Printing out the final result

    printf("Name                Value\n");
    printf("------------------------------\n");
    printf("engine_on   %d \n", engine_on);
    printf("gear_pos    %d \n", gear_pos);
    printf("key_pos     %d \n", key_pos);
    printf("brake1      %d \n", brake1);
    printf("brake2      %d \n", brake2);

    return 0;
}