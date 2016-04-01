#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <stdbool.h>

/*This program implements a stack with 
 *push, pop and list functionalities using 
 *an array of 10 integers.
 *
 * Author: Daniel Lu
 * Date:   1/14/2014
 */

int main() {

  printf("Hello, this program implements a stack.\n");
  printf("Please enter #<integer> to push.\n");
  printf("Please enter < . > to pop.\n");
  printf("Please enter 'list' to view stack contents and exit\n");
  
  Stack * stack = _make(10);
  Stack * stack2 = _make(10);
  
  push(stack, 1);
  push(stack,2);
  push(stack,3);
  push(stack,4);
  push(stack,5);
  pop(stack);
  pop(stack2);
  push(stack2, 6);
  push(stack2,7);
  push(stack2,8);
  pop(stack2);
  list(stack);
  list(stack2);
  
  /* char str [100];
  while(1) {
    printf("Enter: ");
    char * result = fgets(str, 100, stdin);
    if(result[0] == '#') {
      char * end_ptr = 0;
      result++;
      long int val = strtol(result,&end_ptr,10);
      if(end_ptr != 0 && *end_ptr != '\n' && *end_ptr != '\0') {
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
    } else {
      printf("Input not recognized, enter again\n");
    }
  }
  */

  _del(stack2);  
  _del(stack);
  return 0;
}



