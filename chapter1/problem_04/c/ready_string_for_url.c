#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* shiftTwice(char* someString, int fromIndex, int trueLength){
  fromIndex++;
  char newValue1 = someString[fromIndex];
  char newValue2 = someString[fromIndex+1];
  for(int i = fromIndex; i < trueLength-2; i+=2){
    char temp1 = someString[i+2];
    char temp2 = someString[i+3];
    someString[i+2] = newValue1;
    someString[i+3] = newValue2;
    newValue1 = temp1;
    newValue2 = temp2;
  }
  return someString;
}

char* ready_string_for_url(char* someString, int trueLength){
  for(int i = 0; i < trueLength-2; i++){
    if(someString[i] == ' '){
      someString = shiftTwice(someString, i, trueLength);
      someString[i] = '%';
      someString[i+1] = '2';
      someString[i+2] = '0';
    }
  }
  return someString;
}

int main(int argc, char** argv){
  char* someString = NULL;
  size_t size = 0;
  size_t deltaSize = 3;
  int stringLength = 0;

  if(argc == 2){
    stringLength = strlen(argv[1]);
    someString = malloc(sizeof(char)*stringLength);
    strncpy(someString, argv[1], stringLength);
  }else{
    getline(&someString, &size, stdin);
    stringLength = strlen(someString);
  }

  int appliedDeltas = 0;
  for(int i = 0; i < stringLength; i++){
    if(someString[i] == ' '){
      someString = realloc(someString, deltaSize);
      appliedDeltas++;
    }
  }
  
  someString = ready_string_for_url(someString, stringLength+appliedDeltas*3);
  printf("%s\n", someString);
  
  //free(someString);
  return 0;
}
