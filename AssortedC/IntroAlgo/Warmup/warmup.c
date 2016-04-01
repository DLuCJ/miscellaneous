
/* This program prints five unique random numbers between 0 and 99
 * and prompts for a repeat of the process.
 *
 * Author: Daniel Lu
 * Date:   1/7/2014
 */

#include <stdio.h>
#include <stdlib.h>
#include "printNum.h" 

const int SIZE = 100;
const int COUNT = 5;

int main(void) {

  printf("\nWelcome to Daniel Lu's warmup program.\n");
  printf("It prints five unique random numbers between 0 and 99\n\n"); 
  //allocate space
  int *numbers = (int *) malloc(SIZE*sizeof(int));
  //populate once
  int i;
  for(i = 0; i < SIZE; i++) {
    numbers[i] = i;
  }

  char ch[5] ;
  while(1) {
    printNum(numbers,SIZE,COUNT);
    printf("\nAgain? <y/n>");
    scanf("%2s",&ch);
    if(*ch == 'n' || *ch == 'N') {
      break;
    }
  } 

  printf("\nDone\n");
  free(numbers);
  return 0;
}

