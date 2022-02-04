#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int code(int engine_on, int gear_pos, int key_pos, int brake1, int brake2);

int main(int argc, char *argv[])
{

  if (argc == 6)
  {
    char *e= argv[1];
    char *g= argv[2];
    char *k= argv[3];
    char *b1= argv[4];
    char *b2= argv[5];

    int engine_on = atoi(e);
    int gear_pos = atoi(g);
    int key_pos =  atoi(k);
    int brake1 = atoi(b1);
    int brake2 = atoi(b2);
    code(engine_on, gear_pos, key_pos, brake1, brake2);
  }
  else{
    printf("Not enough arguments inputted\n");
  }

  return 0;
}

int code(int engine_on, int gear_pos, int key_pos, int brake1, int brake2)
{

  unsigned char byte = 0;
  byte = brake2;
  brake1 = brake1 << 1;
  byte = byte | brake1;
  key_pos = key_pos << 2;
  byte = byte | key_pos;
  gear_pos = gear_pos << 4;
  byte = byte | gear_pos;
  engine_on = engine_on << 7;
  byte = byte | engine_on;

  printf("Number of byte is : %X\n", byte);
  printf("Size of byte is %lu\n", sizeof(byte));

  return 0;
}
