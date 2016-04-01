
/* Functions to terminate program and to merge two linked lists
 *
 * Author: Daniel Lu
 * Date:   2/6/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dlist.h"
#include <limits.h>

void term(Dlist *d1, Dlist *d2) {
  printf("List %s: ",d1->name);
  list(d1, tail(d1));
  printf("\n");
  printf("List %s: ",d2->name);
  list(d2, tail(d2));
  printf("\n");
  del(d1);
  del(d2);
  }

void merge(Dlist *d1, Dlist *d2) {
  Node * node = d2->head;
  while(node != NULL) {
    Node * next = node->next;
    insertNode(d1, node);
    node = next;
  }
  d2->head = NULL;
}
