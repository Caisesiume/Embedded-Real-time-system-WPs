//Tuesday1

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
 
#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 
 
 
// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
int create_random(int *tab );   

 
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
int count_frequency(int *tab, int *freq );     
 
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
int draw_histogram(int *freq );  
 
// ------ Function definitions   ---------- 
 
int create_random(int *tab){

    // Fills the table with random numbers up to the MAX value defined
    // And prints them out
    srand ( time(NULL) );
    for(int i= 0; i< MAX; i++){
       int random = rand ()% MAXNUMBER;
       tab[i] = random;
       printf("%d\n", random);
    }
    return 0;    
}
 
int count_frequency(int *tab, int *freq ){   

    int count;
    // First loop loops through all of the possible numbers that was
    // Randomly generated
    for (int i = 0; i < MAXNUMBER; i++) {
        // Resets the count everytime the loop looks for a new number
        count = 0;
        // Second loopo looks through the table to see how many times i occur
        // Everytime it occurs the count increases by one
        for (int j = 0; j < MAX; j++) {
            if ( i == tab[j]) {
                count++;
            }
        }
        
        // Adds the count of i to the position of i in the freq table
        // If the number 3 occures 5 times in the table
        // freq[3] will have the value of 5
        freq[i] = count;
    }
    return 0;
} 

int draw_histogram(int *freq ) {

    // Goes through the freq table to count each occurence of the numbers
    for (int i = 0 ; i< MAXNUMBER; i++){
         // Will only print out if it occurs more than 0 times
         if (freq[i] > 0) {
            // Prints out the number that is being counted
            printf("%d ", i);
            // Will print an 'x' the number of times that number occured
            for(int j = 0; j < freq[i]; j++) {
            printf("%c", 'x'); 
            }
            printf("\n");

            }
         }
    return 0;

}

// ------ Main   -------------------------- 
 
// The main entry point for the program 
int main (void){ 
    
    int table[MAX], n ; 
    int frequency[MAXNUMBER]; 
    create_random(table);
    count_frequency(table,frequency);
    draw_histogram(frequency);
    return 0;
} 


