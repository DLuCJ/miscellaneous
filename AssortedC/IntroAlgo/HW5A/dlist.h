/* Linked list function definitions, including definitions for node and linked list 
 * structs.
 *
 * Author: Daniel Lu
 * Date:   2/17/2014
 */


#include <stdbool.h>

typedef struct _Node {
  int data;
  struct _Node * next;
  struct _Node * prev;
}Node;

typedef struct _Dlist {
  int id;
  Node * head;
}Dlist;

Dlist * make(int id);
void del(Dlist* d);
int find(Dlist *d, int item);
int delNum(Dlist *d, int item);
int insert(Dlist *d, int item);
void list(Dlist *d);
bool isEmpty(Dlist *d);
bool overflow(long long val);
