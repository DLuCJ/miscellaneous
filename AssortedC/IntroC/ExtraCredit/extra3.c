#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

/*This program finds the square root of a user inputted number
 *using the Newton-Raphson method. 
 *
 * Author: Daniel Lu
 * Date: 10/28/2013
 */

static const int lowBound = 0;

bool isError(char* end_ptr, double num);
double getUserInput();
double mySqrt(double num);

int main(void) {
  
  printf("Find the square root of: ");
  double number = getUserInput();
  printf("The square root of %f is : %f\n", number, mySqrt(number)); 
  
  return 0;
}

//Double check Notes and TBDs for error checking specs q
double mySqrt(double num) {

double getUserInput() {
  char userInput[100];
  char* end_ptr;
  scanf("%s", &userInput);
  double number = strtod(userInput, &end_ptr);
  if(isError(end_ptr, double number)){
    exit(1);
  } else {
    return number;
  }
}


bool isError(char* end_ptr, double num) {
  if(*end_ptr != 0 || num < lowBound) {
    printf("Error: invalid input\n");
    printf("Expecting a non-negative number\n");
    return true;
  }
  return false;
}
