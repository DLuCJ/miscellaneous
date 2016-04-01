#include "prog10.h"


PERSON* createList()
{
    char    answer;
    PERSON *current, *previous, *head = NULL;
    
    while(1)
    {
        
        printf("Add a person to the List? [y/n] ");
        
        scanf("%c", &answer);
        if(answer == 'n')
            return head;
        
        current = (PERSON *)malloc(sizeof(PERSON) );
        
        printf("Enter a Name:");
        scanf("%s", current->name);
        printf("Enter persons age:");
        scanf("%i", &current->age);
        
        while(getchar() != '\n');
        
        if (head == NULL)
            head = current;
        else
            previous->next_ptr = current;
        
        current->next_ptr = NULL;
                
        previous = current;
    }
}

