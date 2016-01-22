#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse(char* str){
  int myStringLength = strlen(str);
  char temp;
  for(int i = 0; i < myStringLength/2; i++){
    temp = str[i];
    str[i] = str[myStringLength -i -1];
    str[myStringLength -i -1] = temp;
  }
}

int main(int argc, char** args){
  if(argc == 1){
    fprintf(stderr, "Usage: ./reverse STRING\n");
    return 1;
  }
  
  reverse(args[1]);
  printf("%s\n", args[1]);
  return 0;
}
