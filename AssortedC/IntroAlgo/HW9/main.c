/* Trie implementation.  User is allowed to perform the listed 
 * operations with strings of lowercase characters
 *
 * Author: Daniel Lu
 * Date:   3/14/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include <string.h>


int main() {
  
  printf("Hello\n");
  printf("Enter a command followed by a lowercase string to operate on Trie\n");
  printf("Valid commands are: insert str, delete str, search str.\n");
  printf("Enter list to print trie\n");
  printf("Enter term to get terminated and exit .\n");
  
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
	printf("Input must include only lowercase characters\n");
	continue;
      }
    }
    
    if(token1 == NULL) {
      printf("Error: invalid input. \n");
      continue;
    } else if(strcasecmp(token1,"list") == 0) {
      if(isEmpty(t)) {
	printf("Empty trie\n");
	continue;
      } else {
	printf("Strings in trie: ");
	list(t);
	printf("\n");
      }
    } else if(strcasecmp(token1, "term") == 0) {
      term(t,t->root);
      free(t);
      printf("\nYou've been terminated\n");
      break;
    } else if(strcasecmp(token1,"insert") == 0) {
      if(token2 == NULL) {
        printf("Error: No string listed\n");
        continue;
      }
      insert(t,t->root,val); 
      printf("Ok \n");
      
    }else if(strcasecmp(token1,"search") == 0) {
      if(token2 == NULL) {
	printf("Error: No string listed\n");
	continue;
      }
      if(find(t,val)) {
	printf("True\n");
      } else {
	bool printFalse = true;
	if(strlen(val) >= 2) {
	  char * prefix = val;
	  prefix[2] = 0;
	  if(preFind(t,prefix)) {
	    printFalse = false;

	    printf("True: ");
	    preList(t,prefix);
	    printf("\n");
	  } 
	} 
	if(printFalse) {
	  printf("False\n");
	}
      }
    } else if(strcasecmp(token1,"delete") == 0){
      if(token2 == NULL) {
	 printf("Error: No string listed\n");
       continue;
       }
      delNum(t,val);
      printf("Ok\n");
    } else{
      printf("Error: invalid input. %s is not recognized keyword: insert, search,list,delete\n", token1);
      continue;
    }
  }
  return 0;
}
