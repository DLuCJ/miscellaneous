#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* This program will calculate and output the nth prime 
 * number, as specified by the user, and use at least one function to do so. 
 *
 * Author: Daniel Lu
 * 10/27/2013
 */

//test for prime number function
bool testPrime(unsigned int number);
bool isError(char* ptr_end, long int n); 

int main(void) {
  char userInput[100]; 
  char* ptr_end;

  //user input and error checking
  printf("Hi, please enter in the nth prime number you want:");
  scanf("%s", &userInput);
  long int nthPrime = strtol(userInput, &ptr_end, 10);
  
  //mandatory user input of 1 or greater
  if(isError(ptr_end, nthPrime)) {
    exit(1);
  }

  unsigned int number = 2;
  int count = 0;

  //loop to find nth prime number, updates with count 
  do {
    if(testPrime(number)) {
      count++;
    }
    number++;
  }
  while (count < nthPrime);
  printf("The prime number you are looking for is %d\n", number - 1); 

  return 0;
}

//parameter: the number to be tested as prime
//output: true if prime, otherwise false
bool testPrime(unsigned int number) {
  unsigned int i;
  for(i = 2; i*i <= number; i++) {
    if(number % i == 0) {
      return false;
    }
  }
  return true;
}

bool isError(char* ptr_end, long int n) {
  if(*ptr_end != 0 || n <= 0) {
    printf("Error: invalid input\n");
    printf("Expecting a positive non-zero number\n");
    return true;
  }
  return false;
}
