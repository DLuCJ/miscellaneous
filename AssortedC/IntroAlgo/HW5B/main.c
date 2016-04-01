
/* Closed hashing Hash table implementation.  User is allowed to perform the listed
 * operations with strings of lowercase alpha characters of length between 1 and 10
 *
 * Author: Daniel Lu
 * Date:   2/17/2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash.h"

int main() {

  printf("Hello\n");
  printf("Enter a command followed by a string of 1 - 10 lowercase characters to perform operation on hash table\n");
  printf("Valid commands are: insert <word>, delete <word>, search <word>, list.\n");
  printf("Enter term to print table and exit .\n");
  
  Hashtable * newTable = makeTable(26);
  char * regex = " \n";

  char str [100];
  while(1) {
    char * errMessage = NULL;
    printf("Enter: ");
    char * result = fgets(str, 100, stdin);
    char * token1 = strtok(result, regex);
    char * token2 = strtok(NULL, regex);
    if(token1 == NULL) {
      printf("Error: invalid input. \n");
      continue;
    } else if(strcasecmp(token1, "term") == 0) {
      hashListFull(newTable);
      term(newTable);
      printf("You've been terminated\n");
      break;
    }
    
    char * val = token2;
    if(overflow(val)){
      printf("Error: invalid input : %s\n", token2);
      printf("Error: Input should be between length 1 and 10 and contain only lowercase alpha characters \n");
	continue;
    }
    if(strcasecmp(token1,"insert") == 0) {
      if(hashInsert(val,newTable)) {
	printf("True \n");
      } else {
	printf("False \n");
      }
    }else if(strcasecmp(token1,"search") == 0) {
      if(search(val,newTable)) {
	printf("True\n");
      } else {
	printf("False\n");
      }
    }else if(strcasecmp(token1,"delete") == 0){
      if(hashDelete(val,newTable)) {
	printf("True \n");
      } else {
	printf("False\n");
      }
    }else if(strcasecmp(token1, "list") == 0) {
      hashListFull(newTable);
    }else{
      printf("Error: invalid input. %s is not recognized keyword: insert, search,list,delete\n", token1);
      continue;
    }
  }
  
  return 0;
}
