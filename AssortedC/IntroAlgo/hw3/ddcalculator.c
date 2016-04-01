/*This file includes functions for performing calculations on stack elements
 *including add, subtract, divide, multiply.
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

bool overflow(long long val) {
  bool overflow = val > INT_MAX || val < INT_MIN;
  if(overflow) {
    printf("Error: integer overflow\n");
  }
  return overflow;
}

int add(Stack *s) {
  if(s->size <= 1) {
    return 1;
  }
  int val_1 = peek(s);
  pop(s);
  int val_2 = peek(s);
  pop(s);
  long long temp = (long long)val_1 + val_2;
  if(overflow(temp)) {
    return 2;
  }
  push(s,temp);
  return 0;
}

int subtract(Stack *s) {
  if(s->size <= 1) {
    return 1;
  }
  int val_1 = peek(s);
  pop(s);
  int val_2 = peek(s);
  pop(s);
  long long temp = (long long)val_2 - val_1;
  if(overflow(temp)) {
    return 2;
  }
  push(s,temp);

  return 0;
}

int divide(Stack *s) {
  if(s->size <= 1) {
    return 1;
  }
  int val_1 = peek(s);
  pop(s);
  int val_2 = peek(s);
  pop(s);
  if(val_1 == 0) {
    return 3;
  }
  long long temp = (long long) val_2 / val_1;
  if(overflow(temp)) {
    return 2;
  }
  push(s,temp);

  return 0;
}

int multiply(Stack *s) {
  if(s->size <= 1) {
    return 1;
  }
  int val_1 = peek(s);
  pop(s);
  int val_2 = peek(s);
  pop(s);
  long long temp = (long long) val_1 * val_2;
  if(overflow(temp)) {
    return 2;
  }
  push(s,temp);

  return 0;
}


