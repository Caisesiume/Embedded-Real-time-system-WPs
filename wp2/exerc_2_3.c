//Submission code 53Tuesday

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define NAME_OF_FILE "employee_record.bin" // Filename used for entire file
 
 
// -----typedefs ------- 
typedef struct { 
        char firstname[20]; 
        char famname[20]; 
        char pers_number[13]; // yyyymmddnnnc 
} PERSON; 
 
// Creates a file and writes a dummy record 
void write_new_file(PERSON *inrecord);  
// Prints out all persons in the file 
void printfile();     

// Prints out all the persons that has their sur or lastname is in list  
void search_by_firstname(char *name); 
 // appends a new person to the file 
void append_file(PERSON *inrecord);  
 

void write_new_file(PERSON *inrecord) {

    FILE* filePointer;                                      // Assings the filepointer
    filePointer = fopen(NAME_OF_FILE, "wb+");               // Opens it in binary mode
    fwrite(inrecord, sizeof(PERSON), 1, filePointer);       // Writes the first dummyrecord to the file (Overwrites old data if file already exists)
    fclose(filePointer);                                    // Closes the file
    
}

void printfile() {
    
    PERSON tmpPerson;       // Initialises a temp PERSON struct to hold the data being read
    FILE* filePointer;      // Assigns the filepointer
    if (filePointer = fopen(NAME_OF_FILE,"rb")) {  // Checks if the file exists

    while (fread(&tmpPerson, sizeof(tmpPerson), 1, filePointer))  { // Assings the data to the tmp struct until it runs out of persons
    
    printf("%s %s %s\n",tmpPerson.firstname, tmpPerson.famname, tmpPerson.pers_number); // prints each person in the file
    
    }
     
    fclose(filePointer); // Closes the file
    }

    else {
        printf("file does not exist\n"); // Error message in case file does not exist
    }
}
    

    


void append_file(PERSON *inrecord) {
   
    FILE* filePointer;                                   // Assings filepointer
    filePointer = fopen(NAME_OF_FILE, "ab");             // Opens it in append mode
   
    fwrite(inrecord, sizeof(PERSON), 1, filePointer);    // Appends the new person to the file
    fclose(filePointer);                                 // CLoses the file
}

void search_by_firstname(char* name) {

    PERSON tmpPerson;
    FILE* filePointer;

    if (filePointer = fopen(NAME_OF_FILE,"rb")) {                                                       // Checks if the file exists

      while (fread(&tmpPerson, sizeof(tmpPerson), 1, filePointer)) {                                       // Loops through all the entries in the file
        
        if (strcmp(name, tmpPerson.firstname) == 0 || strcmp(name, tmpPerson.famname) == 0) {            // If either the firstname or surname matches the search it will print that struct

             printf("%s %s %s\n",tmpPerson.firstname, tmpPerson.famname, tmpPerson.pers_number); 
        }   

    }
     fclose(filePointer);                                                                                // closes the file

    } 

    else {
        printf("file does not exist\n");                                                                 // error message if the file does not exist
    }
     
}
int main(void){ 
    
    
    PERSON ppost;         // Temp person for putting in to the file
    bool exit = false;    // Bool to determine if loop continues or not
    int choice;           // int to determine what the user wants the program to do

    while(!exit) { // Indefinite loop until user exits it
        
        // Menu options
        printf("Please Select one of the following options!\n"); 
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file. \n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");
    
        scanf("%d", &choice); // Takes user input

        if(choice == 1) { // Creates a new file with dummy data

            // Dummy data for creating a file
            strncpy(ppost.firstname, "Guy", 20);
            strncpy(ppost.famname, "Placeholder", 20);
            strncpy(ppost.pers_number, "123456789012", 13);

            write_new_file(&ppost); // Creates a new file
        }
        
        if(choice == 2) { // Appends a new person to the file

            // User inputs data to the person struct that will be appended to the file
            printf("Enter the name of the person you want to add\n");
            scanf("%s", ppost.firstname);
            printf("Now enter the surname\n");
            scanf("%s", ppost.famname);
            printf("Lastly enter the persons personnumber (yyyymmddxxxx)\n");
            scanf("%s", ppost.pers_number);
            
            append_file(&ppost); // Forwards the person to the append function

            printf("entry successfully added!\n");
        }

        if(choice == 3) { // Searches for a person in the file
            char name[20];
            printf("Type the name of the employee you want to find\n");
            scanf("%s", name); // Userinput for the name they want to search
            search_by_firstname(name);

        }

        if(choice == 4) { // Prints all persons in the file
            printfile();
           
        }

        if(choice == 5) { // Exits the program

            printf("Bye Bye\n");
            exit = true; // Sets the loop to false and ends the program
        }


    }

    return(0);     
} 

    
