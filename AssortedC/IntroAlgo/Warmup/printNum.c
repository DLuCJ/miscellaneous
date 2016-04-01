

/* This program prints five unique random numbers between 0 and 99
 * and prompts for a repeat of the process.
 *
 * Author: Daniel Lu
 * Date:   1/7/2014
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void shuffle( int *nums, int size);

void printNum(int *nums, int size, int pickCount ) {
  int i;

  shuffle(nums, size);

  for(i = 0; i < pickCount; i++) {
    printf("%i ", nums[i]);
  }

}

void shuffle( int *nums, int size) {
  
  srand(time(NULL));
  int i,j;
  for (i = size - 1; i >= 1 ; i--) {
    j = rand() % i;
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
  } 
}
