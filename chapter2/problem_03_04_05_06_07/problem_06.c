#include <stdlib.h>
#include <stdio.h>
#include "Node.h"

int Node_is_node_twice(Node* list, Node* actual_node){
  Node* iterator = list;
  unsigned int times_found_actual = 0;
  unsigned int times_found_next = 0;
  Node* next_node = actual_node->next;
  while(iterator != NULL){
    if(iterator->data == actual_node->data && iterator->next == actual_node->next){
      times_found_actual++;
      if(times_found_actual == 2){
        return 1;
      }
    }
    if(iterator->data == next_node->data && iterator->next == next_node->next){
      times_found_next++;
      if(times_found_next == 2){
        return 0;
      }
    }
    iterator = iterator->next;
  }
  return 0;
}

Node* Node_advance_positions(Node* list, int positions, Node** previous){
  if(list == NULL || list->next == NULL){
    return NULL;
  }

  Node* actual_node = list->next;
  *previous = list;
  for(int i = 0; i < positions; i++){
    if(actual_node->next == NULL)
      break;
    *previous = actual_node;
    actual_node = actual_node->next;
  }
  return actual_node;
}

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

Node* Node_detect_loop_node(Node* list){
  if(list == NULL || list->next == NULL){
    return NULL;
  }

  Node* previous_node;
  Node* actual_node = Node_advance_positions(list, 100, &previous_node);
  while(previous_node != NULL){
    if(!Node_is_node_twice(list, previous_node) && Node_is_node_twice(list, actual_node)){
      return actual_node;
    }
    actual_node = previous_node;
    previous_node = Node_get_previous_node(list, actual_node);
  }
  
  return NULL;
}

void Node_append_node_to_tail(Node* list, Node* new_node){
  if(list == NULL || new_node == NULL){
    return;
  }
  Node* n = list;
  while(n->next != NULL){
    n = n->next;
  }
  n->next = new_node;
}

int main(){
  Node* my_linked_list1 = Node_create(1);
  Node_append_to_tail(my_linked_list1, 2);
  Node_append_to_tail(my_linked_list1, 3);
  Node* n = Node_append_to_tail(my_linked_list1, 4);
  Node_append_to_tail(my_linked_list1, 5);
  Node_append_to_tail(my_linked_list1, 6);
  Node_append_node_to_tail(my_linked_list1, n);

  Node* loop_node = Node_detect_loop_node(my_linked_list1);
  if(loop_node != NULL){
    printf("The loop node has data: %d\n", loop_node->data);
  }else{
    printf("No loop found\n");
    Node_destroy(my_linked_list1);
  }

  return 0;
}
