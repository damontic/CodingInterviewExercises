#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Node.h"

Node* Node_get_previous_node(Node* list, Node* actual_node){
  Node* iterator = list;
  Node* previous = NULL;
  while(iterator != NULL){
    if(iterator->data == actual_node->data && iterator->next == actual_node->next){
      return previous;
    }
    previous = iterator;
    iterator = iterator->next;
  }
  return NULL;
}

int Node_is_palindrome(Node* list){
  if(list == NULL){
    return 1;
  }
  Node* initial = list;
  Node* previous_to_final = NULL;
  Node* final = NULL;

  Node* iterator = list;
  while(iterator->next != NULL){
    previous_to_final = iterator;
    iterator = iterator->next;
  }
  final = iterator;
  while(initial->data != final->data && initial->next != final->next){
    if(initial->data != final->data){
      return 0;
    }
    initial = initial->next;
    previous_to_final = Node_get_previous_node(list, previous_to_final);
    final = previous_to_final;
  }
  return 1;
}

int main(){
  Node* my_linked_list1 = Node_create(1);
  Node_append_to_tail(my_linked_list1, 2);
  Node_append_to_tail(my_linked_list1, 3);
  Node_append_to_tail(my_linked_list1, 4);
  Node_append_to_tail(my_linked_list1, 5);
  Node_append_to_tail(my_linked_list1, 6);
  assert(!Node_is_palindrome(my_linked_list1));
  Node_destroy(my_linked_list1);
  
  my_linked_list1 = Node_create(6);
  Node_append_to_tail(my_linked_list1, 5);
  Node_append_to_tail(my_linked_list1, 4);
  Node_append_to_tail(my_linked_list1, 5);
  Node_append_to_tail(my_linked_list1, 6);
  assert(Node_is_palindrome(my_linked_list1));
  Node_destroy(my_linked_list1);

  my_linked_list1 = Node_create(6);
  Node_append_to_tail(my_linked_list1, 5);
  Node_append_to_tail(my_linked_list1, 4);
  Node_append_to_tail(my_linked_list1, 4);
  Node_append_to_tail(my_linked_list1, 5);
  Node_append_to_tail(my_linked_list1, 6);
  assert(Node_is_palindrome(my_linked_list1));
  Node_destroy(my_linked_list1);

  return 0;
}
