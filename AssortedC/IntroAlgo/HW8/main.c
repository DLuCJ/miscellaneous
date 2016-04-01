/* heap sort implementation.  User is allowed to perform the listed 
 * operations with integers between 0 and 999
 *
 * Author: Daniel Lu
 * Date:   3/3/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"
#include <string.h>


int main(int argc, char ** argv) {
  
  int size;
  char * regex = " \n";

  
  if(argc == 2) {
    FILE *fp;
    char * line = NULL;
    ssize_t read;
    size_t len = 0;
    
    fp = fopen(argv[1],"r");
    if(fp == NULL) {
      exit(EXIT_FAILURE);
    }

    while((read = getline(&line,&len,fp)) != -1) {
      char * token;
      int * nums;
      char * first = strtok(line, regex);
      if (!(strcasecmp(first, "term") == 0 || strcasecmp(first, "list") == 0)) {
	char * tokens[1000];
	tokens[0] = first;
	
	int i = 1;
	
	while((token = strtok(NULL,regex)) != NULL){
	  tokens[i++] = token;
	}
	size = i;
	
	nums = make(tokens,size);
	printf("done with nums\n");
      } else if (strcasecmp(first, "term") == 0) {
	printf("Sorted smallest to largest: \n");
	sort(nums,size);
	list(nums,size);
	term(nums);
	printf("\nYou've been terminated\n");
	break;
      } else if (strcasecmp(first,"list") == 0) {
	printf("Max-Heap:\n");
	buildHeap(nums,size);
	list(nums,size);
	printf("\n");
      }
    }
      
    free(line);
    exit(EXIT_SUCCESS);
  }else{
    size = argc - 1;
    char ** arg = argv + 1;   
    int * nums = make(arg,size);
    
    printf("Hello\n");
    printf("This is an implementation of heapsort.\n");
    printf("Enter list to print heap\n");
    printf("Enter term to print in sorted order and exit .\n");
    
    char str [100];
    while(1) {
      
      printf("Enter: ");
      char * result = fgets(str, 100, stdin);
      char * token1 = strtok(result, regex);
      
      if(token1 == NULL) {
	printf("Error: invalid input. \n");
	continue;
      } else if(strcasecmp(token1,"list") == 0) {
	printf("Max-Heap:\n");
	buildHeap(nums,size);
	list(nums,size);
      } else if(strcasecmp(token1, "term") == 0) {
	printf("Sorted smallest to largest: \n");
	sort(nums,size);
	list(nums,size);
	term(nums);
	printf("\nYou've been terminated\n");
	break;
      } else{
	printf("Error: invalid input. %s is not recognized keyword: list,term\n", token1);
	continue;
      }
    }
 } 
  return 0;
}
