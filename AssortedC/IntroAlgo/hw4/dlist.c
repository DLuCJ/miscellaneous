/*This file includes double linked list functions to add, find, delete, list elements, along with
 *functions to make and delete a linked list.
 *
 * Author: Daniel Lu
 * Date:   2/6/2014
 */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dlist.h"
#include <limits.h>


Dlist * make(char * id) {
  Dlist* list = (Dlist *) malloc(sizeof(Dlist));
  list->head = NULL;
  list->name = id;
  return list;
}

void del(Dlist * d) {
  while(d->head != NULL) {
    Node* temp = d->head;
    d->head = temp->next;
    free(temp);
    printf("free \n");
  } 
  free(d);
  printf("free \n");
}

bool overflow(long long val) {
  bool overflow = val > INT_MAX || val < INT_MIN;
  if(overflow) {
    printf("Error: integer overflow\n");
  }
  return overflow;
}

int peek(Dlist *d) {
  if(isEmpty(d)) {
    return INT_MIN;
  }
  return d->head->data;
}

bool isEmpty(Dlist *d) {
  return (d->head == NULL);
}

int delNum(Dlist *d, int item) {
  
  int position = 0;
  Node * node = d->head;
    while(node != NULL){
    position++;
    if(node->data == item) {
      break;
    }
    node = node->next;
  }

  if(node == NULL) {
   return 0;
  }

  Node * right = node->next;
  Node * left = node->prev;
  if(left != NULL) {
    left->next = right;
  }else{
    d->head = right;
  }
  if(right != NULL) {
    right->prev = left;
  }
  return position;
}

int find(Dlist *d, int item) {
  int position = 0;
  Node * node = d->head;
  while(node != NULL){
    position++;
    if(node->data == item) {
      return position;
    }
    node = node->next;
  }
  return 0;
}

int insertNode(Dlist *d, Node* node) {

  node->prev = NULL;
  node->next = NULL;

  Node* right = d->head;
  if(right == NULL) {
    d->head = node;
  }

  Node * left = NULL;
  while(right!= NULL && (right->data < node->data) ){
    if(right->next == NULL) {
      left = right;
    }
    right = right->next;
  }
  node->next = right;
  if(right != NULL) {
    left = right->prev;
    right->prev = node;
  }
  if(left != NULL) {
    left->next = node;
    node->prev = left;
  }
  else {
    d->head = node;
  }
  return 0;
}

int insert(Dlist *d, int item) {
  
  Node * node = (Node *)malloc(sizeof(Node));
  node->data = item;
  return insertNode(d, node);
}
  
void list(Dlist *d, Node* node) {
  if(isEmpty(d)) {
    printf("empty, ok\n");
    return;
  }else if (node == NULL) {
    return;
  }else {
    printf("%i ", node->data);
    list(d,node->prev);
  }
}

Node * tail(Dlist *d) {
  Node* tail = d->head;
  while(tail != NULL && tail->next != NULL) {
    tail = tail->next;
  }
  return tail;
}
