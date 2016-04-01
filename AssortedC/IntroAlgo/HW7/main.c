/* Binary search tree implementation.  User is allowed to perform the listed 
 * operations with strings of lowercase characters between 1 - 10 characters
 *
 * Author: Daniel Lu
 * Date:   2/26/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include <string.h>


int main() {

  printf("Hello\n");
  printf("Enter a command followed by a lowercase string of length 1-10 characters to perform operation on BST\n");
  printf("Valid commands are: insert str, delete str, search str, successor str, predecessor str, max, min.\n");
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
    
    char * val = token2;
    if(token2 != NULL) {
      
      if(overflow(val)){
	printf("Error: invalid input: %s \n", token2);
	printf("Input must include only lowercase characters and be between 1 and 10 characters in length\n");
	continue;
      }
    }
    
    if(token1 == NULL) {
      printf("Error: invalid input. \n");
      continue;
    } else if(strcasecmp(token1,"max") == 0) {
      if(isEmpty(t)) {
        printf("Empty tree\n");
        continue;
      }else {
        printf("Max string is : %s \n", max(t->root)->data);
      }
    } else if(strcasecmp(token1,"min") == 0) {
      if(isEmpty(t)) {
        printf("Empty tree\n");
        continue;
      }else {
        printf("Max string is : %s \n", min(t->root)->data);
      }
    } else if(strcasecmp(token1,"successor") == 0) {
      if(token2 == NULL) {
	printf("Error: No number listed\n");
	continue;
      }
      Node * node = getSucc(t,val);
      if(node == NULL) {
	printf("False\n"); 
      } else {
	printf("Successor of %s is: %s\n",val, node->data);
      }
    } else if(strcasecmp(token1,"predecessor") == 0) {
      if(token2 == NULL) {
	printf("Error: No number listed\n");
	continue;
      }
      Node * node = getPred(t,val);
      if(node == NULL) {
        printf("False\n");
      } else {
        printf("predecessor of %s is: %s\n",val, node->data);
      }
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
      printf("Error: invalid input. %s is not recognized keyword: insert, search,list,delete, successor, predecessor\n", token1);
      continue;
    }
  }
  return 0;
}
