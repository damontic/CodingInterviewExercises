#include <stdlib.h>
#include <assert.h>
#include "node.h"

node_uint_t* node_uint_new(unsigned int data){
  node_uint_t* new_node = malloc(sizeof(node_uint_t));
  new_node->next = NULL;
  new_node->data = data;
  return new_node;
}

void node_uint_destroy(node_uint_t** node){
  assert(node);
  if(*node){
    node_uint_t* my_node = *node;
    node_uint_destroy(&my_node->next);
    free(my_node);
    *node = NULL;
  }
}

