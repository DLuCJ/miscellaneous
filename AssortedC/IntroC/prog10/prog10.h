#include <stdio.h>
#include <stdlib.h>


typedef struct person {
    char name[20];
    int age;
    struct person *next_ptr;
} PERSON;


PERSON* createList(void);
void    print_list(PERSON *head);
void    release_memory(PERSON *);

