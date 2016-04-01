#include <stdio.h> 
#include <stdlib.h> 
/* This program prints four sentences to a file named "my_file".
 * 
 * Author: Daniel Lu
 * Date: 11/21/2013
 */

int main(void) {

  FILE *f = fopen("my_file", "w");
  if (f == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  const char * str1 = "Four score and seven years ago our";
  const char * str2 = "fathers brought forth on this continent,";
  const char * str3 = "a new nation, conceived in Liberty and dedicated";
  const char * str4 = "to the proposition that all men are created equal.";

  fprintf(f, "%s\n%s\n%s\n%s\n", str1,str2,str3,str4);
  fclose(f);

  return 0;
}
