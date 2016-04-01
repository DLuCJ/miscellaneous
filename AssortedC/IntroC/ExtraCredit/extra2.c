#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* This program takes in a base 10 number from the user input 
 * and converts it to its base 2 equivalent.
 *
 * v2.0: Implemented usage of bitwise operations in convert function
 * Author: Daniel Lu
 * Date: 10/27/2013
 */

//function templates
long int getUserInput();
void convert(unsigned long long int number);
bool isError(char * end_ptr, unsigned long long int n);

int main(void) {
  printf("Hello, please input a base 10 number that you would like converted to base 2: ");
  unsigned long long int baseTen = getUserInput();
  printf("Number %llu converted to base 2 = ", baseTen);
  convert(baseTen);
  printf("\n");

  return 0;
}

//parameter: number given as user input
//recursive function that converts base 10 number to base 2 number 
//uses binary shift 
void convert(unsigned long long int number){
  long int remainder = (number & 1);
  if(( number >> 1)> 0) {
    convert(number >> 1);
  }
  printf("%d",remainder);
}

//parameter: none
//takes in user input
//returns user input as an integer
long int getUserInput(){
  char userInput[100];
  char* end_ptr;
  scanf("%s", &userInput);
  unsigned long long int baseTen = strtoull(userInput, &end_ptr, 10);
  // printf("debug: input = %llu, max = %llu\n",baseTen, ULLONG_MAX);
  if(isError(end_ptr, baseTen)){
    exit(1);
  } else {
    return baseTen;
  }
}
  
//parameter: takes in a pointer from strol function and the user input
//returns true if there is an error in user input
bool isError(char* end_ptr, unsigned long long int n){
  if(*end_ptr != 0 || n < 0 || n >= ULLONG_MAX) {
    printf("Error: invalid input\n");
    printf("Expecting a number between 0 and 18446744073709551615\n");
    return true;
  }
  return false;
}
 
