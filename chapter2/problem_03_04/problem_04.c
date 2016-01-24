#include <stdlib.h>
#include <stdio.h>
#include "Node.h"

Node* Node_partition_around_x(Node* list, int x){
  if(list == NULL){
    return NULL;
  }

  Node* partitioned = NULL;
  Node* n = list;
  do{
    if( n->data < x ){
      if(partitioned == NULL){
        partitioned = Node_append_to_tail(partitioned, n->data);
      }else{
	Node_append_to_tail(partitioned, n->data);
      }
    }
    n = n->next;
  }while(n != NULL);

  n = list;
  do{
    if( n->data >= x ){
      if(partitioned == NULL){
        partitioned = Node_append_to_tail(partitioned, n->data);
      }else{
	Node_append_to_tail(partitioned, n->data);
      }
    }
    n = n->next;
  }while(n != NULL);
  return partitioned;
}

int main(){
  Node* my_linked_list = Node_create(17);
  Node_append_to_tail(my_linked_list, 24);
  Node_append_to_tail(my_linked_list, 5);
  Node_append_to_tail(my_linked_list, 4);
  Node_append_to_tail(my_linked_list, 31);
  Node_append_to_tail(my_linked_list, 19);
  Node_append_to_tail(my_linked_list, 82);
  Node_append_to_tail(my_linked_list, 34);

  Node_print_each_element(my_linked_list);
  Node* partitioned1 = Node_partition_around_x(my_linked_list, 50);
  Node_print_each_element(partitioned1);
  Node* partitioned2 = Node_partition_around_x(my_linked_list, 30);
  Node_print_each_element(partitioned2);
  Node* partitioned3 = Node_partition_around_x(my_linked_list, 20);
  Node_print_each_element(partitioned3);
  
  Node_destroy(partitioned3);
  Node_destroy(partitioned2);
  Node_destroy(partitioned1);
  Node_destroy(my_linked_list);
  return 0;
}
