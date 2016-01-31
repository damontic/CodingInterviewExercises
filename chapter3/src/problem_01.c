#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "stack.h"

int main() {
  node_uint_t* node = node_uint_new(4);
  stack_uint_t* stack = stack_uint_new(node);
  printf("%u\n", stack->top->data);
  stack_uint_destroy(&stack);
  return 0;
}
