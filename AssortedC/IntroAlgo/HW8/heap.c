/* heap sort functions, including heapify and building the heap
 *
 * Author: Daniel Lu
 * Date:   3/3/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"
#include <limits.h>

int * make(char ** arg, int size) {
  int i;

  int * nums = (int *) malloc(size * sizeof(int));
  for(i = 0; i < size; i++) {
    char * end_ptr = 0;
    long long val = strtoll(arg[i],&end_ptr,10);
    if((end_ptr != 0 && *end_ptr != '\n' && *end_ptr != '\0') || overflow(val))\
      {
	printf("Error: invalid input: %s \n", arg[i]);
	printf("Input must be an integer in the range (0 - 999)\n");
	exit(1);
      } else {
      nums[i] = val;
    }
  }
  return nums;
}

void sort(int * nums, int size) {
  int i;
  int heapsize = size;
  buildHeap(nums,size);
  for(i = size-1; i >= 1; i--) {
    swap(&nums[0],&nums[i]); 
    heapsize--;
    heapify(nums,0,heapsize);
  }
}

void buildHeap(int *nums, int size) {
  int heapsize = size;
  int i;
  for(i = size/2; i>=0; i--) {
    heapify(nums,i, heapsize); 
  }
}

void swap(int * a, int * b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int * nums, int i, int heapsize) {
  int left = 2 * i;
  int right=  2 * i + 1;
  int largest = -1;
  if(left < heapsize && nums[left] > nums[i]) {
    largest = left;
  } else {
    largest = i;
  }

  if(right < heapsize && nums[right] > nums[largest]) {
    largest = right;
  }
  if(largest != i) {
    swap(&nums[i],&nums[largest]);
    heapify(nums,largest,heapsize);
  }
}

void term(int * n) {
  free(n);
}

bool overflow(long long val) {
  bool overflow = val > 999 || val < 0;
  if(overflow) {
    printf("Error: integer overflow\n");
  }
  return overflow;
}

void list(int *n, int size) {
  int i;
  for(i = 0; i < size; i++) {
    printf("index: %i  | key: %i \n",i,n[i]);
  }
  printf("\n");
}


