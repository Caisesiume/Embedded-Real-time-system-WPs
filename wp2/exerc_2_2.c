#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5

// ##### typedefs          ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations   #####

REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);

//###### Main program #######
int main(int argc, char *argv[])
{
    // Variable for position we are in the list
    int nr = 0;

    // Head and node pointers for the list
    REGTYPE *act_post, *head = NULL;
    srand(time(0)); //   Random seed
    head = random_list();
    // Inserting a node to the beginning of the list
    head = add_first(head, 64);
    act_post = head;
    // Printing Out the values and position of each node in the list
    // while the condition is the node exists
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    // --- Free the allocated memory  ---

    // Loop to free up space while the condition is that the node exists
    while ((act_post = head) != NULL)
    {
        // Setting head to next node to traverse the list
        head = act_post->next;
        // Function called to free up the space
        free(act_post);
    }

    return 0;
}

// ====     End of main   ======================================

// ##### Function definitions   #####

REGTYPE *random_list(void)
{
    // Variable for the value of the node and
    // number of loops i the for loop will make
    int nr, i = 0;
    nr = rand() % 100;
    // Initializing the three pointers needed to traverse and fill the doubly linked list
    REGTYPE *top, *old, *item;
    //Making sure number of nodes required to be in the linked list is more than or equal to 1
    if (MAX >= 1)
    {
        // Allocating the required memory space for the head node
        top = (struct q *)malloc(sizeof(REGTYPE));
        // Condition to make sure top node exists and has be allocated memory
        if (top != NULL)
        {
            // Setting top value to a random number and previous and next of top to null
            // since top is our first node in the list
            top->number = nr;
            top->prev = NULL;
            top->next = NULL;
            // Assign top node of the list as last node
            old = top;
            // Putting data for rest of the nodes in the list
            // We start i from 1 since the first node is our top node
            for (i = 1; i < MAX; i++)
            {
                // Allocating the required memory space for our pointer
                item = (struct q *)malloc(sizeof(REGTYPE));
                // Creating our random number for the value of our node
                nr = rand() % 100;
                // Condition to make sure item node exists and memory has be allocated
                if (item != NULL)
                {
                    // Setting the value of our node to a random number
                    item->number = nr;
                    // new node is linking with the previous node
                    item->prev = old;
                    // Since item node is the last in the list next will be null
                    item->next = NULL;
                    // Previous node is linking with the new node
                    old->next = item;
                    // Assign new node as last node
                    old = item;
                }
                // Condition for if the item node had not been allocated with suffient or any memory
                else
                {
                    // Error Message to print to the user
                    printf(" Memory can not be allocated.");
                    // End the lopp
                    break;
                }
            }
        }
        // Condition for if the top node had not been allocated with suffient or any memory
        else
        {
            // Error Message to print to the user
            printf(" Memory can not be allocated.");
        }
    }
    // Returning the head of the list
    return (top);
}

//==========================================================

REGTYPE *add_first(REGTYPE *temp, int data)
{
    // Intializing node item to insert into the beginning of the list
    REGTYPE *item = (struct q *)malloc(sizeof(REGTYPE));

    // Condition for if the list is empty
    if (temp == NULL)
    {
        // The new node previous and next should be NULL
        // since its the only node in the list
        item->prev = NULL;
        item->next = NULL;
        // Setting the value of the node to the value of the data variable
        item->number = data;
        // The new node will now be the head of the list
        temp = item;
    }
    // Condition for if the list is not empty
    else
    {

        // Setting the value of the node to the value of the data variable
        item->number = data;
        // Set previous of item to null since it will be at the beginning of the list
        item->prev = NULL;
        // Our old head of the list temp, will now be set as next node of our new node item
        item->next = temp;
        // Setting the value of the node to the value of the data variable
        item->number = data;
        // The new node will now be the head of the list
        temp = item;
    }
    // Returning the new head of the list , the new node we have inserted
    return temp;
}