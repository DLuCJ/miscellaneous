/*This file includes stack functions pop, push, list with
 *functions to make and delete a stack.
 *
 * Author: Daniel Lu
 * Date:   1/29/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "ddcalculator.h"
#include <limits.h>

Stack * _make() {
  Stack* stack = (Stack *) malloc(sizeof(Stack));
  stack->head = NULL;
  stack->size = 0;
  return stack;
}

void _del(Stack * s) {
  while(s->head != NULL) {
    Node* temp = s->head;
    s->head = temp->next;
    free(temp);
  }
  free(s);
}

int peek(Stack *s) {
  if(isEmpty(s)) {
    return INT_MIN;
  }
  return s->head->data;
}

int pop(Stack * s) {
  if(isEmpty(s)) {
    //Error: stack empty. Can't pop.
    return 1;
  }
  
  Node * top = s->head;
  s->head = s->head->next;
  if(s->head != NULL) {
    s->head->prev = NULL;
  }
  s->size--;

  free(top);
  return 0;
}

int push(Stack *s, int item) {

  if(isFull(s)) {
    // Error: stack full
    return 1;
  }

  Node * node = (Node *)malloc(sizeof(Node));
  node->data = item;
  node->prev = NULL;
  node->next = s->head;
  if(s->head != NULL) {
    s->head->prev = node;
  }
  s->head = node;
  s->size++;

  return 0;
}

void list(Stack *s) {

  printf("Top to bottom: ");
  while(s->head != NULL) {
    printf("%i ", s->head->data);
    s->head = s->head->next;
  }
  printf("\n");
}

bool isFull(Stack *s) {
  return false;
}

bool isEmpty(Stack *s) {
  return (s->size == 0);
}

