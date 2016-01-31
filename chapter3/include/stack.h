#ifndef __STACK_H
#define __STACK_H

#include "node.h"

typedef struct _stack_uint_t {
  node_uint_t* top;
} stack_uint_t;
stack_uint_t* stack_uint_new(node_uint_t* top);
void stack_uint_destroy(stack_uint_t** stack);
unsigned int stack_uint_pop(stack_uint_t* self_p);
void stack_uint_push(stack_uint_t* self_p);
unsigned int stack_uint_peek(stack_uint_t* self_p);

#endif
