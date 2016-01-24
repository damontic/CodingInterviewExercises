#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Node.h"

unsigned int Node_list_to_number(Node* some_list){
  if(some_list == NULL){
    return 0;
  }
  Node* n = some_list;
  unsigned int digits_counter = 1;
  unsigned int result = n->data;
  while(n->next != NULL){
    n = n->next;
    result += pow(10, digits_counter)*n->data;
    digits_counter++;
  }
  return result;
}

Node* Node_sum_numbers_in_list(Node* first, Node* second){
  unsigned int result = Node_list_to_number(first) + Node_list_to_number(second);
  char* buffer = calloc(256, sizeof(char));
  sprintf(buffer, "%u", result);
  char elem = buffer[0];
  Node* list = Node_create(atoi(&elem));
  int index = 1;
  while(buffer[index] != 0){
    elem = buffer[index];
    Node_append_to_tail(list, atoi(&elem));
    index++;
  }
  free(buffer);
  return list;
}

int main(){
  Node* my_linked_list1 = Node_create(7);
  Node_append_to_tail(my_linked_list1, 1);
  Node_append_to_tail(my_linked_list1, 6);
  Node_print_each_element(my_linked_list1);

  Node* my_linked_list2 = Node_create(5);
  Node_append_to_tail(my_linked_list2, 9);
  Node_append_to_tail(my_linked_list2, 2);
  Node_print_each_element(my_linked_list2);

  printf("Result of sum: \n");
  Node* result = Node_sum_numbers_in_list(my_linked_list1, my_linked_list2);
  Node_print_each_element(result);

  Node_destroy(result);
  Node_destroy(my_linked_list1);
  Node_destroy(my_linked_list2);
  
  printf("========================================\n");
  
  my_linked_list1 = Node_create(1);
  Node_print_each_element(my_linked_list1);

  my_linked_list2 = Node_create(5);
  Node_print_each_element(my_linked_list2);

  printf("Result of sum: \n");
  result = Node_sum_numbers_in_list(my_linked_list1, my_linked_list2);
  Node_print_each_element(result);

  Node_destroy(result);
  Node_destroy(my_linked_list1);
  Node_destroy(my_linked_list2);

  printf("========================================\n");
  
  my_linked_list1 = Node_create(1);
  Node_print_each_element(my_linked_list1);

  my_linked_list2 = Node_create(9);
  Node_append_to_tail(my_linked_list2, 8);
  Node_append_to_tail(my_linked_list2, 7);
  Node_append_to_tail(my_linked_list2, 9);
  Node_print_each_element(my_linked_list2);

  printf("Result of sum: \n");
  result = Node_sum_numbers_in_list(my_linked_list1, my_linked_list2);
  Node_print_each_element(result);

  Node_destroy(result);
  Node_destroy(my_linked_list1);
  Node_destroy(my_linked_list2);
  
  return 0;
}
