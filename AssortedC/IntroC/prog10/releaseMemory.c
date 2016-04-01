#include "prog10.h"

void release_memory(PERSON *person_ptr)
{
    PERSON *tmp_next_ptr;
    
    while (person_ptr != NULL)
    {
        tmp_next_ptr = person_ptr->next_ptr;
        free(person_ptr);
        person_ptr = tmp_next_ptr;
    }
    puts("Memory Released");
}

