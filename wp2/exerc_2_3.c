#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
 
 
// -----typedefs ------- 
typedef struct { 
        char firstname[20]; 
        char famname[20]; 
        char pers_number[13]; // yyyymmddnnnc 
} PERSON; 
 
// Function declaration (to be extend)  
PERSON input_record(void);             // Reads a person’s record. 
void write_new_file(PERSON *inrecord);  // Creates a file and  
// writes the first record 
void printfile();     // Prints out all persons in the file 

void search_by_firstname(char *name); // Prints out the person if    
// in list  
void append_file(PERSON *inrecord);    // appends a new person to the file 
 

void writeNewFile(PERSON *inrecord) {

     
    
    FILE* fileToWrite;
    char *fileName = "employee_record.bin";
    fileToWrite = fopen(fileName, "wb+");

    

      fwrite(inrecord, sizeof(PERSON), 1, fileToWrite);
      fclose(fileToWrite);
      printf("%s %s %s\n", inrecord->firstname, inrecord->famname, inrecord->pers_number);



}

void printfile() {
    
    PERSON testPerson;
    int n = 0;

    FILE* fileToRead;
    char *fileName = "C:/Users/gusta/coding/SEM/DIT632-WPs/employee_record.bin";
    fileToRead = fopen(fileName,"rb");
     while (fread(&testPerson, sizeof(testPerson), 1, fileToRead)) // while the file still has content print the person
    {
    printf("%s %s %s\n",testPerson.firstname, testPerson.famname, testPerson.pers_number); // print the person struct
     }
     fclose(fileToRead);
        }
    

    


void append_file(PERSON *inrecord) {
     FILE* fileToWrite;
    char *fileName = "employee_record.bin";
    fileToWrite = fopen(fileName, "ab");
   fwrite(inrecord, sizeof(PERSON), 1, fileToWrite);
    fclose(fileToWrite);
}
 
int main(void){ 
    
    
            PERSON ppost; 
    bool exit = false;
    int choice;

    while(!exit) {
        
        printf("Please Select one of the following options!\n");
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file. \n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");
    
        scanf("%d", &choice);

        if(choice == 1) {

           
            strncpy(ppost.firstname, "Guy", 20);
            strncpy(ppost.famname, "Placeholder", 20);
            strncpy(ppost.pers_number, "123456789012", 13);

            writeNewFile(&ppost);
        }
        
        if(choice == 2) {

            printf("Enter the name of the person you want to add\n");
            scanf("%s", ppost.firstname);
            printf("Now enter the surname\n");
            scanf("%s", ppost.famname);
            printf("Lastly enter the persons personnumber (yyyymmddxxxx)\n");
            scanf("%s", ppost.pers_number);
            
            append_file(&ppost);

            printf("entry successfully added!\n");
        }

        if(choice == 3) {
            printf("Type the name of the employee you want to find\n");
           // scanf("%s", ppost.firstname);

        }

        if(choice == 4) {
            printfile();
           
        }

        if(choice == 5) {

            printf("Bye Bye\n");
            exit = true;
        }

    }

    return(0);     
} 

    
