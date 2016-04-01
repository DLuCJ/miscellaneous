/*This program implements a stack with
 *push, pop and list functionalities using
 *a doubly linked list of integers and provides calculator functionalities.
 *These include add, subtract, divide, and multiply
 *
 * Author: Daniel Lu
 * Date:   1/29/2014
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <stdbool.h>
#include "ddcalculator.h"

int main() {

  printf("Hello, this program implements a stack.\n");
  printf("Enter #<integer> to push.\n");
  printf("Enter < . > to pop.\n");
  printf("Enter < + > < - > < / > < * > to \n");
  printf("add, subtract, divide, and multiply, respectively.\n");
  printf("The result will be at the top of the stack.\n");
  printf("Please enter 'list' to view stack contents and exit\n");

  Stack * stack = _make();

  char str [100];
  while(1) {
    char * errMessage = NULL;
    printf("Enter: ");
    char * result = fgets(str, 100, stdin);
    if(result[0] == '#') {
      char * end_ptr = 0;
      result++;
      long long val = strtoll(result,&end_ptr,10);
      if((end_ptr != 0 && *end_ptr != '\n' && *end_ptr != '\0') || overflow(val)){
        printf("Error: invalid input.\n");
        printf("Expecting format #<integer>\n");
        continue;
      }
      if(push(stack,val) == 1) {
        errMessage = "Error: stack full";
      }
    } else if(result[0] == '.') {
      int temp = peek(stack);
      if(pop(stack) == 1) {
        errMessage = "Error:stack empty";
      }else {
	printf("Number popped: %i\n",temp);
      }
    }else if(result[0] == 'l' || result[0] == 'L') {
      list(stack);
      //done and exit
      break;
    } else if (result[0] == '+') {
      if(add(stack) == 1) {
        errMessage = "Error: not enough values for operation";
      }
    } else if(result[0] == '-') {
      if(subtract(stack) == 1) {
        errMessage = "Error: not enough values for operation";
      }
    } else if(result[0] == '/') {
      int status = divide(stack);
      if(status == 1) {
        errMessage = "Error: not enough values for operation";
      }else if(status == 3) {
	errMessage = "Error: division by zero";
      }
    } else if(result[0] == '*') {
      if(multiply(stack) == 1) {
        errMessage = "Error: not enough values for operation";
      }
    }else {
      printf("Input not recognized, enter again\n");
      continue;
    }
    if(errMessage != NULL) {
      printf("%s \n",errMessage);
    }else {
      printf("Ok \n");
    }
  }


  _del(stack);

  return 0;
}

