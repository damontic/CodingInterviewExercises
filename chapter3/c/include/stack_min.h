#ifndef __STACK_MIN_H
#define __STACK_MIN_H

#include "node.h"
#include "stack.h"

typedef struct _stack_mins_uint_t {
  node_uint_t* top;
  stack_uint_t* mins;
} stack_mins_uint_t;
stack_mins_uint_t* stack_mins_uint_new(unsigned int data);
void stack_mins_uint_destroy(stack_mins_uint_t** stack);
unsigned int stack_mins_uint_pop(stack_mins_uint_t* self_p);
void stack_mins_uint_push(stack_mins_uint_t* self_p, unsigned int data);
unsigned int stack_mins_uint_peek(stack_mins_uint_t* self_p);
unsigned int stack_mins_uint_min(stack_mins_uint_t* self_p);

#endif
