#include <stdio.h>

#define MAX 100

// Function to move the robot 1 step forward
void move(char *input);
// Function to turn the robot 1 step clockwise
void turn(char *input);

// Decides which direction the robot will walk in
enum DIRECTION (N, O, S, W);

typedef struct ( 
    int xpos;
    int ypos;
    enum DIRECTION dir;

) ROBOT;

int main(void) {

    return 0;
}