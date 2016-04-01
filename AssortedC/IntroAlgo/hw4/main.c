
/*This program allows the user to perform operations on two doubly linked lists Eric and Stan. 
 *
 * Author: Daniel Lu
 * Date:   2/6/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dlist.h"
#include <string.h>
#include "util.h"

int main() {

  printf("Hello.\n");
  printf("Enter E(for Eric) or S(for Stan) followed by a command to perform operation on lists\n");
  printf("Valid commands are: insert #, delete #, find #, list, union.\n");
  printf("Enter term to print both lists and finish.\n");

  Dlist * Eric = make("Eric");
  Dlist * Stan = make("Stan");
  char * regex = " \n";

  char str [100];
  while(1) {
    Dlist * current = NULL;
    char * errMessage = NULL;
    printf("Enter: ");
    char * result = fgets(str, 100, stdin);
    char * token1 = strtok(result, regex);
    char * token2 = strtok(NULL, regex);
    char * token3 = strtok(NULL, regex);
    
    if(token1 == NULL) {
      printf("Error: invalid input. \n");
      continue;
    }
    
    if(strcasecmp(token1, "E") == 0) {
      current = Eric;
    } else if(strcasecmp(token1, "S") == 0) {
      current = Stan;
    }else if(strcasecmp(token1,"term")== 0) {
      term(Eric,Stan);
      printf("Terminated\n");
      break;
    }else{ 
      printf("Error: invalid input. %s is not recognized keyword: E,S,term \n", token1);
      continue;
    }
    if(current!= NULL) {
      if(token2 == NULL) {
	printf("Error: invalid input. \n");
	continue;
      }
      if(strcasecmp(token2, "list") == 0) {
	printf("List %s: ",current->name); 
	list(current,tail(current));
	printf("\n");
      } else if(strcasecmp(token2, "union") == 0) {
	merge(current,current == Stan ? Eric :Stan);
	printf("ok \n");
      }else {
	if(token3 == NULL) {
	  printf("Error: invalid input. \n");
	  continue;
	}
	char * end_ptr = 0;
   
	long long val = strtoll(token3,&end_ptr,10);
	if((end_ptr != 0 && *end_ptr != '\n' && *end_ptr != '\0') || overflow(val)){
	  printf("Error: invalid input. %s is not an integer\n", token3);
	  continue;
	}
	if(strcasecmp(token2,"insert") == 0) {
	  insert(current, val);
	}else if(strcasecmp(token2,"find") == 0) {
	  int position = find(current, val);
	  if (position == 0) {
	    printf("Failed, ok\n");
	  }else{
	    printf("Found in position %i, ok\n",position);
	  }
	}else if(strcasecmp(token2,"delete") == 0){
	  int position = delNum(current, val);
          if (position == 0) {
            printf("Failed, ok\n");
          }else{
            printf("Delete in position %i, ok\n",position);
          }
	}else{
	  printf("Error: invalid input. %s is not recognized keyword: insert, find,list,union, delete\n", token2);
	  continue;
	}
      }
    }
  }
  return 0;
}
