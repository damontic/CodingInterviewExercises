#include <stdlib.h>
#include <assert.h>
#include "stack_min.h"

stack_mins_uint_t* stack_mins_uint_new(unsigned int data){
  stack_mins_uint_t* new_stack = malloc(sizeof(stack_mins_uint_t));
  node_uint_t* new_node = node_uint_new(data);
  new_stack->top = new_node;
  new_stack->mins = stack_uint_new(data);
  return new_stack;
}

void stack_mins_uint_destroy(stack_mins_uint_t** stack){
  assert(stack);
  if(*stack){
    stack_mins_uint_t* my_stack = *stack;
    node_uint_destroy(&my_stack->top);
    stack_uint_destroy(&my_stack->mins);
    free(my_stack);
    *stack = NULL;
  }
}

unsigned int stack_mins_uint_pop(stack_mins_uint_t* self_p){
  unsigned int result = 0;
  if(self_p->top){
    result = self_p->top->data;
    node_uint_t* to_delete = self_p->top;
    self_p->top = self_p->top->next;
    free(to_delete);
    if(self_p->mins->top->data == result){
      stack_uint_pop(self_p->mins);
    }
  }
  return result;
}

void stack_mins_uint_push(stack_mins_uint_t* self_p, unsigned int data){
  node_uint_t* new_node = node_uint_new(data);
  new_node->next = self_p->top;
  self_p->top = new_node;
  if(self_p->mins->top->data > data){
    stack_uint_push(self_p->mins, data);
  }
}

unsigned int stack_mins_uint_peek(stack_mins_uint_t* self_p){
  return self_p->top->data;
}

unsigned int stack_mins_uint_min(stack_mins_uint_t* self_p){
  return self_p->mins->top->data;
}
