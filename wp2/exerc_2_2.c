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
    int nr = 0;

    REGTYPE *act_post, *head = NULL;
    srand(time(0)); //   Random seed
    head = random_list();
    head=add_first(head,56);
    act_post = head;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    // --- Free the allocated memory  ---

    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }

    return 0;
}


// ====     End of main   ======================================

REGTYPE *random_list(void)
{
    int nr, i = 0;
    nr = rand() % 100;
    REGTYPE *top, *old, *item;
    if (MAX >= 1)
    {
        top = (struct q *)malloc(sizeof(REGTYPE));
        if (top != NULL)
        {
            top->number = nr;
            top->prev = NULL;
            top->next = NULL;
            old = top;
            // putting data for rest of the nodes
            for (i = 1; i < MAX; i++)
            {
                item = (struct q *)malloc(sizeof(REGTYPE));
                nr = rand() % 100;
                if (item != NULL)
                {
                    item->number = nr;
                    item->prev = old; // new node is linking with the previous node
                    item->next = NULL;

                    old->next = item; // previous node is linking with the new node
                    old = item;       // assign new node as last node
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
    return (top);
}

//==========================================================

REGTYPE *add_first(REGTYPE *temp, int data)
{
    REGTYPE *item = (struct q *)malloc(sizeof(REGTYPE));
    //temp= (struct q *)malloc(sizeof(REGTYPE));
    item->number = data;
    item->prev = NULL;
    item->next = temp;
    if (temp == NULL)
    {
        item->prev = NULL;
        item->next = NULL;
        item->number = data;
        temp = item;
    }
    else
    {
        //MAX+1;
        temp->prev = item;
        item->prev = NULL;
        item->next = temp;
        item->number = data;
        temp = item;
    }
    return temp;
}