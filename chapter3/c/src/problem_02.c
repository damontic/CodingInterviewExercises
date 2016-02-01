#include <stdlib.h>
#include <stdio.h>
#include "stack_min.h"

int main(){
  stack_mins_uint_t* stack = stack_mins_uint_new(99);
  stack_mins_uint_push(stack, 46);
  stack_mins_uint_push(stack, 64);
  stack_mins_uint_push(stack, 79);
  stack_mins_uint_push(stack, 13);
  stack_mins_uint_push(stack, 28);
  printf("%u\n", stack_mins_uint_min(stack));
  stack_mins_uint_destroy(&stack);
  return EXIT_SUCCESS;
}
