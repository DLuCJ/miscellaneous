
/*This program implements an insertion sort
 *that sorts user inputted single alpha characters
 *until 'z' is entered, then prints the sorted list.
 *
 * Author: Daniel Lu
 * Date:   1/14/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include "isort.h"
#include <string.h>

static const int SIZE = 1000;

int main() {
  char * array = malloc(SIZE);

  printf("Hello, this program implements an insertion sort.\n");
  printf("Please enter single alpha characters (case insensitive) to sort them.\n");
  printf("The sorted list will be printed when 'z' is entered.\n");

  char str [100];
  int index = 0;
  while(1) {
    printf("Enter: ");
    char * result = fgets(str, 100, stdin);
    char c = tolower(result[0]);
    if(c < 'a' || c > 'z') {
      printf("Error: only single alpha character input allowed.\n");
      continue;
    }
    if(strlen(result) != 2) {
      printf("Error: only single alpha character input allowed.\n");
      continue;
    }
    if(index == SIZE) {
      printf("Too many characters.  Only 1000 allowed.\n");
      break;
    }
    array[index] = c;
    index++;
    if(c == 'z') {
      insert(array, index );
      list(array, index);
      break;
    }
  }
  free(array);
  return 0;

}

