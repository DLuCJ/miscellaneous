
/*This program implements a stack with
 *push, pop and list functionalities using
 *an array of 10 integers and provides calculator functionalities.
 *These include add, subtract, divide, and multiply
 *
 * Author: Daniel Lu
 * Date:   1/22/2014
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <stdbool.h>
#include "calculator.h"

int main() {

  printf("Hello, this program implements a stack.\n");
  printf("Enter #<integer> to push.\n");
  printf("Enter < . > to pop.\n");
  printf("Enter < + > < - > < / > < * > to \n");
  printf("add, subtract, divide, and multiply, respectively.\n");
  printf("The result will be at the top of the stack.\n");
  printf("Please enter 'list' to view stack contents and exit\n");
  
  Stack * stack = _make(10);
  
  char str [100];
  while(1) {
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
        printf("Error: stack full\n");
      }
    } else if(result[0] == '.') {
      if(pop(stack) == 1) {
        printf("Error:stack empty\n");
      }
    }else if(result[0] == 'l' || result[0] == 'L') {
      list(stack);
      //done and exit
      break;
    } else if (result[0] == '+') {
      if(add(stack) == 1) {
	printf("Error: not enough values for operation\n");
      }
    } else if(result[0] == '-') {
      if(subtract(stack) == 1) {
	printf("Error: not enough values for operation\n");
      }
    } else if(result[0] == '/') {
      if(divide(stack) == 1) {
	printf("Error: not enough values for operation\n");
      }
    } else if(result[0] == '*') {
      if(multiply(stack) == 1) {
	printf("Error: not enough values for operation\n");
      }
    }else {
      printf("Input not recognized, enter again\n");
    }
  }


  _del(stack);

  return 0;
}
