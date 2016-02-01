#include <assert.h>
#include "stack.h"
#include "set_stack.h"

set_stack_uint_t* set_stack_uint_new(size_t threshold, unsigned int data){
  set_stack_uint_t* new_set_stack = malloc(sizeof(set_stack_uint_t));
  stack_uint_t* new_stack = stack_uint_new(data);
  new_set_stack->stacks = malloc(sizeof(stack_uint_t**));
  new_set_stack->stacks[0] = new_stack;
  new_set_stack->threshold = threshold;
  new_set_stack->length = 1;
  new_set_stack->stack_count = 0;
  return new_set_stack;
}

void set_stack_uint_destroy(set_stack_uint_t** self_p){
  assert(self_p);
  if(*self_p){
    set_stack_uint_t* to_delete = *self_p;
    for(size_t i = 0; i < to_delete->stack_count+1; i++){
      stack_uint_t* stack_to_delete = to_delete->stacks[i];
      stack_uint_destroy(&stack_to_delete);
    }
    free(to_delete->stacks);
    free(to_delete);
    *self_p = NULL;
  }
}

void set_stack_uint_push(set_stack_uint_t* self_p, unsigned int data){
  if(self_p->length % self_p->threshold == 0){
    self_p->length = 1;
    self_p->stack_count++;
    stack_uint_t** temp_p = realloc(self_p->stacks, sizeof(stack_uint_t**) * self_p->stack_count);
    self_p->stacks = temp_p;
    stack_uint_t* new_stack = stack_uint_new(data);
    self_p->stacks[self_p->stack_count] = new_stack;
  }else{
    stack_uint_t* previous = (self_p->stacks)[self_p->stack_count];
    stack_uint_push(previous, data);
    self_p->length++;
  }
}

unsigned int set_stack_uint_pop(set_stack_uint_t* self_p){
  unsigned int result = 0;
  if(self_p->length == 1){
    stack_uint_destroy(&self_p->stacks[self_p->stack_count]);
    self_p->stack_count--;
    self_p->length = 5;
  }else{
    result = stack_uint_pop(self_p->stacks[self_p->stack_count]);
    self_p->length--;
  }
  return result;
}

unsigned int set_stack_uint_peek(set_stack_uint_t* self_p){
  return self_p->stacks[self_p->stack_count]->top->data;
}
