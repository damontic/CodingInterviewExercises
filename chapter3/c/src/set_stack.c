#include <assert.h>
#include "set_stack.h"

set_stack_uint_t* set_stack_uint_new(size_t threshold, unsigned int data){
  set_stack_uint_t* new_set_stack = malloc(sizeof(set_stack_uint_t));
  node_uint_t* new_node = node_uint_new(data);
  new_set_stack->top = new_node;
  new_set_stack->threshold = threshold;
  return new_set_stack;
}

void set_stack_uint_destroy(set_stack_uint_t** self_p){
  assert(self_p);
  if(*self_p){
    set_stack_uint_t* to_delete = *self_p;
    node_uint_destroy(&to_delete->top);
    free(to_delete);
    *self_p = NULL;
  }
}

void set_stack_uint_push(set_stack_uint_t* self_p, unsigned int data){
  node_uint_t* new_node = node_uint_new(data);
  new_node->next = self_p->top;
  self_p->top = new_node;
}

unsigned int set_stack_uint_pop(set_stack_uint_t* self_p){
  unsigned int result = 0;
  if(self_p->top){
    node_uint_t* to_delete = self_p->top;
    result = to_delete->data;
    self_p->top = to_delete->next;
    free(to_delete);
  }
  return result;
}

unsigned int set_stack_uint_peek(set_stack_uint_t* self_p){
  return self_p->top->data;
}
