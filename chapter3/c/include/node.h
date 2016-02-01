#ifndef __NODE_H
#define __NODE_H

typedef struct _node_uint_t{
  struct _node_uint_t* next;
  unsigned int data;
} node_uint_t;
node_uint_t* node_uint_new(unsigned int data);
void node_uint_destroy(node_uint_t** node);

#endif
