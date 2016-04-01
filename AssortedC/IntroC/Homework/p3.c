#include <stdio.h> 
#include <stdlib.h> 
/* This program calculates the payment information for a house mortgage 
 * given certain user input. 
 *
 * Author: Daniel Lu
 * 10/11/2013
 */

int main(void){
  //Variable initializations
  char loanDuration[100], loanAmount[100], interestRate[100], pay_per_month[100];
  char* ptr_end;
  char* ptr_end1;
  char* ptr_end2;
  char* ptr_end3;

  //user input and error checking
  printf("Hello, please input the required information when asked below\n");
  printf("How many years is your loan? :");
  scanf("%s", &loanDuration);
  long int loanTime = strtol(loanDuration, &ptr_end, 10);
  if(*ptr_end != 0 || loanTime <= 0) {
    printf("Error: invalid input\n");
    printf("Expecting a positive whole number\n");
    exit(1);
  }
  printf("Loan amount? :");
  scanf("%s", &loanAmount);  
  double loanTotal = strtod(loanAmount, &ptr_end1);
  if(*ptr_end1 != 0 || loanTotal < 0) {
    printf("Error: invalid input\n");
    printf("Expecting a non-negative decimal number\n");
    exit(1);
  }
  printf("Annual interest rate in percent? :");
  scanf("%s", &interestRate);
  double interestAnnual = (strtod(interestRate, &ptr_end2)/100);
  if(*ptr_end2 != 0 || interestAnnual < 0) {
    printf("Error: invalid input\n");
    printf("Expecting a non-negative decimal number like 5 or 5.0\n");
    exit(1);
  }
    
  printf("Monthly payment? :");
  scanf("%s", &pay_per_month);
  double monthPay = strtod(pay_per_month, &ptr_end3);
  if(*ptr_end3 != 0 || monthPay < 0) {
    printf("Error: invalid input\n");
    printf("Expecting a non-negative decimal number\n");
    exit(1);
  }
  
  printf("\nBelow is your loan information\n");

  //Loop for calculating monthly loan information
  int i;
  double interestTotal = 0;
  for (i = 0; i < (loanTime * 12); i++) {
    
    double interest =((interestAnnual/12) * loanTotal );
    interestTotal += interest;
    if((loanTotal - (monthPay - interest)) <= 0 ){
      break;
    }
    loanTotal -= (monthPay - interest);
    printf("Month(%d)  interest = %8.2f,  payment_left_over = %8.2f, balance = %8.2f\n",(i + 1),interest,(monthPay - interest), loanTotal);  
  }
  printf("\nTotal Interest =   %8.2f, Final Balance =  %8.2f\n", interestTotal, loanTotal);
}
