//Submission code 53Tuesday

// ---- CONCEPTUAL IMPLEMENTATION ----
// Implement the positioning with struct.
// The input needs to be in a loops, taking 2 different type of inputs.
// Takes user input for start position.
// Start direction is always north.
// (x, y)
// Needs to be in the range of 0-99.

// move() uses pointer params for the robot to update position which is a variable in the main function (calling function). 
// both move() and turn() should be void functions

// Needs one input string with the movement pattern. Max 100 characters as specified in the assignment.
// Loop over the char array, until the dedicated stop char is found (s).
// m = Move on step in current direction
// t = Turn 90 degrees clockwise
// s = Stop, the program stops.
// NOTE: Lowercase!

// When looping the input char array is done, print the current position (coords).
// If no end char found (no 's'),
// ask for new starting position as well as an input string consisting of m, t and s.
// This step repeats until the input string (char array) contains a 's'.

#include <stdio.h>
#include <string.h>

#define MAX 100 // Highest value allowed on the grid system (both x & y)

#define MIN 0 // Lowest value allowed on the grid system (both x & y)

#define STOP 0 // Stop variable for the overhauling loop.

#define MOVE 'm' // defined char for moving forward.

#define TURN 't' // defined char for turning.

#define END 's' // defined char for quitting the program.

// Decides which direction the robot will walk in
enum DIRECTION {N, O, S, W};

typedef struct ROBOT{ 
    int xpos;
    int ypos;
    enum DIRECTION dir;

} ROBOT;


// Function to move the robot 1 step forward
// Params are points in order to change the actual value from this function.
void move(int *x_pos, int *y_pos, enum DIRECTION *dir) {
    // Switches depending on the current direction (*dir)
    // Add/Subtract 1 to move the robot in the correct direction
    switch (*dir) 
    {
    case N:
        // Check that the robot is within the limits of the grid (0-99)
        if (*y_pos < MAX)
        {
            // Moving one step towards North (N) equals +1 on 
            // the Y-axis when looking at a grid.
            *y_pos = *y_pos + 1;
        }
        break;

    case O:
        // Check that the robot is within the limits of the grid (0-99)
        if (*x_pos < MAX)
        {
            // Moving one step towards East (O) equals+1 on 
            // the X-axis when looking at a grid.
            *x_pos = *x_pos + 1;
        }
        break;
    
    case S:
        // Check that the robot is within the limits of the grid (0-99)
        if (*y_pos > MIN)
        {
            // Moving one step towards South (S) equals -1 on 
            // the Y-axis when looking at a grid.
            *y_pos = *y_pos - 1;
        }
        break;

    case W:
        // Check that the robot is within the limits of the grid (0-99)
        if (*x_pos > MIN)
        {
            // Moving one step towards West (W) equals -1 on 
            // the X-axis when looking at a grid.
            *x_pos= *x_pos - 1;
        }
        break;

    default:
        printf("Something went wrong when moving, check if the robot is stuck");
        break;
    }
}
// Function to turn the robot 90 degrees clockwise.
// Needs the robots current direction, provided by using pointer in args.
void turn(enum DIRECTION *current_dir) {
    // We only need to set the value to 0 if the enum is 3
    // since we have 4 directions.
    // 0 = N, 1 = O, 2 = S, 3 = W.
    if (*current_dir == W)
    {
        *current_dir = N;
    }
    else
    {
        // This part will only be executed if the provided direction is W / 3
        // Setting it to 0 will turn the direction 90 degrees from W to N.
        *current_dir = *current_dir + 1;
    }
};

int main(void) {

    struct ROBOT bot;  //Declares the robot in the main function.
    int stop_sign = 1; // If this is set to 0, will be equal STOP.
    int x_input, y_input; // Stores the values of the starting position input.
    char movement_pattern[MAX]; // Stores the input string of the expected movement.
    while (stop_sign != STOP)
    {
        //The loop needs to run at least once for the users to give input
        //of the starting positions.

        bot.dir = N; // Sets the initial direction to north before computing the movement pattern.

        // --- GETTING START POSITION X-AXIS ---
        // loop to make sure the x-axis input is valid number 0-99
        // X - Axis input
        do
        {
            printf("Enter starting position for X-Axis (0-99): \n");
            scanf("%d", &x_input);
            //Checks if the input value is valid (Between 0 - 99)
            if (x_input < MAX || x_input >= MIN)
            {
                // Assigns the value of the temp variable to the x coordinate 
                // of the robot, only if the condition 3 rows above is fulfilled. 
                bot.xpos = x_input; 
            }
        // Keeps asking for a correct input until a numberr within 
        // the interval 0-99 is provided.
        } while (x_input > MAX || x_input < MIN); 
        

        // --- GETTING START POSITION Y-AXIS ---
        // loop to make sure the y-axis input is valid number 0-99
        do
        {
            printf("Enter starting position for Y-Axis (0-99): \n");
            scanf("%d", &y_input);

            //Checks if the input value is valid (Between 0 - 99)
            if (y_input < MAX || y_input >= MIN)
            {
                bot.ypos = y_input;
            }
        // Keeps asking for a correct input until a number within 
        // the allowed interval (0-99) has been provided.
        } while (y_input > MAX || y_input < MIN);


        // Will keep iterating until a movement pattern with < 100 instructions is provided.
        do
        {
            // For readability - Prints following: 
            // Enter the movement pattern you want the robot to follow (Max 100 instructions). \n
            // NOTE: Starting direction is North (N)\n
            // m - move in the current direction \n
            // t - turn 90deg clockwise \n
            // s - Include this character to exit the program immediately\n
            // (E.g. mtmmmtttmtm)\n

            // Lets user input the movement pattern for the robot.
            
            printf("Enter the movement pattern you want the robot to follow (Max 100 instructions). \n NOTE: Starting direction is North (N)\n m - move in the current direction \n t - turn 90deg clockwise \n s - Include this character to completely exit the program\n (E.g. mtmmmtttmtm)\n");
            scanf("%s", movement_pattern);

            // If a string longer than MAX (100) is provided, ask for a new one.
            // Then, a new iteration will be triggered.
        } while (strlen(movement_pattern) > MAX); 

        int len = strlen(movement_pattern); // Gets the amount of steps the movement_pattern include.
        // Loops through all instructions in the provided movement_pattern.
        for (int i = 0; i < len; i++)
        {
            // Stores the active char. Saves the new char at start of each iteration.
            char current_char = movement_pattern[i]; 
            switch (current_char)
            {
            case MOVE: // Moves the robot one step.
                // bot.xpos - X-Axis position
                // bot.ypos - Y-Axis position
                // bot.dir - Currently facing direction.
                move(&bot.xpos, &bot.ypos, &bot.dir);
                break;

            case TURN: // Turns the robots currently facing direction 90 degrees clockwise.
                // bot.dir - Currently facing direction.
                turn(&bot.dir);
                break;

            case END:
                // If 's' is included in the input string
                // the loop will not continue iterating after
                // current iteration is over.
                stop_sign = 0;
                break;

            default:
                // The only time this is executed is if the movement pattern includes invalid characters
                // which do not have a predefined meaning.
                printf("The provided movement pattern includes invalid characters\n");
                break;
            }
        }
        
        // Prints the result of the movement pattern given.
        // Result is provided in the form of updated coordinates.
        printf("Robot stopped at x:%d y:%d \n", bot.xpos, bot.ypos);
    }
    return 0;
}