#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int decode(unsigned char hex);

int main(int argc, char *argv[])
{
    if(argc == 2){
    char *hexval = argv[1];
    int hex = strtol(hexval, NULL, 16);
    printf("value:%d\n", hex);
    decode(hex);
    }
    else{
            printf("Arguments Input Incorrect or absent\n");
    }
    return 0;
}

int decode(unsigned char hex)
{

    int engine_on = 0;
    int gear_pos = 0;
    int key_pos = 0;
    int brake1 = 0;
    int brake2 = 0;

    engine_on = hex >> 7;
    hex = hex << 1;
    //printf("%d,", hex);

    gear_pos = hex >> 5;
    hex = hex << 3;
    

    key_pos = hex >> 6;
    hex = hex << 2;

    brake1 = hex >> 7;
    hex = hex << 1;

    brake2 = hex >> 7;
    
    printf("Name                Value\n");
    printf("------------------------------\n");
    printf("engine_on   %d \n", engine_on);
    printf("gear_pos    %d \n", gear_pos);
    printf("key_pos     %d \n", key_pos);
    printf("brake1      %d \n", brake1);
    printf("brake2      %d \n", brake2);

    return 0;
}