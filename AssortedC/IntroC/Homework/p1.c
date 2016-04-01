#include <stdio.h>

int main (void) {
  int a, b, c;
  a = 10;
  b = 20;
  c = a + b;
  
  /*I'm not sure if there is a difference between %d and %i, but I'm used to %dj*/
  printf("%d + %d = %d\n", a, b, c);
  printf("That was easy!\n");

  return 0;
}
