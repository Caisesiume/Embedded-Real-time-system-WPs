// ---- CONCEPTUAL IMPLEMENTATION ----
// Implement the positioning with struct.
// The input needs to be looped taking 2 different type of inputs.
// Takes user input for start position.
// Start direction is always north.
// (x, y)
// Needs to be in the range of 0-99.

// move() uses pointer params for the robot to update position which is a variable in the main function (calling function). 
// both move() and turn() should be void functions

// Needs one input string. Loop over the char array, until the dedicated stop char is found (s).
// M = Move on step in current direction
// T = Turn 90 degrees clockwise
// S = Stop, the program stops.

// When looping the input char array is done, print the current position (coords).
// If no end char found, 
//  ask for new starting position as well as an input string consisting of M, T and S.
// This step repeats until the input string (char array) contains a S.

#include <stdio.h>

#define MAX 100

// Function to move the robot 1 step forward
void move(char *input);
// Function to turn the robot 1 step clockwise
void turn(char *input);

// Decides which direction the robot will walk in
enum DIRECTION (N, O, S, W);

typedef struct { 
    int xpos;
    int ypos;
    enum DIRECTION dir;

} ROBOT;

int main(void) {

    return 0;
}