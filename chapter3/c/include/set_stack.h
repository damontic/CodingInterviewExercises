#ifndef __SET_STACK_H
#define __SET_STACK_H

#include <stdlib.h>
#include "node.h"

typedef struct _set_stack_uint_t {
  node_uint_t* top;
  size_t threshold;
} set_stack_uint_t ;
set_stack_uint_t* set_stack_uint_new(size_t threshold, unsigned int data);
void set_stack_uint_destroy(set_stack_uint_t** self_p);
void set_stack_uint_push(set_stack_uint_t* self_p, unsigned int data);
unsigned int set_stack_uint_pop(set_stack_uint_t* self_p);
unsigned int set_stack_uint_peek(set_stack_uint_t* self_p);

#endif
