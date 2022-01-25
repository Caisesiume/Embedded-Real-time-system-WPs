#include <stdio.h>

#define MAX 27

int letterCheck(char c) {
    if (c < 91) {
      return 78;
    }
      return 110;
}
char swapLetter(char c) {

    for (int i = 0; i < 6; i++) {
      if (c < letterCheck(c)) {
        return c + 13;
      }
      else if (c >= 78)
        return c - 13;
      }
  }

int main(void) {

char userinput[100];
char testInput[6] = {'B','a','n','a','n','\0'};
char test = 'b' -32;


for (int i = 0; i < 6; i++) {
  testInput[i] = swapLetter(testInput[i]);
}
printf("%s\n",testInput);

  return 0;
}

