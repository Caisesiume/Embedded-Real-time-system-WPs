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

    srand ( time(NULL) );
    for(int i= 0; i< MAX; i++){
       int random = rand ()% MAXNUMBER;
       tab[i] = random;
       printf("%d\n", random);
    }
    return 0;    
}
 
int count_frequency(int *tab, int *freq ){   

    // Counts all possible numbers in loop and adds the
    // total count in to that position in the frequency array
    // e.g. if the number 3 occurs 4 times the third position
    // will have the value of 4
    
    int count;
    for (int i = 0; i < MAXNUMBER; i++) {
        count = 0;
        for (int j = 0; j < MAX; j++) {
            if ( i == tab[j]) {
                count++;
            }
        }
        
        freq[i] = count;
    }
    return 0;
} 

int draw_histogram(int *freq ) {

    // Checks if the value is greater than 0 and then prints
    // as many x's as that value
    // does nothing if < 0
    
    for (int i = 0 ; i< MAXNUMBER; i++){
         if (freq[i] > 0) {
            printf("%d ", i);
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
//  
// If you choose to go for the optional part 
// Please modify it accordingly 
int main (void){ 
    
    int table[MAX], n ; 
    int frequency[MAXNUMBER]; 
    create_random(table);
    count_frequency(table,frequency);
    draw_histogram(frequency);
    return 0;
} 


