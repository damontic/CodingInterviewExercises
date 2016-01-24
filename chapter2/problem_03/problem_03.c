#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
  void* next;
  int data;
} Node;

Node* Node_create(int data){
  Node* nodo = malloc(sizeof(Node));
  nodo->data = data;
  nodo->next=NULL;
}

void Node_destroy(Node* node){
  Node* n = node;
  while(n->next!=NULL){
    Node* to_delete = n;
    n = n->next;
    free(to_delete);
    }
  free(n);
}

Node* Node_append_to_tail(Node* node, int data){
  Node* new_node = Node_create(data);
  Node* n = node;
  while(n->next != NULL){
    n = n->next;
  }
  n->next = new_node;
  return new_node;
}

void Node_print_each_element(Node *node){
  Node* n = node;
  printf("%d ", n->data);
  while(n->next != NULL){
    n=n->next;
    printf("%d ", n->data);
  }
  printf("\b\n");
}

void Node_delete_in_the_middle(Node* node_to_delete){
  Node* next_from_node_to_delete = node_to_delete->next;
  if(next_from_node_to_delete != NULL){
    node_to_delete->next = next_from_node_to_delete->next;
    node_to_delete->data = next_from_node_to_delete->data;
    free(next_from_node_to_delete);
  }else{
    fprintf(stderr, "Cannot delete node with data %d because it is the last element of the list.", node_to_delete->data);
  }
}

int main(){
  Node* nodo = Node_create(8);
  Node* node_to_delete2 = Node_append_to_tail(nodo, 9);
  Node_append_to_tail(nodo, 10);
  Node_append_to_tail(nodo, 11);
  Node_append_to_tail(nodo, 12);
  Node* node_to_delete1 = Node_append_to_tail(nodo, 13);
  Node_append_to_tail(nodo, 14);
  Node* node_to_delete3 = Node_append_to_tail(nodo, 15);

  Node_print_each_element(nodo);
  Node_delete_in_the_middle(node_to_delete1);
  Node_print_each_element(nodo);
  Node_delete_in_the_middle(node_to_delete2);
  Node_print_each_element(nodo);
  Node_delete_in_the_middle(node_to_delete3);
  Node_print_each_element(nodo);
  Node_delete_in_the_middle(nodo);
  Node_print_each_element(nodo);
  
  Node_destroy(nodo);
  return 0;
}
