/* Binary search tree implementation.  User is allowed to perform the listed 
 * operations with integers between 0 and 999
 *
 * Author: Daniel Lu
 * Date:   2/20/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include <string.h>


int main() {

  printf("Hello\n");
  printf("Enter a command followed by a number between 0 and 999 inclusive to perform operation on hash table\n");
  printf("Valid commands are: insert #, delete #, search #.\n");
  printf("Enter list to print entire table\n");
  printf("Enter term to print table and exit .\n");
  
  Tree * t = make();
  char * regex = " \n";

  char str [100];
  while(1) {
  
    printf("Enter: ");
    char * result = fgets(str, 100, stdin);
    char * token1 = strtok(result, regex);
    char * token2 = strtok(NULL, regex);
    
    long long val;
    if(token2 != NULL) {
      char * end_ptr = 0;
      val = strtoll(token2,&end_ptr,10);
      if((end_ptr != 0 && *end_ptr != '\n' && *end_ptr != '\0') || overflow(val)){
	printf("Error: invalid input: %s \n", token2);
	printf("Input must be an integer in the range (0 - 999)\n");
	continue;
      }
    }
    
    if(token1 == NULL) {
      printf("Error: invalid input. \n");
      continue;
    } else if(strcasecmp(token1,"list") == 0) {
      if(isEmpty(t)) {
	printf("Empty tree\n");
	continue;
      }else {
	list(t,t->root);
	printf("\n");
      }
    } else if(strcasecmp(token1, "term") == 0) {
      if(isEmpty(t)) {
	printf("Empty tree\n");
      } else {
	list(t,t->root);
	term(t,t->root);
      }
      free(t);
      printf("\nYou've been terminated\n");
      break;
    } else if(strcasecmp(token1,"insert") == 0) {
      if(token2 == NULL) {
        printf("Error: No number listed\n");
        continue;
      }
      if(insert(t,t->root,val)) {
	printf("True \n");
      } else {
	printf("False \n");
      }
    }else if(strcasecmp(token1,"search") == 0) {
      if(token2 == NULL) {
        printf("Error: No number listed\n");
        continue;
      }
      if(find(t,val)) {
	printf("True\n");
      } else {
	printf("False\n");
      }
    } else if(strcasecmp(token1,"delete") == 0){
      if(token2 == NULL) {
	 printf("Error: No number listed\n");
       continue;
       }
       if(delNum(t,val)) {
	printf("True \n");
      } else {
	printf("False\n");
      }
    } else{
      printf("Error: invalid input. %s is not recognized keyword: insert, search,list,delete\n", token1);
      continue;
    }
  }
  return 0;
}
