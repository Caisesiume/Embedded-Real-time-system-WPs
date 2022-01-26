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
    return 0;
} 

int create_random(int *tab){
    int table[MAX];
    tab = &table[0];
    for(int i= 0; i< MAX; i++){
       int random = rand ()% MAXNUMBER;
       *tab = random;
       printf("%d\n", table[i]);
       tab ++;
    }
    return 0;    
}

int count_frequency(int *tab, int *freq ){   
    int table [MAX];
    int frequencyArray [MAX];
    int count,i;
    if(table[i]!= -1) {
    for (i =0 ; i< MAX; i++){
        count = 1;
        freq ++;
        for( int j = i+ 1; j< MAX; j++){
            if ( table[i]== table[j]){
                count ++;
                table[j]= -1;
            } 
        }
        frequencyArray[i]= count;       
    }       
    }
    for (i =0 ; i< MAX; i++){
        if( table[i]!= -1){
        printf("%d occurs %d times\n", table[i], frequencyArray[i]);    
        }
    }
    return 0;
} 