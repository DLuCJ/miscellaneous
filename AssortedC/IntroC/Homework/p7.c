#include <stdio.h>
#include <stdlib.h>

/* This program sorts an array of Persons by age
 * and prints the information of said Persons in the
 * new order.
 * Sorting algorithm used is a quicksort
 *
 * Note: sort_by_age function only takes in Person array
 * Swap, partition and quickSort are helper functions 
 *
 * Author: Daniel Lu
 * Date: 11/9/2013
 */


const static int SIZE = 8;

//person structure
typedef struct person {
  char firstName[20];
  char lastName[20];
  int age;
} Person;

void print_person_info(Person person);
void quickSort(int l,int r, Person a[]);
int partition(int l, int r, Person a[]);
void swap(Person a[], int i, int j);
void sort_by_age(Person a[]);

int main(void) {
  int i;
  
  Person student[8] = {
    {"Bob", "Smith", 21},
    {"Jimmy", "John", 18},
    {"Amy", "Goldberg", 20},
    {"Dan", "Marlo", 17},
    {"Sally", "Sorrow", 16},
    {"Daniel", "Lu", 20},
    {"Ziyang", "Lu", 47},
    {"Mary", "Sue", 19}
  };
  
  for (i = 0; i < SIZE; i++) {
    print_person_info(student[i]);
  }
 
  sort_by_age(student); 
  
  printf("--- AFTER SORTING --------------\n");
  
  for( i = 0; i < SIZE; i++){
    print_person_info(student[i]);
    }
  return 0;
}

//Parameter: person structure
//prints information for one Person
void print_person_info(Person person){
  printf("Name = %s %s\n", person.firstName, person.lastName);
  printf("Age = %d\n",person.age);
}

//Parameter: Person array
//sort function, quicksorts
void sort_by_age(Person a[]) {
  quickSort(0, SIZE - 1, a);
}

//Parameter: left bound, right bound, Person array
//sorts each piece of the partition recursively
void quickSort(int l, int r, Person a[]) {
 
  if(l < r) {
  int pointer = partition(l,r,a);
  quickSort(l, pointer - 1, a); //sorts left piece of partitions
  quickSort(pointer + 1, r, a); //sorts right piece of partitions
  }
}

//parameters: left index, right index, Person array
//Scans from left to right for an item that should be on the right
//Scans from right to left for an item that should be on the left
//If found, swap
//Continue until pointers cross 
int partition(int l, int r, Person a[]) {

  int i = l-1;
  int j = r;
  
  while(1) {
    do{ ++i;
    } while(a[i].age < a[r].age); //find item on left to swap

    do{ --j;
    } while(a[j].age >  a[r].age); //find item on right to swap
   
    if(i >= j){ //check if pointers cross
      break;
    }
    
    swap(a,i,j); 
  }
  swap(a,i,r); // swap with partitioning item 
  return i; // return index of item now known to be in place
}    

//swaps Persons in given index positions
void swap( Person a[], int i, int j) {
  Person t = a[j];
  a[j] = a[i];
  a[i] = t;
}
