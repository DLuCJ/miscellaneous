
/*This file includes the pop, push and list functions
 *for the stack.
 *
 * Author: Daniel Lu
 * Date:   1/14/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack * _make(int size) {
  Stack* stack = (Stack *)malloc(sizeof(Stack));
  stack->stack = (int*) malloc(size * sizeof(int));
  stack->place = -1;
  stack->SIZE = size;
  return stack;
}

void _del(Stack * s) {
  free(s);
}

int pop(Stack * s) {
  if(isEmpty(s)) {
    //Error: stack empty. Can't pop.
    return 1;
  }

  s->place--;
  return 0;
}

int push(Stack *s, int item) {

  if(isFull(s)) {
    // Error: stack full
    return 1;
  }

  s->place++;
  s->stack[s->place] = item;
  return 0;
}

void list(Stack *s) {
  int i;
  printf("Top to bottom: ");
  for(i = (s->place); i >= 0; --i) {
    printf("%i ", s->stack[i]); 
  }
  printf("\n");
}

bool isFull(Stack *s) {
  return (s->place == s->SIZE - 1);
}

bool isEmpty(Stack *s) {
  return (s->place == -1);
}

