#include <stdio.h>

int main(void) {
  
  int number[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; 
  int i;
  for(i = 1; i <= 20; i+=4) {
    printf("%i %i\n", *(number + i), number[i]);
  }

  return 0;
}
