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
  if(node == NULL){
    return new_node;
  }
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
