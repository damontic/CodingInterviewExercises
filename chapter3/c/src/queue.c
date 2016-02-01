#include <stdlib.h>
#include <assert.h>
#include "node.h"
#include "queue.h"

queue_uint_t* queue_uint_new(unsigned int data){
  queue_uint_t* new_queue = malloc(sizeof(queue_uint_t));
  node_uint_t* new_node = node_uint_new(data);
  new_queue->first = new_node;
  new_queue->last = new_node;
  return new_queue;
}

void queue_uint_destroy(queue_uint_t** self_p){
  assert(self_p);
  if(*self_p){
    queue_uint_t* to_delete = *self_p;
    node_uint_destroy(&to_delete->first);
    free(to_delete);
    *self_p = NULL;
  }
}

void queue_uint_enqueue(queue_uint_t* self_p, unsigned int data){
  self_p->last->next = node_uint_new(data);
  self_p->last = self_p->last->next;
}

unsigned int queue_uint_dequeue(queue_uint_t* self_p){
  unsigned int result = 0;
  if(self_p->first){
    node_uint_t* to_delete = self_p->first;
    result = to_delete->data;
    self_p->first = self_p->first->next;
    free(to_delete);
  }
  return result;
}
