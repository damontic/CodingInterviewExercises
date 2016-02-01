#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main() {
  puts("STACK:");
  stack_uint_t* stack = stack_uint_new(1);
  stack_uint_push(stack, 2);
  stack_uint_push(stack, 3);
  stack_uint_push(stack, 4);
  unsigned int my_number = stack_uint_pop(stack);
  printf("%u\n", my_number);
  printf("%u\n", stack_uint_peek(stack));
  stack_uint_destroy(&stack);

  puts("QUEUE:");
  queue_uint_t* queue = queue_uint_new(1);
  queue_uint_enqueue(queue, 2);
  queue_uint_enqueue(queue, 3);
  queue_uint_enqueue(queue, 4);
  unsigned int val = queue_uint_dequeue(queue);
  printf("%d\n", val);
  val = queue_uint_dequeue(queue);
  printf("%d\n", val);
  queue_uint_destroy(&queue);
  
  return 0;
}
