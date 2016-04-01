
/* Function definitions for linked list functions, and definition for linked list struct
 * and node struct
 *
 * Author: Daniel Lu
 * Date:   2/6/2014
 */


#include <stdbool.h>

typedef struct _Node {
  int data;
  struct _Node * next;
  struct _Node * prev;
}Node;

typedef struct _Dlist {
  char * name;
  Node * head;
}Dlist;

Node * tail(Dlist *d);
Dlist * make(char * name);
void del(Dlist* d);
int find(Dlist *d, int item);
int delNum(Dlist *d, int item);
int insert(Dlist *d, int item);
void list(Dlist *d, Node* top);
int peek(Dlist *d);
bool isEmpty(Dlist *d);
bool overflow(long long val);
