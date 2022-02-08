#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
#define NAME_OF_FILE "employee_record.bin"
 
 
// -----typedefs ------- 
typedef struct { 
        char firstname[20]; 
        char famname[20]; 
        char pers_number[13]; // yyyymmddnnnc 
} PERSON; 
 
// Function declaration (to be extend)  
PERSON input_record(void);             // Reads a person’s record. 
// Creates a file and  
// writes the first record 
void write_new_file(PERSON *inrecord);  
void printfile();     // Prints out all persons in the file 

void search_by_firstname(char *name); // Prints out the person if    
// in list  
void append_file(PERSON *inrecord);    // appends a new person to the file 
 

void write_new_file(PERSON *inrecord) {

    FILE* filePointer;
    filePointer = fopen(NAME_OF_FILE, "wb+");
    fwrite(inrecord, sizeof(PERSON), 1, filePointer);
    fclose(filePointer);
    
}

void printfile() {
    
    PERSON tmpPerson;
    FILE* filePointer;
    if (filePointer = fopen(NAME_OF_FILE,"rb")) {

    while (fread(&tmpPerson, sizeof(tmpPerson), 1, filePointer))  {
    
    printf("%s %s %s\n",tmpPerson.firstname, tmpPerson.famname, tmpPerson.pers_number); // print the person struct
    
    }
     
    fclose(filePointer);
    }

    else {
        printf("file does not exist\n");
    }
}
    

    


void append_file(PERSON *inrecord) {
   
    FILE* filePointer;
    filePointer = fopen(NAME_OF_FILE, "ab");
   
    fwrite(inrecord, sizeof(PERSON), 1, filePointer);
    fclose(filePointer);
}

void search_by_firstname(char* name) {

    PERSON tmpPerson;
    FILE* filePointer;

    if (filePointer = fopen(NAME_OF_FILE,"rb")); {

    while (fread(&tmpPerson, sizeof(tmpPerson), 1, filePointer)) {
        
        if (strcmp(name, tmpPerson.firstname) == 0 || strcmp(name, tmpPerson.famname) == 0) {

             printf("%s %s %s\n",tmpPerson.firstname, tmpPerson.famname, tmpPerson.pers_number); 
        }
     fclose(filePointer);
        }
    }
        printf("file does not exist\n");
     
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

            write_new_file(&ppost);
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
            char name[20];
            printf("Type the name of the employee you want to find\n");
            scanf("%s", name);
            search_by_firstname(name);

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

    
