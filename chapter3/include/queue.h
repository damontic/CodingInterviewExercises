#ifndef __QUEUE_H
#define __QUEUE_H

typedef struct _queue_uint_t{
  node_uint_t* first;
  node_uint_t* last;
} queue_uint_t;
queue_uint_t* queue_uint_new(unsigned int data);
void queue_uint_destroy(queue_uint_t** to_delete);
void queue_uint_enqueue(queue_uint_t* self_p, unsigned int data);
unsigned int queue_uint_dequeue(queue_uint_t* self_p);

#endif
