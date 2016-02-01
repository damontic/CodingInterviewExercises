#include <assert.h>
#include "stack.h"
#include "set_stack.h"

set_stack_uint_t* set_stack_uint_new(size_t threshold, unsigned int data){
  set_stack_uint_t* new_set_stack = malloc(sizeof(set_stack_uint_t));
  stack_uint_t* new_stack = stack_uint_new(data);
  new_set_stack->stacks = malloc(sizeof(stack_uint_t*));
  new_set_stack->stacks[0] = new_stack;
  new_set_stack->threshold = threshold;
  new_set_stack->length = 1;
  return new_set_stack;
}

void set_stack_uint_destroy(set_stack_uint_t** self_p){
  assert(self_p);
  if(*self_p){
    set_stack_uint_t* to_delete = *self_p;
    for(int i = 0; i < to_delete->length; i++){
      stack_uint_t* stack_to_delete = to_delete->stacks[i];
      stack_uint_destroy(&stack_to_delete);
    }
    free(to_delete->stacks);
    free(to_delete);
    *self_p = NULL;
  }
}

void set_stack_uint_push(set_stack_uint_t* self_p, unsigned int data){
  stack_uint_push(self_p->stacks[0], data);
}

unsigned int set_stack_uint_pop(set_stack_uint_t* self_p){
  return stack_uint_pop(self_p->stacks[0]);
}

unsigned int set_stack_uint_peek(set_stack_uint_t* self_p){
  return self_p->stacks[0]->top->data;
}
