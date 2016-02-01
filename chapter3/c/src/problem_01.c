#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct _Stack3 {
  size_t stack1_index;
  size_t stack2_index;
  size_t stack3_index;
  size_t stack1_dim;
  size_t stack2_dim;
  size_t stack3_dim;
  unsigned int* stacks;
} Stack3;

Stack3* Stack3_create(size_t dim1, size_t dim2, size_t dim3){
  Stack3* new_stack = malloc(sizeof(Stack3));
  new_stack->stack1_index = 0;
  new_stack->stack2_index = dim1;
  new_stack->stack3_index = dim1+dim2;
  new_stack->stack1_dim = dim1;
  new_stack->stack2_dim = dim1+dim2;
  new_stack->stack3_dim = dim1+dim2+dim3;
  new_stack->stacks = malloc(sizeof(unsigned int) * (dim1 + dim2 + dim3));
  return new_stack;
}

void Stack3_destroy(Stack3** self_p){
  assert(self_p);
  if(*self_p){
    Stack3* to_delete = *self_p;
    free(to_delete->stacks);
    free(to_delete);
    *self_p = NULL;
  }
}

void Stack3_push(Stack3* self_p, size_t stack_index, unsigned int data){
  switch(stack_index){
    case 1:
      if(self_p->stack1_index < self_p->stack1_dim){
        self_p->stacks[self_p->stack1_index] = data;
	self_p->stack1_index++;	
      }
      break;
    case 2:
      if(self_p->stack2_index < self_p->stack2_dim){
        self_p->stacks[self_p->stack2_index] = data;
	self_p->stack2_index++;	
      }
      break;
    case 3:
      if(self_p->stack3_index < self_p->stack3_dim){
        self_p->stacks[self_p->stack3_index] = data;
	self_p->stack3_index++;	
      }
      break;
  }
}

unsigned int Stack3_pop(Stack3* self_p, size_t stack_index){
  unsigned int result = 0;
  switch(stack_index){
    case 1:
      if(self_p->stack1_index > 0){
        self_p->stack1_index--;
        result = self_p->stacks[self_p->stack1_index];
      }
      break;
    case 2:
      if(self_p->stack2_index > self_p->stack1_dim){
        self_p->stack2_index--;
        result = self_p->stacks[self_p->stack2_index];
      }
      break;
    case 3:
      if(self_p->stack3_index > self_p->stack2_dim){
        self_p->stack3_index--;
        result = self_p->stacks[self_p->stack3_index];
      }
      break;
  }
  return result;
}

int main(){
  Stack3* stack = Stack3_create(5,5,5);
  Stack3_push(stack, 3, 31);
  Stack3_push(stack, 2, 21);
  Stack3_push(stack, 1, 11);
  Stack3_push(stack, 3, 32);
  Stack3_push(stack, 2, 22);
  Stack3_push(stack, 1, 12);
  Stack3_push(stack, 3, 33);
  Stack3_push(stack, 2, 23);
  Stack3_push(stack, 1, 13);

  printf("%u\n", Stack3_pop(stack, 1));
  printf("%u\n", Stack3_pop(stack, 2));
  printf("%u\n", Stack3_pop(stack, 3));
  printf("%u\n", Stack3_pop(stack, 1));
  printf("%u\n", Stack3_pop(stack, 2));
  printf("%u\n", Stack3_pop(stack, 3));
  
  Stack3_destroy(&stack);
  return EXIT_SUCCESS;
}
