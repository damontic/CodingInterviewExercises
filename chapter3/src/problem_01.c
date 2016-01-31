#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main() {
  stack_uint_t* stack = stack_uint_new(1);
  stack_uint_push(stack, 2);
  stack_uint_push(stack, 3);
  stack_uint_push(stack, 4);
  unsigned int my_number = stack_uint_pop(stack);
  printf("%u\n", my_number);
  printf("%u\n", stack_uint_peek(stack));
  stack_uint_destroy(&stack);
  return 0;
}
