#include <stdio.h>
#include <stdlib.h>

/*
 * This program simulates a convenience store purchase
 * of Oranges, Energy Drinks, and Yogurt
 *
 * Author: Daniel Lu
 * Date: 10/7/2013
*/


//price and tax constants
static float const orangePrice = 0.95;
static float const energyPrice = 1.5;
static float const yogurtPrice = 0.75;
static float const tax = .065;

int main(void){
  
  //variable declarations
  char lbsOranges[100], numberEnergy[100], numberYoYo[100];
  char* ptr_end;
  char* ptr_end1;
  char* ptr_end2;
  long int numEnergy, numYoYo;
  double lbOranges;
  float sumCost, sumTax, sumTotal, costOranges, costEnergy, costYoYo; 
  
  //Introduction and user input prompts
  //Prints error message after each prompt if invalid input
  printf("\nHi, welcome to Daniel Lu's store!\n\n");		
  printf("How many pounds of oranges do you have? : ");
  scanf("%s",&lbsOranges);

  lbOranges = strtod(lbsOranges, &ptr_end);
  if(*ptr_end != 0 ){
    printf("Error: invalid input\n");
    printf("Expecting a decimal number such as 2 or 1.75\n");
    exit(1);
  }

  printf("How many Energy Drinks do you have? : ");
  scanf("%s", &numberEnergy);
  numEnergy = strtol(numberEnergy, &ptr_end1  , 10);
  if(*ptr_end1 != 0) {
    printf("Error: invalid input\n");
    printf("Expecting a whole number\n");
    exit(1);
  }

  printf("How many Yogurts do you have? : ");
  scanf("%s", &numberYoYo);
  numYoYo = strtol(numberYoYo, &ptr_end2 , 10);
  if(*ptr_end2 != 0) {
    printf("Error: invalid input\n");
    printf("Expecting a whole number\n");
    exit(1);
  }

  // cost calculations
  costOranges = (lbOranges * orangePrice);
  costEnergy = (numEnergy * energyPrice);
  costYoYo = (numYoYo * yogurtPrice);
  sumCost = (costOranges + costEnergy + costYoYo);
  sumTax = tax * (costEnergy + costYoYo);
  sumTotal = sumTax + sumCost;
  
  //Results formatting
  printf("\nItem                Cost        Tax\n");
  printf("Oranges         %8.2f\n",costOranges);
  printf("Energy Drink    %8.2f    %8.2f\n",costEnergy,( tax * costEnergy));
  printf("Yogurt          %8.2f    %8.2f\n\n",costYoYo,(tax * costYoYo));
  printf("Totals          %8.2f    %8.2f\n\n",sumCost, sumTax);
  printf("Grand Total:         %8.2f\n\n", sumTotal);
  return 0;
}

  



