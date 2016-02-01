#include <stdlib.h>
#include <assert.h>
#include "stack.h"

stack_uint_t* stack_uint_new(unsigned int data){
  stack_uint_t* new_stack = malloc(sizeof(stack_uint_t));
  node_uint_t* new_node = node_uint_new(data);
  new_stack->top = new_node;
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

unsigned int stack_uint_pop(stack_uint_t* self_p){
  unsigned int result = 0;
  if(self_p->top){
    result = self_p->top->data;
    node_uint_t* to_delete = self_p->top;
    self_p->top = self_p->top->next;
    free(to_delete);
  }
  return result;
}

void stack_uint_push(stack_uint_t* self_p, unsigned int data){
  node_uint_t* new_node = node_uint_new(data);
  new_node->next = self_p->top;
  self_p->top = new_node;
}

unsigned int stack_uint_peek(stack_uint_t* self_p){
  return self_p->top->data;
}
