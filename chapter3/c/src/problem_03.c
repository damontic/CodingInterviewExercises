#include <stdlib.h>
#include <stdio.h>
#include "set_stack.h"

int main(){
  set_stack_uint_t* set_stack = set_stack_uint_new(5, 99);
  set_stack_uint_push(set_stack, 46);
  set_stack_uint_push(set_stack, 64);
  set_stack_uint_push(set_stack, 79);
  set_stack_uint_push(set_stack, 13);
  set_stack_uint_push(set_stack, 28);

  printf("%u\n", set_stack_uint_peek(set_stack));
  set_stack_uint_pop(set_stack);
  printf("%u\n", set_stack_uint_peek(set_stack));
  set_stack_uint_pop(set_stack);
  printf("%u\n", set_stack_uint_peek(set_stack));

  set_stack_uint_destroy(&set_stack);
  return EXIT_SUCCESS;
}
