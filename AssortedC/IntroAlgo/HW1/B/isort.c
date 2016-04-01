
/*This file contains the sort and list functions
 *for the insertion sort.
 *
 * Author: Daniel Lu
 * Date:   1/14/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include "isort.h"

void insert (char *a, int size) {
  int j,i;
  char key;
  for(i = 0; i < size; i++) {
    key = a[i];
    j = i;
    while(j > 0 && a[j - 1] > key) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = key;
  }
}

void list (char * a, int size) {
  int i;
  printf("List: ");
  for(i = 0; i < size; ++i) {
    printf("%c ", a[i]);
  }
  printf("\n");
}

