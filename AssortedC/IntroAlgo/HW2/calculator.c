
/*This file includes functions for performing calculations on stack elements
 *including add, subtract, divide, multiply.
 *
 * Author: Daniel Lu
 * Date:   1/22/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "calculator.h"
#include <limits.h>

bool overflow(long long val) {
  bool overflow = val > INT_MAX || val < INT_MIN;
  if(overflow) {
    printf("Error: integer overflow\n");
  }
  return overflow;
}

int add(Stack *s) {
  if(s->place < 1) {
    return 1;
  }
  long long temp = (long long)s->stack[s->place] + s->stack[s->place -1];
  if(overflow(temp)) {
    return 2;
  }
  s->place--;
  s->stack[s->place] = temp;
  printf("Ok \n");
  return 0;
}

int subtract(Stack *s) {
  if(s->place < 1) {
    return 1;
  }

  long long temp = (long long)s->stack[s->place-1] - s->stack[s->place];
  if(overflow(temp)) {
    return 2;
  }
  s->place--;
  s->stack[s->place] = temp;
  printf("Ok \n");
  return 0;
}

int divide(Stack *s) {
  if(s->place < 1) {
    return 1;
  }
  if(s->stack[s->place] == 0){
    printf("Error: division by zero\n");
    return 2;
  }
  long long temp = (long long)s->stack[s->place-1] / s->stack[s->place];
  if(overflow(temp)) {
    return 2;
  }
  s->place--;
  s->stack[s->place] = temp;
  printf("Ok \n");
  return 0;
}

int multiply(Stack *s) {
  if(s->place < 1) {
    return 1;
  }

  long long temp = (long long)s->stack[s->place] * s->stack[s->place-1];
  if(overflow(temp)) {
    return 2;
  }
  s->place--;
  s->stack[s->place] = temp;
  printf("Ok \n");
  return 0;
}

