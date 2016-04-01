#include "prog10.h"

/* Author: Daniel Lu
 * Date: 11/25/2013
 */

//traverses linked list of PERSONs and prints information 
void print_list(PERSON *person_ptr)
{ 
  while( person_ptr!= NULL) {
    printf("name : %s\nage: %i\n",person_ptr->name, person_ptr->age);
    person_ptr = person_ptr -> next_ptr;
  }
  
}
