/* Chained LL Hash table implementation.  User is allowed to perform the listed 
 * operations with integers between 0 and 999
 *
 * Author: Daniel Lu
 * Date:   2/17/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dlist.h"
#include <string.h>
#include "hash.h"

int main() {

  printf("Hello\n");
  printf("Enter a command followed by a number between 0 and 999 inclusive to perform operation on hash table\n");
  printf("Valid commands are: insert #, delete #, search #, list #.\n");
  printf("Enter searchlist to print entire table\n");
  printf("Enter term to print table and exit .\n");
  
  Hashtable * newTable = makeTable(10);
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
	printf("Error: invalid input. %s is outside valid range (0 - 999)\n", token2);
	continue;
      }
    }

    if(token1 == NULL) {
      printf("Error: invalid input. \n");
      continue;
    } else if(strcasecmp(token1,"searchlist") == 0) {
      hashListFull(newTable);
    } else if(strcasecmp(token1, "term") == 0) {
      hashListFull(newTable);
      term(newTable);
      printf("You've been terminated\n");
      break;
    } else if(strcasecmp(token1,"insert") == 0) {
      if(token2 == NULL) {
        printf("Error: No number listed\n");
        continue;
      }
      if(hashInsert(val,newTable)) {
	printf("True \n");
      } else {
	printf("False \n");
      }
    }else if(strcasecmp(token1,"search") == 0) {
      if(token2 == NULL) {
        printf("Error: No number listed\n");
        continue;
      }
      if(search(val,newTable)) {
	printf("True\n");
      } else {
	printf("False\n");
      }
    }else if(strcasecmp(token1,"delete") == 0){
      if(token2 == NULL) {
        printf("Error: No number listed\n");
        continue;
      }
      if(hashDelete(val,newTable)) {
	printf("True \n");
      } else {
	printf("False\n");
      }
    }else if(strcasecmp(token1, "list") == 0) {
      if(token2 == NULL) {
	printf("Error: No index listed\n");
	continue;
      }  
      if(isNull(hash(val),newTable)) {
	printf("False\n");
      }else {
	printf("List #%i :", hash(val));
	hashList(hash(val),newTable);
	printf("\n");
      }  
    }else{
      printf("Error: invalid input. %s is not recognized keyword: insert, search,list,delete\n", token1);
      continue;
    }
  }
  
  return 0;
}
