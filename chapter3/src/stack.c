#include <stdlib.h>
#include <assert.h>
#include "stack.h"

stack_uint_t* stack_uint_new(node_uint_t* top){
  stack_uint_t* new_stack = malloc(sizeof(stack_uint_t));
  new_stack->top = top;
  return new_stack;
}

void stack_uint_destroy(stack_uint_t** stack){
  assert(stack);
  if(*stack){
    stack_uint_t* my_stack = *stack;
    node_uint_destroy(&my_stack->top);
    free(my_stack);
    *stack = NULL;
  }
}

unsigned int stack_pop(stack_uint_t* self_p){
  unsigned int result = 0;
  if(self_p->top){
    result = self_p->top->data;
    self_p->top = self_p->top->next;
    return result;
  }
  return 0;
}
