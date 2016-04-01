#include "prog10.h"


int main (void)
{

    PERSON *head = NULL;
 
    
    head = createList();
    
    print_list(head);
    
    release_memory(head);

    printf("Done\n");
    return 0;
}
